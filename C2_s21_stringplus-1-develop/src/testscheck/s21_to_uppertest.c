#include "s21_stringtest.h"

START_TEST(test1) {
  char test[] = "abcd";
  char test1[] = "ABCD";
  char *res = s21_to_upper(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test2) {
  char test[] = "nice work";
  char test1[] = "NICE WORK";
  char *res = s21_to_upper(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test3) {
  char test[] = "737+252";
  char test1[] = "737+252";
  char *res = s21_to_upper(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test4) {
  char test[] = " ";
  char test1[] = " ";
  char *res = s21_to_upper(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test5) {
  char test[] = "";
  char test1[] = "";
  char *res = s21_to_upper(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test6) {
  char test[] = "Hello, World!";
  char test1[] = "HELLO, WORLD!";
  char *res = s21_to_upper(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test7) {
  char test[] = "12345";
  char test1[] = "12345";
  char *res = s21_to_upper(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test8) {
  char test[] = "AbCdEfG";
  char test1[] = "ABCDEFG";
  char *res = s21_to_upper(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test9) {
  char test[] = "lowercase";
  char test1[] = "LOWERCASE";
  char *res = s21_to_upper(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test10) {
  char test[] = "!@#$%";
  char test1[] = "!@#$%";
  char *res = s21_to_upper(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

Suite *suite_to_upper(void) {
  Suite *s = suite_create("suite_to_upper");
  TCase *tc = tcase_create("to_upper_tc\n");

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
