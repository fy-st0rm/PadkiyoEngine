#ifndef __EVENT_H__
#define __EVENT_H__

#include "core/includes.h"
#include "core/defines.h"
#include "core/log.h"
#include "window/window.h"
#include "key_defines.h"
#include "math/vec.h"

typedef enum {
	PE_NONE,

	PE_KEYDOWN,
	PE_KEYUP,

	PE_MOUSE_BUTTON_DOWN,
	PE_MOUSE_BUTTON_UP,
} PE_Event_Type;

typedef enum {
	PE_MOUSE_BUTTON_LEFT,
	PE_MOUSE_BUTTON_RIGHT
} PE_Mouse_Button;

typedef struct {
	PE_Event_Type type;
	u32 key;
	PE_Mouse_Button button;
} PE_Event;

PE_Event pe_event_poll(PE_Window* window);

#endif // __EVENT_H__
