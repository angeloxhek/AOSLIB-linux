#ifndef _STRING_H
#define _STRING_H
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void* memset(void* ptr, int value, size_t n);
void* memcpy(void* dest, const void* src, size_t n);
void* memmove(void* dest, const void* src, size_t n);
int memcmp(const void* s1, const void* s2, size_t n);

int strcmp(const char* s1, const char* s2);
char* strcpy(char *dest, const char *src);
char* strncpy(char *dest, const char *src, size_t n);
char* strchr(const char* s, int c);
char* strrchr(const char* s, int c);
char* strstr(const char* haystack, const char* needle);
char* strtok(char* str, const char* delim);
size_t strlen(const char* s);
char* strcat(char* dest, const char* src);
char* strncat(char* dest, const char* src, size_t n);

char* strdup(const char* s);
char* strtok_r(char* str, const char* delim, char** saveptr);
char* strsep(char** stringp, const char* delim);
size_t strnlen(const char* s, size_t maxlen);
size_t strlcpy(char *dest, const char *src, size_t n);
size_t strlcat(char* dest, const char* src, size_t size);

#ifdef __cplusplus
}
#endif

#endif