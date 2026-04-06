#ifndef _STDIO_H
#define _STDIO_H
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SEEK_SET 1
#define SEEK_CUR 2
#define SEEK_END 3

int printf(const char* format, ...);
int snprintf(char* str, size_t size, const char* format, ...);
int sprintf(char* str, const char* format, ...);

#ifdef __cplusplus
}
#endif

#endif