#include "Global/Global.hpp"

float64 Deg2Rad(float64 &f64_Deg)
{
    return f64_Deg * M_PI / 180.0;
}

float32 Deg2Rad(float32 &f32_Deg)
{
    return f32_Deg * M_PI / 180.0f;
}

float64 Rad2Deg(float64 &f64_Rad)
{
    return f64_Rad * 180.0 / M_PI;
}

float32 Rad2Deg(float32 &f32_Rad)
{
    return f32_Rad * 180.0f / M_PI;
}
// ==================================== RAD<->DEG ==================================== //

// ==================================== Scale ==================================== //
float32 Scale2D(float32 &f32_X, float32 &f32_Y)
{
    return sqrt(pow(f32_X, 2) + pow(f32_Y, 2));
}

float32 Scale2D(float32 *arf_X, float32 *arf_Y, int32 s32_Idx)
{
    return sqrt(pow(arf_X[s32_Idx], 2) + pow(arf_Y[s32_Idx], 2));
}
float32 Scale2D(Point2D &st_Point2D)
{
    return sqrt(pow(st_Point2D.f32_X, 2) + pow(st_Point2D.f32_Y, 2));
}

float32 Scale3D(float32 &f32_X, float32 &f32_Y, float32 &f32_Z)
{
    return sqrt(pow(f32_X, 2) + pow(f32_Y, 2) + pow(f32_Z, 2));
}

float32 Scale3D(float32 *arf_X, float32 *arf_Y, float32 *arf_Z, int32 s32_Idx)
{
    return sqrt(pow(arf_X[s32_Idx], 2) + pow(arf_Y[s32_Idx], 2) + pow(arf_Z[s32_Idx], 2));
}

float32 Scale3D(Point3D &st_Point3D)
{
    return sqrt(pow(st_Point3D.f32_X, 2) + pow(st_Point3D.f32_Y, 2) + pow(st_Point3D.f32_Z, 2));
}
// ==================================== Scale ==================================== //


// ==================================== Normalize ==================================== //
float32 Normalize2D(float32 &f32_X1, float32 &f32_Y1, float32 &f32_X2, float32 &f32_Y2)
{
    return sqrt(pow(f32_X1 - f32_X2, 2) + pow(f32_Y1 - f32_Y2, 2));
}

float32 Normalize2D(float32 *arf_X, float32 *arf_Y, int32 &s32_Idx1, int32 &s32_Idx2)
{
    return sqrt(pow(arf_X[s32_Idx1] - arf_X[s32_Idx2], 2) + pow(arf_Y[s32_Idx1] - arf_Y[s32_Idx2], 2));
}

float32 Normalize2D(float32 *arf_X, float32 *arf_Y, int32 s32_Idx1, float32 &f32_X, float32 &f32_Y)
{
    return sqrt(pow(arf_X[s32_Idx1] - f32_X, 2) + pow(arf_Y[s32_Idx1] - f32_Y, 2));
}

float32 Normalize2D(float32 *arf_X, float32 *arf_Y, int32 s32_Idx1, Point2D &st_P2)
{
    return sqrt(pow(arf_X[s32_Idx1] - st_P2.f32_X, 2) + pow(arf_Y[s32_Idx1] - st_P2.f32_Y, 2));
}

float32 Normalize2D(Point2D &st_P1, Point2D &st_P2)
{
    return sqrt(pow(st_P1.f32_X - st_P2.f32_X, 2) + pow(st_P1.f32_Y - st_P2.f32_Y, 2));
}

float32 Normalize2D(std::vector<float32> &vf_P1, Point2D &st_P2)
{
    return sqrt(pow(vf_P1[0] - st_P2.f32_X, 2) + pow(vf_P1[1] - st_P2.f32_Y, 2));
}

float32 Normalize2D(std::vector<float32> &vf_P1, float32 &f32_X, float32 &f32_Y)
{
    return sqrt(pow(vf_P1[0] - f32_X, 2) + pow(vf_P1[1] - f32_Y, 2));
}

float32 Normalize3D(float32 &f32_X1, float32 &f32_Y1, float32 &f32_Z1, float32 &f32_X2, float32 &f32_Y2, float32 &f32_Z2)
{
    return sqrt(pow(f32_X1 - f32_X2, 2) + pow(f32_Y1 - f32_Y2, 2) + pow(f32_Z1 - f32_Z2, 2));
}

