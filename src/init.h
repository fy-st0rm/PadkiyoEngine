#ifndef __INIT_H__
#define __INIT_H__

#include "core/includes.h"
#include "core/dyn_array.h"
#include "allocators/trace_allocator.h"
#include "event/event.h"

typedef struct {
	Trace_Allocator* t_alloc;
	Dyn_Array(PE_Event) events;
} PE_State;

bool pe_init();
void pe_quit();

#endif // __INIT_H__
