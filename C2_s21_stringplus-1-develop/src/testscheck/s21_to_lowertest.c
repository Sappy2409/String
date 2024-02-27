#include "s21_stringtest.h"

START_TEST(test1) {
  char test[] = "ABCD";
  char test1[] = "abcd";
  char *res = s21_to_lower(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test2) {
  char test[] = "NICE WORK";
  char test1[] = "nice work";
  char *res = s21_to_lower(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test3) {
  char test[] = "737+252";
  char test1[] = "737+252";
  char *res = s21_to_lower(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test4) {
  char test[] = " ";
  char test1[] = " ";
  char *res = s21_to_lower(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test5) {
  char test[] = "";
  char test1[] = "";
  char *res = s21_to_lower(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test6) {
  char test[] = "Hello, World!";
  char test1[] = "hello, world!";
  char *res = s21_to_lower(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test7) {
  char test[] = "12345";
  char test1[] = "12345";
  char *res = s21_to_lower(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test8) {
  char test[] = "AbCdEfG";
  char test1[] = "abcdefg";
  char *res = s21_to_lower(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test9) {
  char test[] = "UPPERCASE";
  char test1[] = "uppercase";
  char *res = s21_to_lower(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

START_TEST(test10) {
  char test[] = "!@#$%";
  char test1[] = "!@#$%";
  char *res = s21_to_lower(test);
  ck_assert_str_eq(res, test1);
  free(res);
}
END_TEST

Suite *suite_to_lower(void) {
  Suite *s = suite_create("suite_to_lower");
  TCase *tc = tcase_create("to_lower_tc\n");

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