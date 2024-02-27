#include "s21_stringtest.h"

START_TEST(test1) {
  char test[] = "abcadeddd";
  char test1[] = "cd";
  ck_assert_int_eq(s21_strcspn(test, test1), strcspn(test, test1));
}
END_TEST

START_TEST(test2) {
  char test[] = "abcadedddf";
  char test1[] = "gh";
  ck_assert_int_eq(s21_strcspn(test, test1), strcspn(test, test1));
}
END_TEST

START_TEST(test3) {
  char test[] = "abcad\0edddf";
  char test1[] = "ghe";
  ck_assert_int_eq(s21_strcspn(test, test1), strcspn(test, test1));
}
END_TEST

START_TEST(test4) {
  char test[] = "abcadedddf";
  char test1[] = "gh\0e";
  ck_assert_int_eq(s21_strcspn(test, test1), strcspn(test, test1));
}
END_TEST

START_TEST(test5) {
  char test[] = "abcadedddf";
  char test1[] = "";
  ck_assert_int_eq(s21_strcspn(test, test1), strcspn(test, test1));
}
END_TEST

START_TEST(test6) {
  char test[] = "";
  char test1[] = "adsadsa";
  ck_assert_int_eq(s21_strcspn(test, test1), strcspn(test, test1));
}
END_TEST

START_TEST(test7) {
  char test[] = "abcadedddf";
  char test1[] = "abc";
  ck_assert_int_eq(s21_strcspn(test, test1), strcspn(test, test1));
}
END_TEST

START_TEST(test8) {
  char test[] = "abcadedddf";
  char test1[] = "d";
  ck_assert_int_eq(s21_strcspn(test, test1), strcspn(test, test1));
}
END_TEST

START_TEST(test9) {
  char test[] = "abcadedddf";
  char test1[] = "xyz";
  ck_assert_int_eq(s21_strcspn(test, test1), strcspn(test, test1));
}
END_TEST

START_TEST(test10) {
  char test[] = "abcadedddf";
  char test1[] = " ";
  ck_assert_int_eq(s21_strcspn(test, test1), strcspn(test, test1));
}
END_TEST

Suite *suite_strcspn(void) {
  Suite *s = suite_create("suite_strcspn");
  TCase *tc = tcase_create("strcspn_tc\n");

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