#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *dest1 = dest;
  while (*dest) {
    dest++;
  }
  for (; n > 0; n--) {
    *dest++ = *src++;
  }
  return dest1;
}
