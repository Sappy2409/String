#include "s21_stringtest.h"

START_TEST(test1) {
  char test1[] = "abcde";
  char test2[] = "abcdefgh";
  int n = 5;
  ck_assert_int_eq(s21_strncmp(test1, test2, n), strncmp(test1, test2, n));
}
END_TEST

START_TEST(test2) {
  char test1[] = "abcde";
  char test2[] = "abc\0defgh";
  int n = 5;
  ck_assert_int_eq(s21_strncmp(test1, test2, n), strncmp(test1, test2, n));
}
END_TEST

START_TEST(test3) {
  char test1[] = "ab\0cfde";
  char test2[] = "ab\0cdefgh";
  int n = 5;
  ck_assert_int_eq(s21_strncmp(test1, test2, n), strncmp(test1, test2, n));
}
END_TEST

START_TEST(test4) {
  char test1[5] = "abcde";
  char test2[5] = "abc";
  int n = 5;
  ck_assert_int_eq(s21_strncmp(test1, test2, n), strncmp(test1, test2, n));
}
END_TEST

START_TEST(test5) {
  char test1[] = "abcde";
  char test2[] = "abcde";
  int n = 5;
  ck_assert_int_eq(s21_strncmp(test1, test2, n), strncmp(test1, test2, n));
}
END_TEST

START_TEST(test6) {
  char test1[] = "ab\0cde";
  char test2[] = "abc\0de";
  int n = 5;
  ck_assert_int_eq(s21_strncmp(test1, test2, n), strncmp(test1, test2, n));
}
END_TEST

START_TEST(test7) {
  char test1[5] = "";
  char test2[] = "abcde";
  int n = 5;
  ck_assert_int_eq(s21_strncmp(test1, test2, n), strncmp(test1, test2, n));
}
END_TEST

START_TEST(test8) {
  char test1[] = "abcde";
  char test2[] = "abcdf";
  int n = 5;
  ck_assert_int_eq(s21_strncmp(test1, test2, n), strncmp(test1, test2, n));
}
END_TEST

Suite *suite_strncmp(void) {
  Suite *s = suite_create("suite_strncmp");
  TCase *tc = tcase_create("strncmp_tc\n");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);
  tcase_add_test(tc, test7);
  tcase_add_test(tc, test8);

  suite_add_tcase(s, tc);
  return s;
}
