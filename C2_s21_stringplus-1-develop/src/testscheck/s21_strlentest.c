#include "s21_stringtest.h"

START_TEST(test1) {
  char test[] = "abcde";
  ck_assert_int_eq(s21_strlen(test), strlen(test));
}
END_TEST

START_TEST(test2) {
  char test[] = "abcde\0\0";
  ck_assert_int_eq(s21_strlen(test), strlen(test));
}
END_TEST

START_TEST(test3) {
  char test[] = "abcde\0gfsdgds\0";
  ck_assert_int_eq(s21_strlen(test), strlen(test));
}
END_TEST

START_TEST(test4) {
  char test[] = "";
  ck_assert_int_eq(s21_strlen(test), strlen(test));
}
END_TEST

START_TEST(test5) {
  char test[] = "\0";
  ck_assert_int_eq(s21_strlen(test), strlen(test));
}
END_TEST

START_TEST(test6) {
  char test[] = "abcdefg";
  ck_assert_int_eq(s21_strlen(test), strlen(test));
}
END_TEST

START_TEST(test7) {
  char test[] = "abcde";
  test[2] = '\0';
  ck_assert_int_eq(s21_strlen(test), strlen(test));
}
END_TEST

START_TEST(test8) {
  char test[] = "abcde";
  test[5] = '\0';
  ck_assert_int_eq(s21_strlen(test), strlen(test));
}
END_TEST

START_TEST(test9) {
  char test[] = "abcde";
  test[0] = '\0';
  ck_assert_int_eq(s21_strlen(test), strlen(test));
}
END_TEST

START_TEST(test10) {
  char test[] = "abcde";
  test[4] = '\0';
  ck_assert_int_eq(s21_strlen(test), strlen(test));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *s = suite_create("suite_strlen");
  TCase *tc = tcase_create("strlen_tc\n");

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