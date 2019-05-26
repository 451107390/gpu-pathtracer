#ifndef H_RAY_H
#define H_RAY_H

#include "common.h"

class Ray{
public:
	float3 o;
	float3 d;
	float tmin, tmax;

public:
	__host__ __device__ Ray()
		:o(make_float3(0,0,0)),
		 d(make_float3(0,0,0)),
		 tmin(0.001),
		 tmax(INFINITY){}

	__host__ __device__ Ray(float3& orig, float3& dir, float min = 0.001, float max = INFINITY)
		: o(orig),
		 d(dir),
		 tmin(min),
		 tmax(max){}

	__host__ __device__ float3 operator()(float t){
		return o + t*d;
	}
};

#endif