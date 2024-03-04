#include "vec.h"

/*
 * @brief Vector print functions
 */

void pe_print_vec2(PE_Vec2 v) {
	printf("(%f, %f)\n", v.x, v.y);
}

void pe_print_vec3(PE_Vec3 v) {
	printf("(%f, %f, %f)\n", v.x, v.y, v.z);
}

void pe_print_vec4(PE_Vec4 v) {
	printf("(%f, %f, %f, %f)\n", v.x, v.y, v.z, v.w);
}

/*
 * @brief Vector compares
 */

b8 pe_vec2_eq(PE_Vec2 v1, PE_Vec2 v2) {
	return f32_eq(v1.x, v2.x) &&
         f32_eq(v1.y, v2.y);
}

b8 pe_vec3_eq(PE_Vec3 v1, PE_Vec3 v2) {
	return f32_eq(v1.x, v2.x) &&
         f32_eq(v1.y, v2.y) &&
         f32_eq(v1.z, v2.z);
}

b8 pe_vec4_eq(PE_Vec4 v1, PE_Vec4 v2) {
	return f32_eq(v1.x, v2.x) &&
         f32_eq(v1.y, v2.y) &&
         f32_eq(v1.z, v2.z) &&
         f32_eq(v1.w, v2.w);
}

/*
 * @brief Vector arithematics
 */

PE_Vec2 pe_vec2_add(PE_Vec2 v1, PE_Vec2 v2) {
	return (PE_Vec2) {
		.x = v1.x + v2.x,
		.y = v1.y + v2.y
	};
}

PE_Vec3 pe_vec3_add(PE_Vec3 v1, PE_Vec3 v2) {
	return (PE_Vec3) {
		.x = v1.x + v2.x,
		.y = v1.y + v2.y,
		.z = v1.z + v2.z
	};
}

PE_Vec4 pe_vec4_add(PE_Vec4 v1, PE_Vec4 v2) {
	return (PE_Vec4) {
		.x = v1.x + v2.x,
		.y = v1.y + v2.y,
		.z = v1.z + v2.z,
		.w = v1.w + v2.w
	};
}

PE_Vec2 pe_vec2_sub(PE_Vec2 v1, PE_Vec2 v2) {
	return (PE_Vec2) {
		.x = v1.x - v2.x,
		.y = v1.y - v2.y
	};
}

PE_Vec3 pe_vec3_sub(PE_Vec3 v1, PE_Vec3 v2) {
	return (PE_Vec3) {
		.x = v1.x - v2.x,
		.y = v1.y - v2.y,
		.z = v1.z - v2.z
	};
}

PE_Vec4 pe_vec4_sub(PE_Vec4 v1, PE_Vec4 v2) {
	return (PE_Vec4) {
		.x = v1.x - v2.x,
		.y = v1.y - v2.y,
		.z = v1.z - v2.z,
		.w = v1.w - v2.w
	};
}

PE_Vec2 pe_vec2_mul(PE_Vec2 v1, PE_Vec2 v2) {
	return (PE_Vec2) {
		.x = v1.x * v2.x,
		.y = v1.y * v2.y
	};
}

PE_Vec3 pe_vec3_mul(PE_Vec3 v1, PE_Vec3 v2) {
	return (PE_Vec3) {
		.x = v1.x * v2.x,
		.y = v1.y * v2.y,
		.z = v1.z * v2.z
	};
}

PE_Vec4 pe_vec4_mul(PE_Vec4 v1, PE_Vec4 v2) {
	return (PE_Vec4) {
		.x = v1.x * v2.x,
		.y = v1.y * v2.y,
		.z = v1.z * v2.z,
		.w = v1.w * v2.w
	};
}

PE_Vec2 pe_vec2_mul_scalar(PE_Vec2 v, f32 scalar) {
	return (PE_Vec2) {
		.x = v.x * scalar,
		.y = v.y * scalar
	};
}

