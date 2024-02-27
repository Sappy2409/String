#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  int count = 0;
  const char *str3 = str2;
  while (*str1 && !count) {
    while (*str2 && !count) {
      if (*str1 == *str2) {
        count = 1;
      }
      str2++;
    }
    str2 = str3;
    i++;
    str1++;
  }
  if (*str1 == '\0') {
    i++;
  }
  return i - 1;
}
