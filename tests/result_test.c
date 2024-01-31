#include "pe.h"

DECLARE_RESULT(int32_t, int32_t)
DEFINE_RESULT(int32_t, int32_t)

Result_int32_t result_test_foo(int32_t n) {
	if (n % 2 == 0)
		return Result_int32_t_ok(200);
	return Result_int32_t_err("Not even");
}

void result_test() {
	pe_assert(
		Result_int32_t_unwrap(result_test_foo(10)) == 200,
		"[TEST FAILED]\n"
	);
	pe_assert(
		Result_int32_t_unwrap_or(result_test_foo(11), 69) == 69,
		"[TEST FAILED]\n"
	);
	pe_assert(
		strcmp(Result_int32_t_unwrap_err(result_test_foo(11)), "Not even") == 0,
		"[TEST FAILED]\n"
	);
	log_sucess("%s: [TEST PASSED]\n", __FILE__);
}
