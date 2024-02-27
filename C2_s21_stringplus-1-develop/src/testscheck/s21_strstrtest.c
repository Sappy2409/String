#include "s21_stringtest.h"

START_TEST(test1) {
  char test[] = "abcdeddd";
  char test1[] = "ed";
  ck_assert_ptr_eq(s21_strstr(test, test1), strstr(test, test1));
}
END_TEST

START_TEST(test2) {
  char test[] = "abcdeddd";
  char test1[] = "edf";
  ck_assert_ptr_eq(s21_strstr(test, test1), strstr(test, test1));
}
END_TEST

START_TEST(test3) {
  char test[] = "abc\0deddd";
  char test1[] = "ed";
  ck_assert_ptr_eq(s21_strstr(test, test1), strstr(test, test1));
}
END_TEST

START_TEST(test4) {
  char test[] = "abc\0deddd";
  char test1[] = "bc\0de";
  ck_assert_ptr_eq(s21_strstr(test, test1), strstr(test, test1));
}
END_TEST

START_TEST(test5) {
  char test[] = "abcdedddbcde";
  char test1[] = "bcde";
  ck_assert_ptr_eq(s21_strstr(test, test1), strstr(test, test1));
}
END_TEST

START_TEST(test6) {
  char test[] = "";
  char test1[] = "abc";
  ck_assert_ptr_eq(s21_strstr(test, test1), strstr(test, test1));
}
END_TEST

Suite *suite_strstr(void) {
  Suite *s = suite_create("suite_strstr");
  TCase *tc = tcase_create("strstr_tc\n");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);

  suite_add_tcase(s, tc);
  return s;
}
