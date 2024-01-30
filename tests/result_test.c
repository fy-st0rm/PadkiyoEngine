#include "pe.h"

DEFINE_RESULT(int32_t, int32_t, int32_t)

Result_int32_t result_test_foo(int32_t n) {
	if (n % 2 == 0)
		return Result_int32_t_ok(200);
	return Result_int32_t_err(500);
}

void result_test() {
	assert(
		Result_int32_t_unwrap(result_test_foo(10)) == 200,
		"[TEST FAILED]\n"
	);
	assert(
		Result_int32_t_unwrap_or(result_test_foo(11), 69) == 69,
		"[TEST FAILED]\n"
	);
	assert(
		Result_int32_t_unwrap_err(result_test_foo(11)) == 500,
		"[TEST FAILED]\n"
	);
	log_sucess("%s: [TEST PASSED]\n", __FILE__);
}
