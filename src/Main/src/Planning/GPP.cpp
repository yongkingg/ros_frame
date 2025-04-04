#include <iostream>
#include <string>
#include <Global/Global.hpp>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <cfloat>
#include <cmath>

Map M_Line_1, M_Line_2, M_Line_3;
Map InBoundary, OutBoundary;
Map BestPath;
Frenet F_Line_2;

PointSet_1D<c_PATHSIZE> Gap_2_1, Gap_2_2, Gap_2_3, Gap_2_In, Gap_2_Out;
PointSet_1D<c_NODESIZE> distArr, prevArr;
PointSet_2D<c_PATHSIZE> tanv_1, tanv_2, tanv_3;
PointSet_2D<c_PATHSIZE> norv_1, norv_2, norv_3;
PointSet_2D<c_NODESIZE> points;
PointSet_2D<c_NODESIZE> adjCost, adjList;
Point2D curPos;

void get_Tan(Map& line, PointSet_2D<c_PATHSIZE>& tanv, PointSet_2D<c_PATHSIZE>& norv)
{
    for (int32 index = 0; index < line.s32_Size - 1; index++)
    {
        float32 dx = line.arf32_E[index +1] - line.arf32_E[index];
        float32 dy = line.arf32_N[index +1] - line.arf32_N[index];

        float32 norm = sqrt(dx * dx + dy * dy);

        tanv.arf32_Point[index][0] = dx / norm;
        tanv.arf32_Point[index][1] = dy / norm;

        norv.arf32_Point[index][0] = -dy / norm;
        norv.arf32_Point[index][1] = dx / norm;
    }
}

void get_S(Map& line, Frenet& frenet)
{
    frenet.arf32_S[0] = 0.0f;
    for (int32 index = 0; index < line.s32_Size - 1; index++)
    {
        float32 dx = line.arf32_E[index + 1] - line.arf32_E[index];
        float32 dy = line.arf32_N[index + 1] - line.arf32_N[index];
        frenet.arf32_S[index +1] = frenet.arf32_S[index] + sqrt(dx * dx + dy * dy);
    }
    frenet.s32_Size = line.s32_Size;
}

void EnuToFrenet(Map& line, Frenet& frenet, PointSet_2D<c_PATHSIZE>& tanv, PointSet_2D<c_PATHSIZE>& norv, Map& refBoundary)
{
    get_S(line, frenet); 
    get_Tan(line, tanv, norv);  

    for (int32 i = 0; i < line.s32_Size; i++)
    {
        float32 base_x = line.arf32_E[i];
        float32 base_y = line.arf32_N[i];

        float32 ref_x = refBoundary.arf32_E[i];
        float32 ref_y = refBoundary.arf32_N[i];

        float32 vec_x = ref_x - base_x;
        float32 vec_y = ref_y - base_y;

        float32 nor_x = norv.arf32_Point[i][0];
        float32 nor_y = norv.arf32_Point[i][1];

        frenet.arf32_D[i] = vec_x * nor_x + vec_y * nor_y;  
    }

    frenet.s32_Size = line.s32_Size;
}

void FrenetToEnu(Map& line, Map& Reline, Frenet frenet, PointSet_2D<c_PATHSIZE>& norv)
{
    for (int32 index = 0; index < line.s32_Size; index++)
    {
        Reline.arf32_E[index] = line.arf32_E[index] - norv.arf32_Point[index][0] * frenet.arf32_D[index];
        Reline.arf32_N[index] = line.arf32_N[index] - norv.arf32_Point[index][1] * frenet.arf32_D[index];
    }
}

