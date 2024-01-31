#include "init.h"

PE_State* pe_state;

bool pe_init() {
	if (!glfwInit()) return false;

	pe_state = (PE_State*) malloc(sizeof(PE_State));
	pe_state->t_alloc = trace_allocator_new();

	return true;
}

void pe_quit() {
	glfwTerminate();

	trace_allocator_delete(pe_state->t_alloc);
	free(pe_state);
}
