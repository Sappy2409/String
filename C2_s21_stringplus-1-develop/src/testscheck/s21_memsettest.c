#include "s21_stringtest.h"

START_TEST(test1) {
  char test1[] = "abcde";
  char test2 = 'a';
  char test3[] = "abcde";
  s21_memset(test1, test2, 3);
  memset(test3, test2, 3);
  // char test3[5] = "";
  ck_assert_str_eq(test1, test3);
}
END_TEST

START_TEST(test2) {
  char test1[] = "ab\0cde";
  char test2 = 'a';
  char test3[] = "ab\0cde";
  s21_memset(test1, test2, 3);
  memset(test3, test2, 3);
  // char test3[5] = "";
  ck_assert_str_eq(test1, test3);
}
END_TEST

START_TEST(test3) {
  char test1[] = "ab\0cde";
  char test2 = '\0';
  char test3[] = "ab\0cde";
  s21_memset(test1, test2, 3);
  memset(test3, test2, 3);
  // char test3[5] = "";
  ck_assert_str_eq(test1, test3);
}
END_TEST

START_TEST(test4) {
  char test1[] = "abcde";
  char test3[] = "abcde";
  char test2 = 'd';
  s21_memset(test1, test2, 3);
  memset(test3, test2, 3);
  // char test3[5] = "";
  ck_assert_str_eq(test1, test3);
}
END_TEST

Suite *suite_memset(void) {
  Suite *s = suite_create("suite_memset");
  TCase *tc = tcase_create("memset_tc\n");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);

  suite_add_tcase(s, tc);
  return s;
}