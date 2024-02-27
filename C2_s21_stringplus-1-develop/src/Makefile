all:clean s21_string.a test gcov_report

s21_string.a: clean
	gcc -c -std=c11 -Wall -Werror -Wextra s21_*.c
	ar r s21_string.a s21_*.o

test:cleantest
	gcc -std=c11 -Wall -Werror -Wextra s21_string.a ./testscheck/s21_*.c -o test -lcheck
	./test

gcov_report:cleantest s21_string.a
	gcc -std=c11 -Wall -Werror -Wextra -fprofile-arcs -ftest-coverage s21_string.a ./testscheck/s21_*.c s21_*.c -o tests -lcheck
	./tests
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html

clean:cleantest
	rm -rf *.o
	rm -rf *.a

cleantest:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf tests
	rm -rf report
