#include "s21_string.h"

void *s21_to_lower(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *res = s21_NULL;
  res = (char *)calloc((len + 1), sizeof(char));
  if (str != s21_NULL) {
    s21_strncpy(res, str, len + 1);
    for (s21_size_t i = 0; i < len; i++) {
      if (res[i] >= 'A' && res[i] <= 'Z') {
        res[i] += 32;
      }
    }
  }
  return (void *)res;
}