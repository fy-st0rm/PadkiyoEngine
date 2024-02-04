#include "window.h"

extern PE_State* pe_state;
DEFINE_RESULT(Win_ptr, PE_Window*);

Result_Win_ptr pe_window_new(const char* title, u32 width, u32 height) {
	PE_Window* window = trace_allocator_alloc(pe_state->t_alloc, sizeof(PE_Window));

	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	window->glfw_window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window->glfw_window)
		return Result_Win_ptr_err("Failed to create glfw window.");

	glfwMakeContextCurrent(window->glfw_window);

	if (glewInit() != GLEW_OK)
		return Result_Win_ptr_err("Failed to initialize glew.");

	window->should_close = glfwWindowShouldClose(window->glfw_window);

	return Result_Win_ptr_ok(window);
}

void pe_window_delete(PE_Window* window) {
	trace_allocator_free(pe_state->t_alloc, window);
}

void pe_window_update(PE_Window* window) {
	window->should_close = glfwWindowShouldClose(window->glfw_window);
	glfwSwapBuffers(window->glfw_window);
	glfwPollEvents();
}

void pe_window_clear_rgba(PE_Window* window, PE_Vec4 color) {
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT);
}
