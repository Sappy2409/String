#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  char *res = s21_NULL;
  static char *last = s21_NULL;
  if (str) {
    last = str;
  }
  if (last == s21_NULL) {
    res = s21_NULL;
  } else {
    char *first = last;
    res = s21_strpbrk(last, delim);
    if (res != s21_NULL) {
      *res = '\0';
      last = res + 1;
      res = first;
      while (s21_strchr(delim, *last) != s21_NULL) {
        *last = '\0';
        last = last + 1;
      }
    } else {
      res = first;
      last = s21_NULL;
    }
  }
  return res;
}
