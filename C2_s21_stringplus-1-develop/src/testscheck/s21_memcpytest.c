#include "s21_stringtest.h"

START_TEST(test1) {
  char test1[10] = "abcde";
  char test2[10] = "";
  char test3[10] = "";
  s21_memcpy(test2, test1, 5);
  memcpy(test3, test1, 5);
  // char test3[5] = "";
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test2) {
  char test1[10] = "abcde";
  char test2[10] = "123";
  char test3[10] = "123";
  s21_memcpy(test2, test1, 5);
  memcpy(test3, test1, 5);
  // char test3[5] = "";
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test3) {
  char test1[] = "abcde";
  char test2[10] = "123";
  char test3[10] = "123";
  s21_memcpy(test2, test1, 0);
  memcpy(test3, test1, 0);
  // char test3[5] = "";
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test4) {
  char test1[15] = "abcde";
  char test2[10] = "123";
  char test3[10] = "123";
  s21_memcpy(test2, test1, 10);
  memcpy(test3, test1, 10);
  // char test3[5] = "";
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test5) {
  char test1[] = "ab\0cde";
  char test2[10] = "123";
  char test3[10] = "123";
  s21_memcpy(test2, test1, 5);
  memcpy(test3, test1, 5);
  // char test3[5] = "";
  ck_assert_str_eq(test2, test3);
}
END_TEST

START_TEST(test6) {
  char test1[10] = "abcde";
  char test2[10] = "123123123";
  char test3[10] = "123123123";
  s21_memcpy(test2, test1, 5);
  memcpy(test3, test1, 5);
  // char test3[5] = "";
  ck_assert_str_eq(test2, test3);
}
END_TEST

Suite *suite_memcpy(void) {
  Suite *s = suite_create("suite_memcpy");
  TCase *tc = tcase_create("memcpy_tc\n");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);

  suite_add_tcase(s, tc);
  return s;
}