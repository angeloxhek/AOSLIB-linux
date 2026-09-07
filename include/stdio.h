#ifndef _STDIO_H
#define _STDIO_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define EOF (-1)

typedef struct _FILE FILE;

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

FILE *fopen(const char *filename, const char *mode);
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
int fclose(FILE *stream);

int fflush(FILE *stream);
int fseek(FILE *stream, long offset, int whence);
long ftell(FILE *stream);
void rewind(FILE *stream);

int fputc(int c, FILE *stream);
int fgetc(FILE *stream);
int puts(const char *s);
int fputs(const char *s, FILE *stream);

#ifdef __cplusplus
}
#endif

#endif /* _STDIO_H */