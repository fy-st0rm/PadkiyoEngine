#include "result_test.c"
#include "allocator_test.c"
#include "dyn_array_test.c"

int main() {
	pe_assert(pe_init(), "Failed to initialize PE\n");
	result_test();
	trace_allocator_test();
	dyn_array_test();
	pe_quit();
	return 0;
}
