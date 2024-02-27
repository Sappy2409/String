#include "s21_stringtest.h"

START_TEST(test1) {
  char test[] = "abcded";
  int c = 'd';
  ck_assert_ptr_eq(s21_strchr(test, c), strchr(test, c));
}
END_TEST

START_TEST(test2) {
  char test[] = "abcded";
  int c = 'd';
  ck_assert_ptr_eq(s21_strchr(test, c), strchr(test, c));
}
END_TEST

START_TEST(test3) {
  char test[] = "abcded";
  int c = 'd';
  ck_assert_ptr_eq(s21_strchr(test, c), strchr(test, c));
}
END_TEST

START_TEST(test4) {
  char test[] = "a\0bcded";
  int c = 'd';
  ck_assert_ptr_eq(s21_strchr(test, c), strchr(test, c));
}
END_TEST

START_TEST(test5) {
  char test[] = "abcded";
  int c = 'f';
  ck_assert_ptr_eq(s21_strchr(test, c), strchr(test, c));
}
END_TEST

START_TEST(test6) {
  char test[] = "abcdef";
  int c = 'a';
  ck_assert_ptr_eq(s21_strchr(test, c), strchr(test, c));
}
END_TEST

START_TEST(test7) {
  char test[] = "abcdef";
  int c = '\0';
  ck_assert_ptr_null(s21_strchr(test, c));
}
END_TEST

START_TEST(test8) {
  char test[] = "abcdef";
  int c = 'g';
  ck_assert_ptr_eq(s21_strchr(test, c), strchr(test, c));
}
END_TEST

START_TEST(test9) {
  char test[] = "";
  int c = 'a';
  ck_assert_ptr_eq(s21_strchr(test, c), strchr(test, c));
}
END_TEST

START_TEST(test10) {
  char test[] = "abcdef";
  int c = 'f';
  ck_assert_ptr_eq(s21_strchr(test, c), strchr(test, c));
}
END_TEST

Suite *suite_strchr(void) {
  Suite *s = suite_create("suite_strchr");
  TCase *tc = tcase_create("strchr_tc\n");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);
  tcase_add_test(tc, test7);
  tcase_add_test(tc, test8);
  tcase_add_test(tc, test9);
  tcase_add_test(tc, test10);
  suite_add_tcase(s, tc);
  return s;
}