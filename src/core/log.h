#ifndef __PE_log_H__
#define __PE_log_H__

#include <stdio.h>
#include <stdlib.h>

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

#endif // __PE_LOG_H__
