#ifndef _STDLIB_H
#define _STDLIB_H
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

__attribute__((noreturn)) void exit(int code);

void* malloc(size_t size);
void free(void* ptr);
void* realloc(void* ptr, size_t new_size);
void* calloc(size_t num, size_t size);

int atoi(const char *str);
long atol(const char *str);
long long atoll(const char *str);
unsigned long long strtoull(const char *nptr, char **endptr, int base);
long long strtoll(const char *nptr, char **endptr, int base);

char* itoa(int value, char* str, int base);
char* utoa(unsigned int value, char* str, int base);
char* ltoa(long value, char* str, int base);
char* ultoa(unsigned long value, char* str, int base);
char* lltoa(long long value, char* str, int base);
char* ulltoa(unsigned long long value, char* str, int base);

#ifdef __cplusplus
}
#endif

#endif