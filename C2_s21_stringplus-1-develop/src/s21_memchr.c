#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *memchStr = (const unsigned char *)str;
  const unsigned char symbol = (const unsigned char)c;
  for (s21_size_t i = 0; i < n; i++) {
    if (memchStr[i] == symbol) {
      return (char *)(memchStr + i);
    }
  }
  return s21_NULL;
}