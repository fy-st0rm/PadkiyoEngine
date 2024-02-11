#include "event.h"
#include "core/dyn_array.h"
#include "init.h"

extern PE_State* pe_state;

void key_callback(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods) {
	PE_Event event;
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

PE_Event pe_event_poll(PE_Window* window) {
	glfwSetKeyCallback(window->glfw_window, key_callback);
	if (dyn_array_len(pe_state->events))
		return dyn_array_pop(pe_state->events, 0);
	return (PE_Event) { .type = PE_NONE };
}