PE_Vec3 pe_vec3_mul_scalar(PE_Vec3 v, f32 scalar) {
	return (PE_Vec3) {
		.x = v.x * scalar,
		.y = v.y * scalar,
		.z = v.z * scalar
	};
}

PE_Vec4 pe_vec4_mul_scalar(PE_Vec4 v, f32 scalar) {
	return (PE_Vec4) {
		.x = v.x * scalar,
		.y = v.y * scalar,
		.z = v.z * scalar,
		.w = v.w * scalar
	};
}

PE_Vec2 pe_vec2_div(PE_Vec2 v1, PE_Vec2 v2) {
	return (PE_Vec2) {
		.x = v1.x / v2.x,
		.y = v1.y / v2.y
	};
}

PE_Vec3 pe_vec3_div(PE_Vec3 v1, PE_Vec3 v2) {
	return (PE_Vec3) {
		.x = v1.x / v2.x,
		.y = v1.y / v2.y,
		.z = v1.z / v2.z
	};
}

PE_Vec4 pe_vec4_div(PE_Vec4 v1, PE_Vec4 v2) {
	return (PE_Vec4) {
		.x = v1.x / v2.x,
		.y = v1.y / v2.y,
		.z = v1.z / v2.z,
		.w = v1.w / v2.w
	};
}

f32 pe_vec2_mag(PE_Vec2 v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

f32 pe_vec3_mag(PE_Vec3 v) {
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

f32 pe_vec4_mag(PE_Vec4 v) {
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

PE_Vec2 pe_vec2_dir(PE_Vec2 v) {
	PE_Vec2 d = { 0, 0 };
	if (v.x < 0) d.x = -1;
	if (v.x > 0) d.x = 1;
	if (v.x == 0) d.x = 0;

	if (v.y < 0) d.y = -1;
	if (v.y > 0) d.y = 1;
	if (v.y == 0) d.y = 0;
	return d;
}

PE_Vec3 pe_vec3_dir(PE_Vec3 v) {
	PE_Vec3 d = { 0, 0 };
	if (v.x < 0) d.x = -1;
	if (v.x > 0) d.x = 1;
	if (v.x == 0) d.x = 0;

	if (v.y < 0) d.y = -1;
	if (v.y > 0) d.y = 1;
	if (v.y == 0) d.y = 0;

	if (v.z < 0) d.z = -1;
	if (v.z > 0) d.z = 1;
	if (v.z == 0) d.z = 0;
	return d;
}

PE_Vec2 pe_vec2_normalize(PE_Vec2 v) {
	f32 r = pe_vec2_mag(v);
	return (PE_Vec2) {
		.x = v.x / r,
		.y = v.y / r
	};
}

PE_Vec3 pe_vec3_normalize(PE_Vec3 v) {
	f32 r = pe_vec3_mag(v);
	return (PE_Vec3) {
		.x = v.x / r,
		.y = v.y / r,
		.z = v.z / r
	};
}
PE_Vec4 pe_vec4_normalize(PE_Vec4 v) {
	f32 r = pe_vec4_mag(v);
	return (PE_Vec4) {
		.x = v.x / r,
		.y = v.y / r,
		.z = v.z / r,
		.w = v.w / r
	};
}

PE_Vec2 pe_vec2_cross(PE_Vec2 v1, PE_Vec2 v2) {
	pe_assert(false, "pe_vec2_cross is not implemented yet.\n");
}

PE_Vec3 pe_vec3_cross(PE_Vec3 v1, PE_Vec3 v2) {
	return (PE_Vec3) {
		.x = v1.y * v2.z - v1.z * v2.y,
		.y = - (v1.x * v2.z - v1.z * v2.x),
		.z = v1.x * v2.y - v1.y * v2.x
	};
}

PE_Vec4 pe_vec4_cross(PE_Vec4 v1, PE_Vec4 v2) {
	pe_assert(false, "pe_vec3_cross is not implemented yet.\n");
}
