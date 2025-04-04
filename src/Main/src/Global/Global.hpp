#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <ros/ros.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <yaml-cpp/yaml.h>

using namespace std;

// ========================= Type ========================= // 
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef short int16;
typedef int int32;
typedef float float32;
typedef double float64;

const double PI = 3.141592653589793;
// ========================= Size ========================= // 
const int32 c_PATHSIZE = 0;
const int32 c_MAPSIZE = 0;
const int32 c_MISSIONSIZE = 0;

// ========================= Path ========================= // 
const int32 c_GLOBALPATH = 0;
const int32 c_LOCALPATH = 1;

struct Point2D
{
	float32 f32_X;
	float32 f32_Y;
};

struct Point3D
{
	float32 f32_X;
	float32 f32_Y;
	float32 f32_Z;
};

struct GPSIMU
{
	float32 f32_E;
	float32 f32_N;
	float32 f32_Heading_rad;
	float32 f32_Heading_deg;
	float32 f32_Vel;
	bool b_Jamming;
};

struct Path
{
    float32 arf32_E[c_PATHSIZE];
    float32 arf32_N[c_PATHSIZE];
    int32 s32_NearIdx;
    int32 s32_Size;
};

struct Map
{
	float32 arf32_E[c_MAPSIZE];
	float32 arf32_N[c_MAPSIZE];
	int32 s32_Size;
};

struct IdxSet
{
    std::pair<int32, int32> arp_Idx[c_MISSIONSIZE];
    int32 s32_SelectNumber;
    int32 s32_Num;
};

struct Planning
{
    Path st_GlobalPath;
    Path st_LocalPath;

    // HighWayPath st_HighWayPath[3];

    Map st_InBoundary1;
    Map st_InBoundary2;
    Map st_InBoundary3;
    Map st_InBoundary4;
    Map st_OutBoundary;

    // Avoid st_AvoidSmall;
    // Avoid st_AvoidCircle;
    // Avoid st_AvoidTunnel;

    IdxSet st_Mission;
    IdxSet st_Traffic;
    IdxSet st_Corner;

    // int32 ars32_TrafficStopIdx[5] = {1220, 3495, 6480, 8215, 9990};
    int32 s32_PathType = c_GLOBALPATH;
    float32 f32_TargetVelocity;
    float32 f32_HighWayMaxVel = 30;
    bool b_StopSig = false;
    int32 s32_SlowSig = 0;
    int32 s32_AEBMode = 0;
};

struct PurePursuit
{
	float32 f32_LD;
	float32 f32_Alpha;
	int32 s32_WayIdx;
};

struct PID
{
	float32 f32_KP;
	float32 f32_KI;
	float32 f32_KD;

	float32 f32_P_Error;
	float32 f32_I_Error;
	float32 f32_D_Error;

	float32 f32_Input_P;
	float32 f32_Input_I;
	float32 f32_Input_D;
};

struct Control
{
	PurePursuit st_PurePursuit;
	PID st_PID;

	float32 f32_DefaultVel_KPH;
	float32 f32_TargetVel_KPH;
	float32 f32_MissionVel_KPH[c_MISSIONSIZE];

	float32 f32_TargetSteer_Rad;
};


// ==================================== RAD<->DEG ==================================== //
float64 Deg2Rad(float64 &f64_Deg);
float32 Deg2Rad(float32 &f32_Deg);
float64 Rad2Deg(float64 &f64_Rad);
float32 Rad2Deg(float32 &f32_Rad);
// ==================================== RAD<->DEG ==================================== //


// ==================================== Scale ==================================== //
float32 Scale2D(float32 &f32_X, float32 &f32_Y);
float32 Scale2D(float32 *arf_X, float32 *arf_Y, int32 s32_Idx);
float32 Scale2D(Point2D &st_Point2D);

float32 Scale3D(float32 &f32_X, float32 &f32_Y, float32 &f32_Z);
float32 Scale3D(float32 *arf_X, float32 *arf_Y, float32 *arf_Z, int32 s32_Idx);
float32 Scale3D(Point3D &st_Point3D);
// ==================================== Scale ==================================== //


// ==================================== Normalize ==================================== //
float32 Normalize2D(float32 &f32_X1, float32 &f32_Y1, float32 &f32_X2, float32 &f32_Y2);
float32 Normalize2D(float32 *arf_X, float32 *arf_Y, int32 &s32_Idx1, int32 &s32_Idx2);
float32 Normalize2D(float32 *arf_X, float32 *arf_Y, int32 s32_Idx1, float32 &f32_X, float32 &f32_Y);
float32 Normalize2D(float32 *arf_X, float32 *arf_Y, int32 s32_Idx1, Point2D &st_P2);
float32 Normalize2D(Point2D &st_P1, Point2D &st_P2);
float32 Normalize2D(std::vector<float32> &vf_P1, Point2D &st_P2);
float32 Normalize2D(std::vector<float32> &vf_P1, float32 &f32_X, float32 &f32_Y);

float32 Normalize3D(float32 &f32_X1, float32 &f32_Y1, float32 &f32_Z1, float32 &f32_X2, float32 &f32_Y2, float32 &f32_Z2);
float32 Normalize3D(float32 *arf_X, float32 *arf_Y, float32 *arf_Z, int32 &s32_Idx1, int32 &s32_Idx2);
float32 Normalize3D(Point3D &st_P1, Point3D &st_P2);
// ==================================== Normalize ==================================== //


// ==================================== Velocity ==================================== //
float32 KPH2MPS(float32 f32_KPH);
float32 MPS2KPH(float32 f32_MPS);
// ==================================== Velocity ==================================== //


// ==================================== Vector ==================================== //
Point2D UnitVector(Point2D &st_Point2DStart, Point2D &st_Point2DEnd);
Point2D UnitVector(float32 f32_XStart, float32 f32_YStart, float32 f32_XEnd, float32 f32_YEnd);
float32 CrossProduct(Point2D &st_RefPoint, Point2D &st_Point);
// ==================================== Vector ==================================== //


// ==================================== LoadData ==================================== //
void LoadData(std::ifstream &st_LoadFile, Path &st_Path);
// void LoadData(std::ifstream &st_LoadFile, HighWayPath &st_Path);
void LoadData(std::ifstream &st_LoadFile, Map &st_Map);
void LoadIdx(std::ifstream &st_LoadFile, IdxSet &st_IdxSet);
// ==================================== LoadData ==================================== //


// ==================================== RayCasting ==================================== //
bool InOrOut(Planning &st_Planning, float32 f32_PointX, float32 f32_PointY);
// ==================================== RayCasting ==================================== //


#endif