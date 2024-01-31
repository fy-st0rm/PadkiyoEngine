#ifndef __PE_WINDOW_H__
#define __PE_WINDOW_H__

#include "core/includes.h"
#include "core/result.h"
#include "core/defines.h"
#include "allocators/trace_allocator.h"
#include "math/vec.h"
#include "init.h"

typedef struct {
	GLFWwindow* glfw_window;
	u32 width, height;
	b8 should_close;
} PE_Window;

DECLARE_RESULT(Win_ptr, PE_Window*)

Result_Win_ptr pe_window_new(const char* title, u32 width, u32 height);
void pe_window_delete(PE_Window* window);
void pe_window_update(PE_Window* window);
void pe_window_clear_rgba(PE_Window* window, PE_Vec4 color);


#endif // __PE_WINDOW_H__
