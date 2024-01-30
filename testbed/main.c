#include "pe.h"

int main() {
	Trace_Allocator* allocator = trace_allocator_new();

	char* a = (char*) trace_allocator_alloc(allocator, 100);
	strcpy(a, "Hello world\n");
	printf("%s", a);
	trace_allocator_free(allocator, a);

	trace_allocator_delete(allocator);
	return 0;
}
