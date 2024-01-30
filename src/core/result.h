#ifndef __RESULT_H__
#define __RESULT_H__

#include "log.h"

typedef enum {
	OK, ERROR
} ResultStatus;

#define DEFINE_RESULT(name, V, E)                             \
	typedef struct {                                            \
		ResultStatus status;                                      \
		union {                                                   \
			V result;                                               \
			E error;                                                \
		} __value;                                                \
	} Result_##name;                                            \
                                                              \
	Result_##name Result_##name##_ok(V v) {                     \
		return (Result_##name) {                                  \
			.status = OK,                                           \
			.__value.result = v                                     \
		};                                                        \
	}                                                           \
                                                              \
	Result_##name Result_##name##_err(E e) {                    \
		return (Result_##name) {                                  \
			.status = ERROR,                                        \
			.__value.error = e                                      \
		};                                                        \
	}                                                           \
                                                              \
	V Result_##name##_unwrap(Result_##name res) {               \
		if (res.status == OK) return res.__value.result;          \
		pe_assert(0, "Attempted to unwrap errored result\n");     \
	}                                                           \
                                                              \
	V Result_##name##_unwrap_or(Result_##name res, V x) {       \
		if (res.status == OK) return res.__value.result;          \
		return x;                                                 \
	}                                                           \
	                                                            \
	E Result_##name##_unwrap_err(Result_##name res) {           \
		if (res.status == ERROR) return res.__value.error;        \
		pe_assert(0, "Result was not an error\n");                \
	}                                                           \


#endif // __RESULT_H__
