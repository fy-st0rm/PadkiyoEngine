#ifndef __LOG_H__
#define __LOG_H__

#include <stdio.h>
#include <stdlib.h>

/*
 * @brief: Assertion macro
 */

#define __assert(...) ({ fprintf(stderr, "\033[31m[ASSERTION]: %s:%d:\033[0m ", __FILE__, __LINE__); fprintf(stderr, __VA_ARGS__); exit(1); })
#define assert(x, ...) \
	do {\
		if (!(x)) (__assert(__VA_ARGS__));\
	} while (0);\

/*
 * @brief: Loging color codes
 */

#define LOG_NORMAL 0
#define LOG_ERROR  91
#define LOG_SUCESS 92
#define LOG_WARN   93
#define LOG_INFO   95

/*
 * @brief: Loging macros
 */

#define log_typed(type, ...)         \
	({                                     \
		printf("\033[%dm", type);            \
		printf(__VA_ARGS__);                 \
		printf("\033[%dm", LOG_NORMAL);   \
	})

#define log(...)                             \
	({                                            \
		log_typed(LOG_NORMAL, "[LOG]:    ");  \
		log_typed(LOG_NORMAL, __VA_ARGS__);   \
	})

#define log_sucess(...)                      \
	({                                            \
		log_typed(LOG_SUCESS, "[SUCESS]: ");  \
		log_typed(LOG_SUCESS, __VA_ARGS__);   \
	})

#define log_warn(...)                        \
	({                                            \
		log_typed(LOG_WARN,   "[WARN]:   ");  \
		log_typed(LOG_WARN, __VA_ARGS__);     \
	})

#define log_error(...)                       \
	({                                            \
		log_typed(LOG_ERROR,  "[ERROR]:  ");  \
		log_typed(LOG_ERROR, __VA_ARGS__);    \
	})

#define log_info(...)                        \
	({                                            \
		log_typed(LOG_INFO,   "[INFO]:   ");  \
		log_typed(LOG_INFO, __VA_ARGS__);     \
	})

#endif // __LOG_H__
