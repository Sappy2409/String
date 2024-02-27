#include "s21_stringtest.h"

START_TEST(test1) {
  char src[] = "Cho U Vas Zdes Proishodit.";
  char trim_chars[] = "";
  char expected[] = "Cho U Vas Zdes Proishodit.";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test2) {
  char src[] = "";
  char trim_chars[] = "Cho U Vas Zdes Proishodit.";
  char expected[] = "";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test3) {
  char src[] = "Cho U Vas Zdes Proishodit.";
  char trim_chars[] = "Cho U Vas Zdes Proishodit.";
  char expected[] = "";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test4) {
  char src[] = "Cho U Vas Zdes Proishodit. ";
  char trim_chars[] = " ";
  char expected[] = "Cho U Vas Zdes Proishodit.";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test5) {
  char src[] = "   Cho U Vas Zdes Proishodit. ";
  char trim_chars[] = " ";
  char expected[] = "Cho U Vas Zdes Proishodit.";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST
START_TEST(test6) {
  char src[] = "   Hello, World!   ";
  char trim_chars[] = " ";
  char expected[] = "Hello, World!";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test7) {
  char src[] = "1,2,3,4,5,";
  char trim_chars[] = ",";
  char expected[] = "1,2,3,4,5";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test8) {
  char src[] = "AaBbCcDdEe";
  char trim_chars[] = "ABCDE";
  char expected[] = "aBbCcDdEe";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test9) {
  char src[] = "abc123";
  char trim_chars[] = "def";
  char expected[] = "abc123";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test10) {
  char src[] = "1234";
  char trim_chars[] = "";
  char expected[] = "1234";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

Suite *suite_trim(void) {
  Suite *s = suite_create("suite_trim");
  TCase *tc = tcase_create("trim_tc\n");

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