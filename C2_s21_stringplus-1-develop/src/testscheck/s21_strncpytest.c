#include "s21_stringtest.h"

START_TEST(test1) {
  char test1[10] = "abcde";
  char test2[10] = "";
  char test3[10] = "";
  s21_strncpy(test2, test1, 5);
  strncpy(test3, test1, 5);
  // char test3[5] = "";
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test2) {
  char test1[10] = "abcde";
  char test2[10] = "12\03";
  char test3[10] = "12\03";
  s21_strncpy(test2, test1, 5);
  strncpy(test3, test1, 5);
  // char test3[5] = "";
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test3) {
  char test1[] = "abcde";
  char test2[10] = "123";
  char test3[10] = "123";
  s21_strncpy(test2, test1, 0);
  strncpy(test3, test1, 0);
  // char test3[5] = "";
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test4) {
  char test1[15] = "abcde";
  char test2[10] = "123";
  char test3[10] = "123";
  s21_strncpy(test2, test1, 10);
  strncpy(test3, test1, 10);
  // char test3[5] = "";
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test5) {
  char test1[] = "ab\0cde";
  char test2[10] = "123";
  char test3[10] = "123";
  s21_strncpy(test2, test1, 5);
  strncpy(test3, test1, 5);
  // char test3[5] = "";
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test6) {
  char test1[10] = "abcde";
  char test2[10] = "123123123";
  char test3[10] = "123123123";
  s21_strncpy(test2, test1, 5);
  strncpy(test3, test1, 5);
  // char test3[5] = "";
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test7) {
  char test1[] = "abcde";
  char test2[10] = "123456789";
  char test3[10] = "123456789";
  s21_strncpy(test2, test1, 3);
  strncpy(test3, test1, 3);
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test8) {
  char test1[] = "abcde";
  char test2[10] = "";
  char test3[10] = "";
  s21_strncpy(test2, test1, 0);
  strncpy(test3, test1, 0);
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test9) {
  char test1[] = "abcde";
  char test2[10] = "123456";
  char test3[10] = "123456";
  s21_strncpy(test2, test1, 10);
  strncpy(test3, test1, 10);
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test10) {
  char test1[] = "abcde";
  char test2[10] = "xyz";
  char test3[10] = "xyz";
  s21_strncpy(test2, test1, 2);
  strncpy(test3, test1, 2);
  ck_assert_str_eq(test2, test3);
}
END_TEST

Suite *suite_strncpy(void) {
  Suite *s = suite_create("suite_strncpy");
  TCase *tc = tcase_create("strncpy_tc\n");

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