#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
  char *cdest = dest;
  for (; *src && n > 0; dest++, src++, n--) {
    *dest = *src;
  }
  if (*src == '\0' && n > 0) {
    *dest = *src;
  }
  return cdest;
}
