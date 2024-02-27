#include "s21_stringtest.h"

START_TEST(test1) {
  char test1[512] = {'\0'};
  char test2[512] = {'\0'};
  sprintf(test1, "numbers:%d%+d%10d%.10d%-10.5d", -123, -123, -123, -123, -123);
  s21_sprintf(test2, "numbers:%d%+d%10d%.10d%-10.5d", -123, -123, -123, -123,
              -123);
  // char test3[5] = "";
  ck_assert_str_eq(test2, test1);
}
END_TEST

START_TEST(test2) {
  char test1[512] = {'\0'};
  char test2[512] = {'\0'};
  sprintf(test1, "unumbers:%u%hu%10d%.10u%-10.5u", 456, 123, 123, 123, 123);
  s21_sprintf(test2, "unumbers:%u%hu%10d%.10u%-10.5u", 456, 123, 123, 123, 123);
  // char test3[5] = "";
  ck_assert_str_eq(test2, test1);
}
END_TEST

START_TEST(test3) {
  char test1[512] = {'\0'};
  char test2[512] = {'\0'};
  sprintf(test1, "chars:%c%10c%-10c", 'a', 'a', 'a');
  s21_sprintf(test2, "chars:%c%10c%-10c", 'a', 'a', 'a');
  // char test3[5] = "";
  ck_assert_str_eq(test2, test1);
}
END_TEST

START_TEST(test4) {
  char test1[512] = {'\0'};
  char test2[512] = {'\0'};
  sprintf(test1, "chars:%c", 'a');
  s21_sprintf(test2, "chars:%c", 'a');
  // char test3[5] = "";
  ck_assert_str_eq(test2, test1);
}
END_TEST

START_TEST(test5) {
  char test1[512] = {'\0'};
  char test2[512] = {'\0'};
  char test3[10] = "abc123\0";
  // sprintf(test1,"string:%s%10s%-10s%.3s%-10.3s", test3, test3, test3, test3);
  // s21_sprintf(test2,"string:%s%10s%-10s%.3s%-10.3s", test3, test3, test3,
  // test3);
  sprintf(test1, "string:%-10.3s%s%10s%.3s", test3, test3, test3, test3);
  s21_sprintf(test2, "string:%-10.3s%s%10s%.3s", test3, test3, test3, test3);
  // char test3[5] = "";
  ck_assert_str_eq(test2, test1);
}
END_TEST

START_TEST(test6) {
  char test12[512];
  char test22[512];
  sprintf(test12, "chars:%c", 'a');
  s21_sprintf(test22, "chars:%c", 'a');
  // char test3[5] = "";
  ck_assert_str_eq(test22, test12);
}
END_TEST

START_TEST(test7) {
  char test12[512];
  char test22[512];
  sprintf(test12, "double:%f% f%10f%-30.14f%30.14f", -123.123, 123.123,
          -123.123, -123.123, -123.123);
  s21_sprintf(test22, "double:%f% f%10f%-30.14f%30.14f", -123.123, 123.123,
              -123.123, -123.123, -123.123);
  // char test3[5] = "";
  ck_assert_str_eq(test22, test12);
}
END_TEST

START_TEST(test8) {
  char test12[512];
  char test22[512];
  sprintf(test12, "double:%.10f%.14f%.10f%%", 256.349999999, -123.100300,
          256.34);
  s21_sprintf(test22, "double:%.10f%.14f%.10f%%", 256.349999999, -123.100300,
              256.34);
  // char test3[5] = "";
  ck_assert_str_eq(test22, test12);
}
END_TEST

Suite *suite_sprintf(void) {
  Suite *s = suite_create("suite_sprintf");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);
  tcase_add_test(tc, test7);
  tcase_add_test(tc, test8);

  suite_add_tcase(s, tc);
  return s;
}
