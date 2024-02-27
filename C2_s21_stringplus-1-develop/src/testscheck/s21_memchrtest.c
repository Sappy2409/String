#include "s21_stringtest.h"

START_TEST(test1) {
  char test[] = "abcde";
  int c = 'd';
  ck_assert_ptr_eq(s21_memchr(test, c, 5), memchr(test, c, 5));
}
END_TEST

START_TEST(test2) {
  char test[] = "abcde";
  int c = 'd';
  ck_assert_ptr_eq(s21_memchr(test, c, 2), memchr(test, c, 2));
}
END_TEST

START_TEST(test3) {
  char test[] = "abcde";
  int c = 'd';
  ck_assert_ptr_eq(s21_memchr(test, c, 5), memchr(test, c, 5));
}
END_TEST

START_TEST(test4) {
  char test[] = "a\0bcde";
  int c = 'd';
  ck_assert_ptr_eq(s21_memchr(test, c, 6), memchr(test, c, 6));
}
END_TEST

START_TEST(test5) {
  char test[] = "abcde";
  int c = 'f';
  ck_assert_ptr_eq(s21_memchr(test, c, 5), memchr(test, c, 5));
}
END_TEST

START_TEST(test6) {
  char test[] = "abcde";
  int c = 'a';
  ck_assert_ptr_eq(s21_memchr(test, c, 5), memchr(test, c, 5));
}
END_TEST

START_TEST(test7) {
  char test[] = "abcde";
  int c = '\0';
  ck_assert_ptr_eq(s21_memchr(test, c, 5), memchr(test, c, 5));
}
END_TEST

START_TEST(test8) {
  char test[] = "";
  int c = 'a';
  ck_assert_ptr_eq(s21_memchr(test, c, 0), memchr(test, c, 0));
}
END_TEST

START_TEST(test9) {
  char test[] = "abcde";
  int c = 'e';
  ck_assert_ptr_eq(s21_memchr(test, c, 5), memchr(test, c, 5));
}
END_TEST

START_TEST(test10) {
  char test[] = "abcde";
  int c = 'b';
  ck_assert_ptr_eq(s21_memchr(test, c, 2), memchr(test, c, 2));
}
END_TEST

Suite *suite_memchr(void) {
  Suite *s = suite_create("suite_memchr");
  TCase *tc = tcase_create("memchr_tc\n");

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