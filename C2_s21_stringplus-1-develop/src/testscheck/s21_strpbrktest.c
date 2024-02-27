#include "s21_stringtest.h"

START_TEST(test1) {
  char test[] = "abcdeddd";
  char test1[] = "fd";
  ck_assert_ptr_eq(s21_strpbrk(test, test1), strpbrk(test, test1));
}
END_TEST

START_TEST(test2) {
  char test[] = "abcdeddd";
  char test1[] = "ff";
  ck_assert_ptr_eq(s21_strpbrk(test, test1), strpbrk(test, test1));
}
END_TEST

START_TEST(test3) {
  char test[] = "abc\0deddd";
  char test1[] = "fd";
  ck_assert_ptr_eq(s21_strpbrk(test, test1), strpbrk(test, test1));
}
END_TEST

START_TEST(test4) {
  char test[] = "abcdeddd";
  char test1[] = "da";
  ck_assert_ptr_eq(s21_strpbrk(test, test1), strpbrk(test, test1));
}
END_TEST

START_TEST(test5) {
  char test[] = "abcdeddd";
  char test1[] = "f\0d";
  ck_assert_ptr_eq(s21_strpbrk(test, test1), strpbrk(test, test1));
}
END_TEST

START_TEST(test6) {
  char test[] = "abcdeddd";
  char test1[] = "";
  ck_assert_ptr_eq(s21_strpbrk(test, test1), strpbrk(test, test1));
}
END_TEST

START_TEST(test7) {
  char test[] = "";
  char test1[] = "abcdeddd";
  ck_assert_ptr_eq(s21_strpbrk(test, test1), strpbrk(test, test1));
}
END_TEST

START_TEST(test8) {
  char test[] = "";
  char test1[] = "";
  ck_assert_ptr_eq(s21_strpbrk(test, test1), strpbrk(test, test1));
}
END_TEST

START_TEST(test9) {
  char test[] = "abcdeddd";
  char test1[] = "xyz";
  ck_assert_ptr_eq(s21_strpbrk(test, test1), strpbrk(test, test1));
}
END_TEST

START_TEST(test10) {
  char test[] = "abcdeddd";
  char test1[] = "d";
  ck_assert_ptr_eq(s21_strpbrk(test, test1), strpbrk(test, test1));
}
END_TEST

START_TEST(test11) {
  char test[] = "abcdeddd";
  char test1[] = "fgh";
  ck_assert_ptr_eq(s21_strpbrk(test, test1), strpbrk(test, test1));
}
END_TEST

START_TEST(test12) {
  char test[] = "abcdeddd";
  char test1[] = "abcdefg";
  ck_assert_ptr_eq(s21_strpbrk(test, test1), strpbrk(test, test1));
}
END_TEST

Suite *suite_strpbrk(void) {
  Suite *s = suite_create("suite_strpbrk");
  TCase *tc = tcase_create("strpbrk_tc\n");

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
  tcase_add_test(tc, test12);

  suite_add_tcase(s, tc);
  return s;
}
