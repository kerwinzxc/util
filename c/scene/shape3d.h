//
// Created by hujianzhe on 18-4-30.
//

#ifndef UTIL_C_SCENE_SHAPE3D_H
#define	UTIL_C_SCENE_SHAPE3D_H

#include "vector_math.h"

typedef enum shape3d_enum_t {
	SHAPE3D_MIN_ENUM_NUM = -1,
	SHAPE3D_LINESEGMENT,
	SHAPE3D_PLANE,
	SHAPE3D_AABB,
	SHAPE3D_SPHERE,
	SHAPE3D_CYLINDER,
	SHAPE3D_MAX_ENUM_NUM
} shape3d_enum_t;

typedef struct shape3d_linesegment_t {
	vector3_t vertices0;
	vector3_t vertices1;
} shape3d_linesegment_t;

typedef struct shape3d_plane_t {
	vector3_t pivot;
	vector3_t normal;
} shape3d_plane_t;

typedef struct shape3d_aabb_t {
	vector3_t pivot;
	vector3_t half;
} shape3d_aabb_t;

typedef struct shape3d_sphere_t {
	vector3_t pivot;
	double radius;
} shape3d_sphere_t;

typedef struct shape3d_cylinder_t {
	vector3_t pivot0;
	vector3_t pivot1;
	double radius;
} shape3d_cylinder_t;

typedef union shape3d_t {
	shape3d_linesegment_t linesegment;
	shape3d_plane_t plane;
	shape3d_aabb_t aabb;
	shape3d_sphere_t sphere;
	shape3d_cylinder_t cylinder;
} shape3d_t;

#ifdef	__cplusplus
extern "C" {
#endif

shape3d_plane_t* shape3d_plane_build_by_point(shape3d_plane_t* plane, const vector3_t* p1, const vector3_t* p2, const vector3_t* p3);

#ifdef	__cplusplus
}
#endif

#endif // !UTIL_C_SCENE_SHAPE3D_H
