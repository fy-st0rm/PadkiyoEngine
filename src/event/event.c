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

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	PE_Event event = {0};

	switch (button) {
		case GLFW_MOUSE_BUTTON_LEFT:
			event.button = PE_MOUSE_BUTTON_LEFT;
			break;
		case GLFW_MOUSE_BUTTON_RIGHT:
			event.button = PE_MOUSE_BUTTON_RIGHT;
			break;
		default:
			pe_assert(0, "Unhandled mouse button: %d\n", button);
	}

	switch (action) {
		case GLFW_PRESS:
			event.type = PE_MOUSE_BUTTON_DOWN;
			break;
		case GLFW_RELEASE:
			event.type = PE_MOUSE_BUTTON_UP;
			break;
		default:
			pe_assert(0, "Unhandled mouse action: %d\n", action);
	}

	dyn_array_append(pe_state->events, event);
}

PE_Event pe_event_poll(PE_Window* window) {
	glfwSetKeyCallback(window->glfw_window, key_callback);
	glfwSetMouseButtonCallback(window->glfw_window, mouse_button_callback);

	if (dyn_array_len(pe_state->events))
		return dyn_array_pop(pe_state->events, 0);
	return (PE_Event) { .type = PE_NONE };
}
