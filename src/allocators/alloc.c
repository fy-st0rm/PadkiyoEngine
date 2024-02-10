#include "alloc.h"
#include "trace_allocator.h"
#include "init.h"

extern PE_State* pe_state;

void* __pe_alloc(size_t size, const char* file, i32 line) {
	return __trace_allocator_alloc(pe_state->t_alloc, size, file, line);
}

void pe_free(void* ptr) {
	trace_allocator_free(pe_state->t_alloc, ptr);
}
