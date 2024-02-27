#include "s21_stringtest.h"

START_TEST(test1) {
  char test1[10] = "abcde";
  char test2[10] = "fgh";
  char test3[10] = "fgh";
  s21_strncat(test2, test1, 5);
  strncat(test3, test1, 5);
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test2) {
  char test1[10] = "abcde";
  char test2[10] = "fg\0h";
  char test3[10] = "fg\0h";
  s21_strncat(test2, test1, 5);
  strncat(test3, test1, 5);
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test3) {
  char test1[10] = "abcde";
  char test2[10] = "fg\0h";
  char test3[10] = "fg\0h";
  s21_strncat(test2, test1, 7);
  strncat(test3, test1, 7);
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test4) {
  char test1[10] = "abcde";
  char test2[10] = "ijk";
  char test3[10] = "ijk";
  s21_strncat(test2, test1, 5);
  strncat(test3, test1, 5);
  ck_assert_str_eq(test2, test3);
}
END_TEST

Suite *suite_strncat(void) {
  Suite *s = suite_create("suite_strncat");
  TCase *tc = tcase_create("strncat_tc\n");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);

  suite_add_tcase(s, tc);
  return s;
}
