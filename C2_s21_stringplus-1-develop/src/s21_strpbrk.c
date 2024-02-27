#include "s21_string.h"

char* s21_strpbrk(const char* str1, const char* str2) {
  char* res = s21_NULL;
  const char* str3 = str2;
  while (*str1 && !res) {
    while (*str2 && !res) {
      if (*str1 == *str2) {
        res = (char*)str1;
      }
      str2++;
    }
    str2 = str3;
    str1++;
  }
  return res;
}
