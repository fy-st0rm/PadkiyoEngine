#ifndef __MATH_UTILS_H__
#define __MATH_UTILS_H__

#include "core/includes.h"
#include "core/defines.h"

#define PE_PI 3.14159
#define pe_to_radians(x) x * PE_PI / 180
#define pe_to_degrees(x) x * 180 / PE_PI
#define pe_rand_init(seed) srand(seed)
#define pe_rand_range(l, u) rand() % (u - l + 1) + l

static b8 f32_eq(f32 a, f32 b) {
	return fabs(a - b) < 0.01f;
}

#endif // __MATH_UTILS_H__
