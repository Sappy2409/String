#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  for (; (*(char *)str1 && n > 1) && *(char *)str1 == *(char *)str2;
       str1++, str2++, n--) {
  }
  return *(char *)str1 - *(char *)str2;
}
