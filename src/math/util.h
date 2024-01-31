#ifndef __UTIL_H__
#define __UTIL_H__

#include "core/includes.h"
#include "core/defines.h"

#define ISO_PI 3.14159
#define iso_radians(x) x * ISO_PI / 180
#define iso_rand_range(l, u) rand() % (u - l + 1) + l

static b8 f32_eq(f32 a, f32 b) {
	return fabs(a - b) < 0.01f;
}

#endif // __UTIL_H__
