#include "s21_stringtest.h"

START_TEST(test1) {
  int errnum = 10;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(test2) {
  int errnum = 0;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(test3) {
  int errnum = -10;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(test4) {
  int errnum = 150;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

Suite *suite_strerror(void) {
  Suite *s = suite_create("suite_strerror");
  TCase *tc = tcase_create("strerror_tc\n");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);

  suite_add_tcase(s, tc);
  return s;
}