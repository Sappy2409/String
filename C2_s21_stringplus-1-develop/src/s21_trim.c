#include "s21_string.h"

int is_trim_char(char ch, const char *trim_chars) {  /////////проверка на трим
  int res = 0;
  for (s21_size_t i = 0; i < s21_strlen(trim_chars); i++) {
    if (ch == trim_chars[i]) {
      res = 1;
    }
  }
  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = s21_NULL;
  s21_size_t src_len = s21_strlen(src);
  s21_size_t start = 0;
  s21_size_t end = src_len - 1;
  for (; start < src_len && is_trim_char(src[start], trim_chars);
       start++) { /*зато в одну строку*/
  }               /////топаем слева-направо
  for (; end > start && is_trim_char(src[end], trim_chars);
       end--) { /*здесь тоже*/
  }             /////топаем справа-налево
  s21_size_t trim_len = end - start + 1;  /////считаем сколько натопали
  res = (char *)calloc(trim_len + 1, sizeof(char));
  s21_strncpy(res, src + start, trim_len);
  res[trim_len] = '\0';
  if (src == s21_NULL || trim_chars == s21_NULL) res = s21_NULL;
  return (void *)res;
}