#ifndef __ALLOC_H__
#define __ALLOC_H__

#include "core/defines.h"
#include "core/includes.h"

#define pe_alloc(size) __pe_alloc(size, __FILE__, __LINE__)
void* __pe_alloc(size_t size, const char* file, i32 line);
void pe_free(void* ptr);

#endif // __ALLOC_H__