void MakePoints(Map& line, PointSet_2D<c_PATHSIZE>& norv, Map& InBoundary, Map& OutBoundary, int32 margin, PointSet_2D<c_NODESIZE>& points)
{
    int32 totalSize = 0;
    for (int32 index = 0; index < line.s32_Size; index++)
    {
        float32 base_point[2] = { line.arf32_E[index], line.arf32_N[index] };

        float32 norm = sqrt(
            norv.arf32_Point[index][0] * norv.arf32_Point[index][0] + norv.arf32_Point[index][1] * norv.arf32_Point[index][1]
        );
        float32 normVector[2] = { norv.arf32_Point[index][0] / norm, norv.arf32_Point[index][1] / norm };

        float32 vecIn[2] = {
            InBoundary.arf32_E[index] - base_point[0],
            InBoundary.arf32_N[index] - base_point[1]
        };
        float32 vecOut[2] = {
            OutBoundary.arf32_E[index] - base_point[0],
            OutBoundary.arf32_N[index] - base_point[1]
        };

        float32 distIn = vecIn[0] * normVector[0] + vecIn[1] * normVector[1];
        float32 distOut = vecOut[0] * normVector[0] + vecOut[1] * normVector[1];

        if (distIn > distOut) {
            distIn = distIn - margin;
            distOut = distOut + margin;
        }
        else {
            distIn = distIn + margin;
            distOut = distOut - margin;
        }

        float32 step = fabs(distIn - distOut) / (c_SAMPLEPOINTSIZE - 1);
        float32 d = (distIn > distOut) ? distOut : distIn;

        for (int32 cnt = 0; cnt < c_SAMPLEPOINTSIZE; cnt++) {
            float32 x = base_point[0] + d * normVector[0];
            float32 y = base_point[1] + d * normVector[1];
            d += step;

            if (std::isnan(x) || std::isnan(y)) {
                points.s32_Size = totalSize;
                return;
            }

            int32 global_idx = index * c_SAMPLEPOINTSIZE + cnt;
            points.arf32_Point[global_idx][0] = x;
            points.arf32_Point[global_idx][1] = y;
            totalSize++;
        }
    }
    points.s32_Size = totalSize;    
}

void BuildGraph(PointSet_2D<c_NODESIZE>& points, 
                PointSet_2D<c_NODESIZE>& adjList, 
                PointSet_2D<c_NODESIZE>& adjCost)
{
    const int32 numLayers = c_PATHSIZE;              
    const int32 pointsPerLayer = c_SAMPLEPOINTSIZE;  
    const int32 totalNodes = points.s32_Size;

    for (int32 i = 0; i < totalNodes; i++) {
        for (int32 j = 0; j < c_SAMPLEPOINTSIZE; j++) {
            adjList.arf32_Point[i][j] = -1;
            adjCost.arf32_Point[i][j] = FLT_MAX;
        }
    }

    for (int32 index = 0; index < numLayers - 1; index++)
    {
        for (int32 k = 0; k < pointsPerLayer; k++)    
        {
            int32 v = index * pointsPerLayer + k;
            float32 vx = points.arf32_Point[v][0];
            float32 vy = points.arf32_Point[v][1];

            for (int32 m = 0; m < pointsPerLayer; m++) 
            {
                int32 w = (index + 1) * pointsPerLayer + m;
                float32 wx = points.arf32_Point[w][0];
                float32 wy = points.arf32_Point[w][1];

                float32 dx = wx - vx;
                float32 dy = wy - vy;
                float32 costVal = sqrt(dx * dx + dy * dy);

                int32 j = 0;
                while (j < c_SAMPLEPOINTSIZE && adjList.arf32_Point[v][j] != -1)
                    j++;

                if (j < c_SAMPLEPOINTSIZE) {
                    adjList.arf32_Point[v][j] = (float32)w;
                    adjCost.arf32_Point[v][j] = costVal;
                } 
            }
        }
    }
}

void Dijkstra(PointSet_2D<c_NODESIZE>& adjList, PointSet_2D<c_NODESIZE>& adjCost, PointSet_1D<c_NODESIZE>& distArr, PointSet_1D<c_NODESIZE>& prevArr, int32 startNode)
{
    const int32 nodeSize = c_NODESIZE;

    for (int32 i = 0; i < nodeSize; i++) {
        distArr.arf32_Point[i][0] = INFINITY; 
        prevArr.arf32_Point[i][0] = -1;        
    }
    distArr.arf32_Point[startNode][0] = 0.0f;

    bool visited[c_NODESIZE] = { false };

    for (int32 i = 0; i < nodeSize; i++) {
        int32 u = -1;
        float32 best = INFINITY;

        for (int32 v = 0; v < nodeSize; v++) {
            if (!visited[v] && distArr.arf32_Point[v][0] < best) {
                best = distArr.arf32_Point[v][0];
                u = v;
            }
        }
        if (u == -1) break;

        visited[u] = true;
        for (int32 j = 0; j < c_SAMPLEPOINTSIZE; j++) {
            int32 w = (int32)(adjList.arf32_Point[u][j]);
            if (adjList.arf32_Point[u][j] == -1) break;

            float32 cost = adjCost.arf32_Point[u][j];
            float32 alt = distArr.arf32_Point[u][0] + cost;

            if (alt < distArr.arf32_Point[w][0]) {
                distArr.arf32_Point[w][0] = alt;
                prevArr.arf32_Point[w][0] = (float32)u;
            }
        }
    }
}

