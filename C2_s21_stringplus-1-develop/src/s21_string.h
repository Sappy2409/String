#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

typedef struct {
  int minus;
  int plus;
  int space;
  int precision;
  int is_precision_set;
  int width;
  char length;
  char specifier;
} flags;
#define s21_NULL ((void *)0)
typedef long unsigned s21_size_t;
s21_size_t s21_strlen(const char *str);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strncpy(char *dest, const char *src, size_t n);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strtok(char *str, const char *delim);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strerror(int errnum);
int s21_sprintf(char *str, const char *format, ...);
char *s21_inttostr(char *str, int n, flags f);
char *s21_doubletostring(char *str, double n, flags f);
void specdfunc(flags f, char *buff, va_list factor);
const char *get_flags(const char *format, flags *f);
const char *get_width(const char *format, flags *f);
const char *get_precision(const char *format, flags *f);
const char *get_length(const char *format, flags *f);
int s21_isdigit(char c);
int s21_strtoint(char *str);
void specufunc(flags f, char *buff, va_list factor);
char *s21_uinttostr(char *str, unsigned n, flags f);
void speccfunc(flags f, char *buff, va_list factor);
void specsfunc(flags f, char *buff, va_list factor);
void specffunc(flags f, char *buff, va_list factor);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
char *s21_strtok(char *str, const char *delim);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
void specprocfunc(char *buff);
#endif  // SRC_S21_STRING_H_