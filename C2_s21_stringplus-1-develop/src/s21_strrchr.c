#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *res = s21_NULL;
  while (*str) {
    if (*str == c) {
      res = str;
    }
    str++;
  }
  return (char *)res;
}