std::pair<int32, int32> decodeNodeIndex(int32 nodeIndex)
{
    int32 layerIndex = nodeIndex / c_SAMPLEPOINTSIZE;
    int32 nodeInLayerIndex = nodeIndex % c_SAMPLEPOINTSIZE;
    return { layerIndex, nodeInLayerIndex };
}

void BacktrackPath(PointSet_1D<c_NODESIZE>& prevArr, int32 startNode, int32 endNode, int32* pathNodes, int32& pathLength)
{
    pathLength = 0;
    int32 cur = endNode;
    while (cur != startNode)
    {
        pathNodes[pathLength++] = cur;
        cur = static_cast<int32>(prevArr.arf32_Point[cur][0]);
    }

    pathNodes[pathLength++] = startNode;

    for (int32 i = 0; i < pathLength / 2; i++)
    {
        int32 tmp = pathNodes[i];
        pathNodes[i] = pathNodes[pathLength - i - 1];
        pathNodes[pathLength - i - 1] = tmp;
    }
}

void MakePath(Map& line, PointSet_2D<c_NODESIZE>& points, Map& BestPath,
    PointSet_1D<c_NODESIZE>& distArr, PointSet_1D<c_NODESIZE>& prevArr, int32 startNode)
{
    BuildGraph(points, adjList, adjCost);
    Dijkstra(adjList, adjCost, distArr, prevArr, startNode);

    int32 bestEnd = -1;
    float32 bestCost = INFINITY;
    int32 startOfLastLayer = (c_PATHSIZE - 1) * c_SAMPLEPOINTSIZE;
    for (int32 i = 0; i < c_SAMPLEPOINTSIZE; i++)
    {
        int32 nodeIdx = startOfLastLayer + i;
        float32 cost = distArr.arf32_Point[nodeIdx][0];

        if (cost < bestCost)
        {
            bestCost = cost;
            bestEnd = nodeIdx;
        }
    }


    int32 pathNodes[c_PATHSIZE];
    int32 pathLength = 0;
    BacktrackPath(prevArr, startNode, bestEnd, pathNodes, pathLength);
    BestPath.s32_Size = 0;
    for (int32 i = 0; i < pathLength; i++)
    {
        int32 nd = pathNodes[i];

        auto [layerIdx, candIdx] = decodeNodeIndex(nd);
        int32 pointIdx = layerIdx * c_SAMPLEPOINTSIZE + candIdx;
        BestPath.arf32_E[BestPath.s32_Size] = points.arf32_Point[pointIdx][0];
        BestPath.arf32_N[BestPath.s32_Size] = points.arf32_Point[pointIdx][1];
        BestPath.s32_Size++;
    }

    if (BestPath.s32_Size > 0) {
        float lastX = BestPath.arf32_E[BestPath.s32_Size - 1];
        float lastY = BestPath.arf32_N[BestPath.s32_Size - 1];

        if ((fabs(lastX) < 1e-4 && fabs(lastY) < 1e-4) || std::isnan(lastX) || std::isnan(lastY)) {
            BestPath.s32_Size--;
        }
    }
}

visualization_msgs::Marker createLineMarker(const Map& line, const std::string& ns, int id, float r, float g, float b)
{
    visualization_msgs::Marker marker;
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();
    marker.ns = ns;
    marker.id = id;
    marker.type = visualization_msgs::Marker::LINE_STRIP;
    marker.action = visualization_msgs::Marker::ADD;
    marker.scale.x = 0.2;
    marker.color.r = r;
    marker.color.g = g;
    marker.color.b = b;
    marker.color.a = 1.0;

    for (int i = 0; i < line.s32_Size; i++) {
        geometry_msgs::Point p;
        p.x = line.arf32_E[i];
        p.y = line.arf32_N[i];
        p.z = 0;
        marker.points.push_back(p);
    }

    return marker;
}

visualization_msgs::Marker createPointCloudMarker(const PointSet_2D<c_NODESIZE>& points, const std::string& ns, int id, float r, float g, float b)
{
    visualization_msgs::Marker marker;
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();
    marker.ns = ns;
    marker.id = id;
    marker.type = visualization_msgs::Marker::POINTS;
    marker.action = visualization_msgs::Marker::ADD;
    marker.scale.x = 0.1;
    marker.scale.y = 0.1;
    marker.color.r = r;
    marker.color.g = g;
    marker.color.b = b;
    marker.color.a = 1.0;

    for (int i = 0; i < points.s32_Size; i++) {
        geometry_msgs::Point p;
        p.x = points.arf32_Point[i][0];
        p.y = points.arf32_Point[i][1];
        p.z = 0;
        marker.points.push_back(p);
    }

    return marker;
}


