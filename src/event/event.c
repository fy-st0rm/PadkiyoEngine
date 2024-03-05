#include "event.h"
#include "core/dyn_array.h"
#include "init.h"

extern PE_State* pe_state;

void key_callback(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods) {
	PE_Event event = { 0 };
	event.key = key;
	switch (action) {
		case GLFW_PRESS:
		case GLFW_REPEAT:
			event.type = PE_KEYDOWN;
			break;
		case GLFW_RELEASE:
			event.type = PE_KEYUP;
			break;
	}

	dyn_array_append(pe_state->events, event);
}

void mouse_motion_callback(GLFWwindow* window, f64 mouse_x, f64 mouse_y) {
	PE_Event event = {
		.type = PE_MOUSE_MOTION,
		.mouse = (PE_Vec2) { mouse_x, mouse_y }
	};

	dyn_array_append(pe_state->events, event);
}

PE_Event pe_event_poll(PE_Window* window) {
	glfwSetKeyCallback(window->glfw_window, key_callback);
	glfwSetCursorPosCallback(window->glfw_window, mouse_motion_callback);

	if (dyn_array_len(pe_state->events))
		return dyn_array_pop(pe_state->events, 0);
	return (PE_Event) { .type = PE_NONE };
}
