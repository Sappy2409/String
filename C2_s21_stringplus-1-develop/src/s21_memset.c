#include "s21_string.h"

void *s21_memset(void *ptr, int value, s21_size_t n) {
  unsigned char *memPtr = (unsigned char *)ptr;
  unsigned char memValue = (unsigned char)value;
  for (s21_size_t i = 0; i < n; i++) {
    memPtr[i] = memValue;
  }
  return ptr;
}