float32 Normalize3D(float32 *arf_X, float32 *arf_Y, float32 *arf_Z, int32 &s32_Idx1, int32 &s32_Idx2)
{
    return sqrt(pow(arf_X[s32_Idx1] - arf_X[s32_Idx2], 2) + pow(arf_Y[s32_Idx1] - arf_Y[s32_Idx2], 2) + pow(arf_Z[s32_Idx1] - arf_Z[s32_Idx2], 2));
}

float32 Normalize3D(Point3D &st_P1, Point3D &st_P2)
{
    return sqrt(pow(st_P1.f32_X - st_P2.f32_X, 2) + pow(st_P1.f32_Y - st_P2.f32_Y, 2) + pow(st_P1.f32_Z - st_P2.f32_Z, 2));
}
// ==================================== Normalize ==================================== //


// ==================================== Velocity ==================================== //
float32 KPH2MPS(float32 f32_KPH)
{
    return f32_KPH / 3.6;
}

float32 MPS2KPH(float32 f32_MPS)
{
    return f32_MPS * 3.6;
}
// ==================================== Velocity ==================================== //


// ==================================== Vector ==================================== //
Point2D UnitVector(Point2D &st_Point2DStart, Point2D &st_Point2DEnd)
{
    float32 f32_Scale = Normalize2D(st_Point2DStart, st_Point2DEnd);
    Point2D st_UnitVector = {(st_Point2DEnd.f32_X - st_Point2DStart.f32_X) / f32_Scale,
                               (st_Point2DEnd.f32_Y - st_Point2DStart.f32_Y) / f32_Scale};
    return st_UnitVector;
}
Point2D UnitVector(float32 f32_XStart, float32 f32_YStart, float32 f32_XEnd, float32 f32_YEnd)
{
    float32 f32_Scale = Normalize2D(f32_XStart, f32_YStart, f32_XEnd, f32_YEnd);
    Point2D st_UnitVector = {(f32_XEnd - f32_XStart) / f32_Scale,
                               (f32_YEnd - f32_YStart) / f32_Scale};
    return st_UnitVector;
}

float32 CrossProduct(Point2D &st_RefPoint, Point2D &st_Point)
{
    return st_RefPoint.f32_X * st_Point.f32_Y - st_RefPoint.f32_Y * st_Point.f32_X;
}
// ==================================== Vector ==================================== //


// ==================================== LoadData ==================================== //
void LoadData(std::ifstream &st_LoadFile, Path &st_Path)
{
    std::string s_FileLine = "";
    float32 f32_X = 0, f32_Y = 0;
    int32 s32_Size = 0;
    while (std::getline(st_LoadFile, s_FileLine))
    {
        std::istringstream st_Stream(s_FileLine);
        st_Stream >> f32_X >> f32_Y;
        st_Path.arf32_E[s32_Size] = f32_X;
        st_Path.arf32_N[s32_Size] = f32_Y;
        s32_Size++;
    }
    st_Path.s32_Size = s32_Size;
    st_LoadFile.close();
}

// void LoadData(std::ifstream &st_LoadFile, HighWayPath &st_Path)
// {
//     std::string s_FileLine = "";
//     float32 f32_X = 0, f32_Y = 0;
//     int32 s32_Size = 0;
//     while (std::getline(st_LoadFile, s_FileLine))
//     {
//         std::istringstream st_Stream(s_FileLine);
//         st_Stream >> f32_X >> f32_Y;
//         st_Path.arf32_E[s32_Size] = f32_X;
//         st_Path.arf32_N[s32_Size] = f32_Y;
//         s32_Size++;
//     }
//     st_Path.s32_Size = s32_Size;
//     st_LoadFile.close();
// }

void LoadData(std::ifstream &st_LoadFile, Map &st_Map)
{
    std::string s_FileLine = "";
    float32 f32_X = 0, f32_Y = 0;
    int32 s32_Size = 0;
    while (std::getline(st_LoadFile, s_FileLine))
    {
        std::istringstream st_Stream(s_FileLine);
        st_Stream >> f32_X >> f32_Y;
        st_Map.arf32_E[s32_Size] = f32_X;
        st_Map.arf32_N[s32_Size] = f32_Y;
        s32_Size++;
    }
    st_Map.s32_Size = s32_Size;
    st_LoadFile.close();
}
void LoadIdx(std::ifstream &st_LoadFile, IdxSet &st_IdxSet)
{
    std::string s_FileLine = "";
    int32 s32_Size = 0;
    int32 s32_Start = 0, s32_End = 0;
    while (std::getline(st_LoadFile, s_FileLine))
    {
        std::istringstream st_Stream(s_FileLine);
        st_Stream >> s32_Start >> s32_End;
        st_IdxSet.arp_Idx[s32_Size].first = s32_Start;
        st_IdxSet.arp_Idx[s32_Size].second = s32_End;
        s32_Size++;
    }
    st_IdxSet.s32_Num = s32_Size;
}
// ==================================== LoadData ==================================== //


