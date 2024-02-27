#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);
  char *res = s21_NULL;
  res = (char *)calloc((src_len + str_len + 1), sizeof(char));
  s21_size_t i = 0, j = 0;
  for (; i < start_index; i++) {
    res[i] = src[i];
  }
  for (; j < str_len; j++) {
    res[i++] = str[j];
  }
  for (j = start_index; j <= src_len; j++) {
    res[i++] = src[j];
  }
  res[s21_strlen(res)] = '\0';
  if (src == s21_NULL || str == s21_NULL || start_index > s21_strlen(src))
    res = s21_NULL;
  return (void *)res;
}
