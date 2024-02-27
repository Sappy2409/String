#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *res = s21_NULL;
  while (*str && res == s21_NULL) {
    if (*str == c) {
      res = str;
    }
    str++;
  }
  return (char *)res;
}
