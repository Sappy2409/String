#include "s21_stringtest.h"

void run_tests(void) {
  Suite *list_cases[] = {suite_strtok(),   suite_strstr(),   suite_strerror(),
                         suite_strcspn(),  suite_strpbrk(),  suite_strrchr(),
                         suite_strncpy(),  suite_strncmp(),  suite_strchr(),
                         suite_strncat(),  suite_memset(),   suite_memcpy(),
                         suite_memcmp(),   suite_memchr(),   suite_strlen(),
                         suite_to_lower(), suite_to_upper(), suite_trim(),
                         suite_insert(),   suite_sprintf(),  NULL};
  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;

  if (counter_testcase > 0) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;
  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
  // sleep(1);
}

int main(void) {
  run_tests();
  return 0;
}