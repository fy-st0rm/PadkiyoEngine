#ifndef __MAT_H__
#define __MAT_H__

#include "core/includes.h"
#include "core/defines.h"
#include "vec.h"

typedef struct {
	f32 m[4][4];
} PE_Mat4;

void pe_print_mat4(PE_Mat4 m);
void pe_mat4_clear(PE_Mat4* m);
PE_Mat4 pe_mat4_mul(PE_Mat4 m1, PE_Mat4 m2);
PE_Vec3 pe_mat4_mul_vec3(PE_Mat4 m, PE_Vec3 v);
PE_Mat4 pe_mat4_identity();
PE_Mat4 pe_mat4_inverse(PE_Mat4 in);
PE_Mat4 pe_mat4_translate(PE_Mat4 m, PE_Vec3 v);
PE_Mat4 pe_mat4_transpose(PE_Mat4 m);
PE_Mat4 pe_ortho_projection(f32 left, f32 right, f32 top, f32 bottom, f32 near, f32 far);
PE_Mat4 pe_persp_projection(f32 aspect_ratio, f32 fov, f32 near, f32 far);

#endif // __MAT_H__
