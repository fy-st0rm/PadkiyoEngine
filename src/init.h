#ifndef __INIT_H__
#define __INIT_H__

#include "core/includes.h"
#include "allocators/trace_allocator.h"

typedef struct {
	Trace_Allocator* t_alloc;
} PE_State;

bool pe_init();
void pe_quit();

#endif // __INIT_H__
