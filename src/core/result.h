#ifndef __RESULT_H__
#define __RESULT_H__

#include "log.h"

typedef enum {
	OK, ERROR
} ResultStatus;

#define DEFINE_RESULT(V, E)                             \
	typedef struct {                                      \
		ResultStatus status;                                \
		union {                                             \
			V result;                                         \
			E error;                                          \
		} __value;                                          \
	} Result_##V;                                         \
                                                        \
	Result_##V Result_##V##_ok(V v) {                     \
		return (Result_##V) {                               \
			.status = OK,                                     \
			.__value = v                                      \
		};                                                  \
	}                                                     \
                                                        \
	Result_##V Result_##V##_err(E e) {                    \
		return (Result_##V) {                               \
			.status = ERROR,                                  \
			.__value = e                                      \
		};                                                  \
	}                                                     \
                                                        \
	V Result_##V##_unwrap(Result_##V res) {               \
		if (res.status == OK) return res.__value.result;    \
		assert(0, "Attempted to unwrap errored result\n");  \
	}                                                     \
                                                        \
	V Result_##V##_unwrap_or(Result_##V res, V x) {       \
		if (res.status == OK) return res.__value.result;    \
		return x;                                           \
	}                                                     \
	                                                      \
	V Result_##V##_unwrap_err(Result_##V res) {           \
		if (res.status == ERROR) return res.__value.error;  \
		assert(0, "Result was not an error\n");             \
	}                                                     \


#endif // __RESULT_H__
