#include "pe.h"

void dyn_array_test() {
	Dyn_Array(int) arr = NULL;

	for (int i = 0; i < 10; i++) {
		dyn_array_append(arr, i * i);
	}

	pe_assert(
		dyn_array_get(arr, 5) == 5 * 5,
		"[TEST FAILED]\n"
	);

	pe_assert(
		dyn_array_pop(arr, 5) == 5 * 5,
		"[TEST FAILED]\n"
	);

	pe_assert(
		dyn_array_len(arr) == 9,
		"[TEST FAILED]\n"
	);

	pe_assert(
		!dyn_array_exists(arr, 25),
		"[TEST FAILED]\n"
	);

	pe_assert(
		dyn_array_index_of(arr, 4) == 2,
		"[TEST FAILED]\n"
	);

	int great = dyn_array_get(arr, 0);
	dyn_array_for_each(arr, int x, {
		if (great < x) great = x;
	});

	pe_assert(
		great == 81,
		"[TEST FAILED]\n"
	);

	dyn_array_delete(arr);
	pe_log_sucess("%s: [TEST PASSED]\n", __FILE__);
}
