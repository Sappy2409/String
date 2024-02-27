#include "s21_stringtest.h"

START_TEST(test1) {
  char test1[] = "abcde";
  char test2[] = "abcdefgh";
  ck_assert_int_eq(s21_memcmp(test1, test2, 5), memcmp(test1, test2, 5));
}
END_TEST

START_TEST(test2) {
  char test1[] = "abcde";
  char test2[] = "abc\0defgh";
  ck_assert_int_eq(s21_memcmp(test1, test2, 5), memcmp(test1, test2, 5));
}
END_TEST

START_TEST(test3) {
  char test1[] = "ab\0cde";
  char test2[] = "ab\0cfdefgh";
  ck_assert_int_eq(s21_memcmp(test1, test2, 5), memcmp(test1, test2, 5));
}
END_TEST

START_TEST(test4) {
  char test1[] = "abcde";
  char test2[10] = "abc";
  ck_assert_int_eq(s21_memcmp(test1, test2, 5), memcmp(test1, test2, 5));
}
END_TEST

START_TEST(test5) {
  char test1[] = "ab\0cde";
  char test2[] = "abc\0de";
  ck_assert_int_eq(s21_memcmp(test1, test2, 5), memcmp(test1, test2, 5));
}
END_TEST

START_TEST(test6) {
  char test1[] = "abcde";
  char test2[] = "abcde";
  ck_assert_int_eq(s21_memcmp(test1, test2, 0), memcmp(test1, test2, 0));
}
END_TEST

START_TEST(test7) {
  char test1[10] = "";
  char test2[10] = "abcde";
  ck_assert_int_eq(s21_memcmp(test1, test2, 10), memcmp(test1, test2, 10));
}
END_TEST

START_TEST(test8) {
  char test1[] = "abcde";
  char test2[] = "abcde";
  ck_assert_int_eq(s21_memcmp(test1, test2, 5), memcmp(test1, test2, 5));
}
END_TEST

START_TEST(test9) {
  char test1[] = "";
  char test2[] = "";
  ck_assert_int_eq(s21_memcmp(test1, test2, 0), memcmp(test1, test2, 0));
}
END_TEST

START_TEST(test10) {
  char test1[] = "abcde";
  char test2[] = "abc";
  ck_assert_int_eq(s21_memcmp(test1, test2, 3), memcmp(test1, test2, 3));
}
END_TEST

START_TEST(test11) {
  char test1[] = "abc\0de";
  char test2[] = "abcde";
  ck_assert_int_eq(s21_memcmp(test1, test2, 6), memcmp(test1, test2, 6));
}
END_TEST

Suite *suite_memcmp(void) {
  Suite *s = suite_create("suite_memcmp");
  TCase *tc = tcase_create("memcmp_tc\n");

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
  tcase_add_test(tc, test11);

  suite_add_tcase(s, tc);
  return s;
}