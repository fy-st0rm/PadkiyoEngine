#include "pe.h"

int main() {
	pe_assert(pe_init(), "Failed to initialize PE\n");

	PE_Window* window = Result_Win_ptr_unwrap(pe_window_new("Hello", 800, 600));

	while (!window->should_close) {
		pe_window_clear_rgba(window, (PE_Vec4) { .r = 0.5, .g = 0.5, .b = 0.5, .a = 1 });
		pe_window_update(window);
	}

	pe_window_delete(window);

	pe_quit();
	return 0;
}
