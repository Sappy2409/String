#include "s21_stringtest.h"

START_TEST(test1) {
  char strtok1[30] = " test1/test2-/-//--test3/test4";
  char strtok2[30] = " test1/test2-/-//--test3/test4";
  char sep[10] = "/-";
  char *istrtok;
  char *istrtok1;
  istrtok = s21_strtok(strtok1, sep);
  istrtok1 = strtok(strtok2, sep);
  ck_assert_str_eq(istrtok, istrtok1);
}
END_TEST

START_TEST(test2) {
  char strtok1[30] = " test1/test2-/-//--test3/test4";
  char strtok2[30] = " test1/test2-/-//--test3/test4";
  char sep[10] = "/-";
  char *istrtok;
  char *istrtok1;
  istrtok = s21_strtok(strtok1, sep);
  istrtok1 = strtok(strtok2, sep);
  istrtok = s21_strtok(NULL, sep);
  istrtok1 = strtok(NULL, sep);
  ck_assert_str_eq(istrtok, istrtok1);
}
END_TEST

START_TEST(test3) {
  char strtok1[30] = " test1/test2-/-//--test3/test4";
  char strtok2[30] = " test1/test2-/-//--test3/test4";
  char sep[10] = "/-";
  char *istrtok;
  char *istrtok1;
  istrtok = s21_strtok(strtok1, sep);
  istrtok1 = strtok(strtok2, sep);
  while (istrtok != NULL || istrtok1 != NULL) {
    ck_assert_str_eq(istrtok, istrtok1);
    istrtok = s21_strtok(NULL, sep);
    istrtok1 = strtok(NULL, sep);
  }
}
END_TEST

Suite *suite_strtok(void) {
  Suite *s = suite_create("suite_strtok");
  TCase *tc = tcase_create("strtok_tc\n");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);

  suite_add_tcase(s, tc);
  return s;
}