// ==================================== RayCasting ==================================== //
bool InOrOut(Planning &st_Planning, float32 f32_PointX, float32 f32_PointY)
{
    int32 s32_MeetNum = 0;
    float32 f32_X, f32_NextX, f32_Y, f32_NextY, f32_Value;
    Map *st_Map[5] = {&st_Planning.st_InBoundary1,
                        &st_Planning.st_InBoundary2,
                        &st_Planning.st_InBoundary3,
                        &st_Planning.st_InBoundary4,
                        &st_Planning.st_OutBoundary};

    for (int32 s32_i = 0; s32_i < 5; s32_i++)
    {
        for (int32 s32_j = 0; s32_j < st_Map[s32_i]->s32_Size; s32_j++)
        {
            if (st_Map[s32_i]->s32_Size == 0)
                break;
            f32_X = st_Map[s32_i]->arf32_E[s32_j];
            f32_NextX = st_Map[s32_i]->arf32_E[(s32_j + 1) % st_Map[s32_i]->s32_Size];

            f32_Y = st_Map[s32_i]->arf32_N[s32_j];
            f32_NextY = st_Map[s32_i]->arf32_N[(s32_j + 1) % st_Map[s32_i]->s32_Size];

            if ((f32_Y >= f32_PointY && f32_NextY < f32_PointY) || (f32_Y < f32_PointY && f32_NextY >= f32_PointY))
            {
                f32_Value = (f32_NextX + (f32_PointY - f32_NextY) / (f32_Y - f32_NextY) * (f32_X - f32_NextX));
                if (f32_Value < f32_PointX)
                    s32_MeetNum += 1;
            }
        }
    }

    if (s32_MeetNum % 2 == 0)
        return false;
    else
        return true;
}
// ==================================== RayCasting ==================================== //


// ==================================== FindNear ==================================== //
int32 FindNear(Planning &st_Planning, float32 &f32_X, float32 &f32_Y, int32 s32_FindNearLen, int32 s32_PathType)
{
    int32 s32_NearIdx = 0;
    Path *st_Path = NULL;
    float32 arf_Dist[s32_FindNearLen] = {0};

    if (s32_PathType == c_GLOBALPATH)
    {
        st_Path = &st_Planning.st_GlobalPath;
        s32_NearIdx = st_Planning.st_GlobalPath.s32_NearIdx;
    }
    else if (s32_PathType == c_LOCALPATH)
        st_Path = &st_Planning.st_LocalPath;

    for (int32 s32_i = s32_NearIdx; s32_i < s32_NearIdx + s32_FindNearLen; s32_i++)
    {
        arf_Dist[s32_i - s32_NearIdx] = Normalize2D(st_Path->arf32_E, st_Path->arf32_N, s32_i % st_Path->s32_Size, f32_X, f32_Y);
    }

    return s32_NearIdx = (s32_NearIdx + std::distance(arf_Dist, std::min_element(arf_Dist, arf_Dist + s32_FindNearLen))) % st_Path->s32_Size;
}

int32 FindNear(Planning &st_Planning, Point2D &st_Point2D, int32 s32_StartIdx, int32 s32_FindNearLen, int32 s32_PathType)
{
    int32 s32_NearIdx = s32_StartIdx;
    Path *st_Path;
    float32 arf_Dist[s32_FindNearLen] = {0};
    if (s32_PathType == c_GLOBALPATH)
        st_Path = &st_Planning.st_GlobalPath;
    else if (s32_PathType == c_LOCALPATH)
        st_Path = &st_Planning.st_LocalPath;

    for (int32 s32_i = 0; s32_i < s32_FindNearLen; s32_i++)
    {
        arf_Dist[s32_i] = Normalize2D(st_Path->arf32_E, st_Path->arf32_N, (s32_i + s32_StartIdx) % st_Path->s32_Size, st_Point2D);
    }

    return s32_NearIdx = (s32_NearIdx + std::distance(arf_Dist, std::min_element(arf_Dist, arf_Dist + s32_FindNearLen))) % st_Path->s32_Size;
}
// ==================================== FindNear ==================================== //
