#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = s21_NULL;
  s21_size_t i;
  if (s21_strlen(needle) == 0) {
    res = (char *)haystack;
  } else {
    for (; *haystack && (res == s21_NULL); haystack++) {
      for (i = 0;
           *(haystack + i) && *(needle + i) && *(haystack + i) == *(needle + i);
           i++) {
      }
      if (i == s21_strlen(needle)) {
        res = (char *)haystack;
      }
    }
  }
  return res;
}
