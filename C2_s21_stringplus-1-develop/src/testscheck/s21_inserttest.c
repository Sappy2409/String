#include "s21_stringtest.h"

START_TEST(test1) {
  char src[] = "Cho U Vas Zdes ";
  char str[] = "Proishodit.";
  s21_size_t start_index = 15;
  char expected[] = "Cho U Vas Zdes Proishodit.";
  char *res = s21_insert(src, str, start_index);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test2) {
  char src[] = " Is My Party And I Cry If I Want To.";
  char str[] = "It";
  s21_size_t start_index = 0;
  char expected[] = "It Is My Party And I Cry If I Want To.";
  char *res = s21_insert(src, str, start_index);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test3) {
  char src[] = "All Your  Are Belong To Us.";
  char str[] = "Base";
  s21_size_t start_index = 9;
  char expected[] = "All Your Base Are Belong To Us.";
  char *res = s21_insert(src, str, start_index);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test4) {
  char src[] = "Your Memes End ";
  char str[] = "Here.";
  s21_size_t start_index = 15;
  char expected[] = "Your Memes End Here.";
  char *res = s21_insert(src, str, start_index);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test5) {
  char src[] = "";
  char str[] = "";
  s21_size_t start_index = 0;
  char expected[] = "";
  char *res = s21_insert(src, str, start_index);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test6) {
  char src[] = "Hello World!";
  char str[] = "Insertion ";
  s21_size_t start_index = 6;
  char expected[] = "Hello Insertion World!";
  char *res = s21_insert(src, str, start_index);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test7) {
  char src[] = "Testing";
  char str[] = " 123 ";
  s21_size_t start_index = 0;
  char expected[] = " 123 Testing";
  char *res = s21_insert(src, str, start_index);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test8) {
  char src[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char str[] = "123";
  s21_size_t start_index = 26;
  char expected[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123";
  char *res = s21_insert(src, str, start_index);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test9) {
  char src[] = "Hello, World!";
  char str[] = "Goodbye";
  s21_size_t start_index = 13;
  char expected[] = "Hello, World!Goodbye";
  char *res = s21_insert(src, str, start_index);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(test10) {
  char src[] = "0123456789";
  char str[] = "abcdef";
  s21_size_t start_index = 5;
  char expected[] = "01234abcdef56789";
  char *res = s21_insert(src, str, start_index);
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

Suite *suite_insert(void) {
  Suite *s = suite_create("suite_insert");
  TCase *tc = tcase_create("insert_tc\n");

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