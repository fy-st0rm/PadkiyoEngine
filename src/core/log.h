#ifndef __PE_log_H__
#define __PE_log_H__

#include "includes.h"

/*
 * @brief: Assertion macro
 */

#define pe_assert(x, ...) \
	do {\
		if (!(x)) {\
			fprintf(stderr, "\033[31m[ASSERTION]: %s:%d:\033[0m ", __FILE__, __LINE__);\
			fprintf(stderr, __VA_ARGS__);\
			exit(1);\
		}\
	} while(0);\

/*
 * @brief: pe_loging color codes
 */

#define PE_LOG_NORMAL 0
#define PE_LOG_ERROR  91
#define PE_LOG_SUCESS 92
#define PE_LOG_WARN   93
#define PE_LOG_INFO   95

/*
 * @brief: pe_loging macros
 */

#define pe_log_typed(type, ...)         \
	({                                     \
		printf("\033[%dm", type);            \
		printf(__VA_ARGS__);                 \
		printf("\033[%dm", PE_LOG_NORMAL);   \
	})

#define pe_log(...)                             \
	({                                            \
		pe_log_typed(PE_LOG_NORMAL, "[pe_log]:    ");  \
		pe_log_typed(PE_LOG_NORMAL, __VA_ARGS__);   \
	})

#define pe_log_sucess(...)                      \
	({                                            \
		pe_log_typed(PE_LOG_SUCESS, "[SUCESS]: ");  \
		pe_log_typed(PE_LOG_SUCESS, __VA_ARGS__);   \
	})

#define pe_log_warn(...)                        \
	({                                            \
		pe_log_typed(PE_LOG_WARN,   "[WARN]:   ");  \
		pe_log_typed(PE_LOG_WARN, __VA_ARGS__);     \
	})

#define pe_log_error(...)                       \
	({                                            \
		pe_log_typed(PE_LOG_ERROR,  "[ERROR]:  ");  \
		pe_log_typed(PE_LOG_ERROR, __VA_ARGS__);    \
	})

#define pe_log_info(...)                        \
	({                                            \
		pe_log_typed(PE_LOG_INFO,   "[INFO]:   ");  \
		pe_log_typed(PE_LOG_INFO, __VA_ARGS__);     \
	})


/*
 * @brief Macros and functions for opengl error handling
 */

#define GLCall(x)\
	(\
		clear_gl_error(), \
		x\
	);\
	pe_assert(gl_error_log(#x, __FILE__, __LINE__), "Opengl failed.\n");\

static void clear_gl_error() {
	while(glGetError());
}

static bool gl_error_log(const char* function, const char* file, int line) {
	GLenum error;
	while ((error = glGetError())) {
		pe_log_error("[Error code]: %d\n", error);
		pe_log_error("[Error message]: %s\n", gluErrorString(error));
		pe_log_error("[Opengl error]: %s %s: %d\n", function ,file, line);
		return false;
	}
	return true;
}

#endif // __PE_LOG_H__