void initMapData()
{
    curPos.f32_X = 0;
    curPos.f32_Y = 0;
    // ============ Gap init ============ // 
    string gapDirectory = getCurrentDirectory() + "/src/Map/Kiapi/Gap";
    std::ifstream fileGap21(gapDirectory + "/Gap_2_1.txt");
    std::ifstream fileGap22(gapDirectory + "/Gap_2_2.txt");
    std::ifstream fileGap23(gapDirectory + "/Gap_2_3.txt");
    std::ifstream fileGapIn(gapDirectory + "/Gap_2_In.txt");
    std::ifstream fileGapOut(gapDirectory + "/Gap_2_Out.txt");
    
    Load1DPoint(fileGap21, Gap_2_1);
    Load1DPoint(fileGap22, Gap_2_2);
    Load1DPoint(fileGap23, Gap_2_3);
    Load1DPoint(fileGapIn, Gap_2_In);
    Load1DPoint(fileGapOut, Gap_2_Out);

    fileGap21.close();
    fileGap22.close();
    fileGap23.close();
    fileGapIn.close();
    fileGapOut.close();
    // ============ Gap init ============ // 

    // ============ Line init ============ // 
    string mapDirectory = getCurrentDirectory() + "/src/Map/Kiapi/Path";
    std::ifstream fileLine1(mapDirectory + "/Line1.txt");
    std::ifstream fileLine2(mapDirectory + "/Line2.txt");
    std::ifstream fileLine3(mapDirectory + "/Line3.txt");

    LoadData(fileLine1, M_Line_1);    
    LoadData(fileLine2, M_Line_2);
    LoadData(fileLine3, M_Line_3);

    fileLine1.close();
    fileLine2.close();
    fileLine3.close();
    // ============ Line init ============ // 

    // ============ Boundary init ============ // 
    string boundaryDirectory = getCurrentDirectory() + "/src/Map/Kiapi/Boundary";
    std::ifstream fileOut(boundaryDirectory + "/Boundary1.txt");
    std::ifstream fileIn(boundaryDirectory + "/Boundary4.txt");

    LoadData(fileIn, InBoundary);
    LoadData(fileOut, OutBoundary);

    fileIn.close();
    fileOut.close();
    EnuToFrenet(M_Line_2, F_Line_2, tanv_2, norv_2, InBoundary);
}


void MakeShortestPath()
{
    MakePoints(M_Line_2, norv_2, InBoundary, OutBoundary, 1.5, points);
    float startNode = FindNear(points, curPos);
    MakePath(M_Line_2, points, BestPath, distArr, prevArr, startNode);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "path_visualizer");
    ros::NodeHandle nh;
    ros::Publisher marker_pub = nh.advertise<visualization_msgs::MarkerArray>("visualization_marker_array", 10);

    initMapData();  
    MakeShortestPath(); 
    ros::Rate rate(1.0);  

    while (ros::ok())
    {
        visualization_msgs::MarkerArray markerArray;

        markerArray.markers.push_back(createLineMarker(M_Line_1, "Line", 0, 1.0, 1.0, 1.0)); // Red
        markerArray.markers.push_back(createLineMarker(M_Line_2, "Line", 1, 1.0, 1.0, 1.0)); // Green
        markerArray.markers.push_back(createLineMarker(M_Line_3, "Line", 2, 1.0, 1.0, 1.0)); // Blue
        markerArray.markers.push_back(createLineMarker(InBoundary, "Boundary", 3, 1.0, 1.0, 1.0)); // Yellow
        markerArray.markers.push_back(createLineMarker(OutBoundary, "Boundary", 4, 1.0, 1.0, 1.0)); // Magenta

        markerArray.markers.push_back(createPointCloudMarker(points, "Points", 5, 0.5, 1.0, 1.0)); // Cyan dots

        markerArray.markers.push_back(createLineMarker(BestPath, "BestPath", 6, 0.0, 1.0, 0.0)); 

        marker_pub.publish(markerArray);
        ros::spinOnce();
        rate.sleep();
    }


    return 0;
}
