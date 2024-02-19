#ifndef __VEC_H__
#define __VEC_H__

#include "core/includes.h"
#include "core/defines.h"
#include "core/log.h"
#include "utils.h"

/*
 * @brief Vector definitions
 */

typedef struct {
	f32 x, y;
} PE_Vec2;

typedef struct {
	f32 x, y, z;
} PE_Vec3;

typedef struct {
	union { f32 x, r; };
	union { f32 y, g; };
	union { f32 z, b; };
	union { f32 w, a; };
} PE_Vec4;

/*
 * @brief Vector print functions
 */

void pe_print_vec2(PE_Vec2 v);
void pe_print_vec3(PE_Vec3 v);
void pe_print_vec4(PE_Vec4 v);

/*
 * @brief Vector compares
 */

b8 pe_vec2_eq(PE_Vec2 v1, PE_Vec2 v2);
b8 pe_vec3_eq(PE_Vec3 v1, PE_Vec3 v2);
b8 pe_vec4_eq(PE_Vec4 v1, PE_Vec4 v2);

/*
 * @brief Vector arithematics
 */

PE_Vec2 pe_vec2_add(PE_Vec2 v1, PE_Vec2 v2);
PE_Vec3 pe_vec3_add(PE_Vec3 v1, PE_Vec3 v2);
PE_Vec4 pe_vec4_add(PE_Vec4 v1, PE_Vec4 v2);

PE_Vec2 pe_vec2_sub(PE_Vec2 v1, PE_Vec2 v2);
PE_Vec3 pe_vec3_sub(PE_Vec3 v1, PE_Vec3 v2);
PE_Vec4 pe_vec4_sub(PE_Vec4 v1, PE_Vec4 v2);

PE_Vec2 pe_vec2_mul(PE_Vec2 v1, PE_Vec2 v2);
PE_Vec3 pe_vec3_mul(PE_Vec3 v1, PE_Vec3 v2);
PE_Vec4 pe_vec4_mul(PE_Vec4 v1, PE_Vec4 v2);

PE_Vec2 pe_vec2_mul_scalar(PE_Vec2 v, f32 scalar);
PE_Vec3 pe_vec3_mul_scalar(PE_Vec3 v, f32 scalar);
PE_Vec4 pe_vec4_mul_scalar(PE_Vec4 v, f32 scalar);

PE_Vec2 pe_vec2_div(PE_Vec2 v1, PE_Vec2 v2);
PE_Vec3 pe_vec3_div(PE_Vec3 v1, PE_Vec3 v2);
PE_Vec4 pe_vec4_div(PE_Vec4 v1, PE_Vec4 v2);

f32 pe_vec2_mag(PE_Vec2 v);
f32 pe_vec3_mag(PE_Vec3 v);
f32 pe_vec4_mag(PE_Vec4 v);

PE_Vec2 pe_vec2_normalize(PE_Vec2 v);
PE_Vec3 pe_vec3_normalize(PE_Vec3 v);
PE_Vec4 pe_vec4_normalize(PE_Vec4 v);

PE_Vec2 pe_vec2_cross(PE_Vec2 v1, PE_Vec2 v2);
PE_Vec3 pe_vec3_cross(PE_Vec3 v1, PE_Vec3 v2);
PE_Vec4 pe_vec4_cross(PE_Vec4 v1, PE_Vec4 v2);

#endif // __VEC_H__
