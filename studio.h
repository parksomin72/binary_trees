#ifndef _STDIO_H
#define _STDIO_H 1

#include <stdarg.h>

#define EOF (-1)

typedef struct {
    /* Implementation-defined */
} FILE;

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

int printf(const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);
int sprintf(char *str, const char *format, ...);
int snprintf(char *str, size_t size, const char *format, ...);

int scanf(const char *format, ...);
int fscanf(FILE *stream, const char *format, ...);
int sscanf(const char *str, const char *format, ...);

int getchar(void);
int fgetc(FILE *stream);
char *fgets(char *str, int size, FILE *stream);

int putchar(int c);
int fputc(int c, FILE *stream);
int fputs(const char *str, FILE *stream);

int puts(const char *str);

int getc(FILE *stream);
int putc(int c, FILE *stream);
int ungetc(int c, FILE *stream);

int fflush(FILE *stream);

int fseek(FILE *stream, long offset, int whence);
long ftell(FILE *stream);
void rewind(FILE *stream);

void clearerr(FILE *stream);
int feof(FILE *stream);
int ferror(FILE *stream);
void perror(const char *s);

#endif /* _STDIO_H */
