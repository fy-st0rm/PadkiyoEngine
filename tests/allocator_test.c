#include "pe.h"

void trace_allocator_test() {
	Trace_Allocator* allocator = trace_allocator_new();

	char* buff = trace_allocator_alloc(allocator, 100);
	memcpy(buff, "hello world", 11);

	pe_assert(
		memcmp(buff, "hello world", 11) == 0,
		"[TEST FAILED]\n"
	);

	trace_allocator_free(allocator, buff);

	pe_assert(
		memcmp(buff, "hello world", 11) != 0,
		"[TEST FAILED]\n"
	);

	trace_allocator_delete(allocator);
	pe_log_sucess("%s: [TEST PASSED]\n", __FILE__);
}
