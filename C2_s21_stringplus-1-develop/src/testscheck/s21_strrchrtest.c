#include "s21_stringtest.h"

START_TEST(test1) {
  char test[] = "abcdeddd";
  int c = 'd';
  ck_assert_ptr_eq(s21_strrchr(test, c), strrchr(test, c));
}
END_TEST

START_TEST(test2) {
  char test[] = "abcdedd";
  int c = 'd';
  ck_assert_ptr_eq(s21_strrchr(test, c), strrchr(test, c));
}
END_TEST

START_TEST(test3) {
  char test[] = "abcded";
  int c = 'd';
  ck_assert_ptr_eq(s21_strrchr(test, c), strrchr(test, c));
}
END_TEST

START_TEST(test4) {
  char test[] = "a\0bcded";
  int c = 'd';
  ck_assert_ptr_eq(s21_strrchr(test, c), strrchr(test, c));
}
END_TEST

START_TEST(test5) {
  char test[] = "abcded";
  int c = 'f';
  ck_assert_ptr_eq(s21_strrchr(test, c), strrchr(test, c));
}
END_TEST

START_TEST(test6) {
  char test[] = "";
  int c = 'd';
  ck_assert_ptr_eq(s21_strrchr(test, c), strrchr(test, c));
}
END_TEST

Suite *suite_strrchr(void) {
  Suite *s = suite_create("suite_strrchr");
  TCase *tc = tcase_create("strrchr_tc\n");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);

  suite_add_tcase(s, tc);
  return s;
}
