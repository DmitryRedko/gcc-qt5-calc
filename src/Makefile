.PHONY: all build install test clean gcov_report uninstall dist dvi linter linter_wow cppcheck

CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
TESTFILE = test
GCOV_FLAG = -lgcov --coverage

LIBS_FOR_CHECK_PCKG =
D_OS =
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	LIBS_FOR_CHECK_PCKG = -lcheck -lsubunit -lm -lpthread -lrt
	D_OS = -D __My_Linux__
else
	LIBS_FOR_CHECK_PCKG = -lcheck -lm -lpthread
	D_OS = -D __My_APPLE__
endif

all: build

build: clean
	-mkdir Build 
	cd Build; qmake ../SmartCalc/SmartCalc.pro
	make -C Build > /dev/null 

install: build
	-mkdir Calculator
	mv Build/SmartCalc.app Calculator

test:
	$(CC) parser/parser.c stack/stack.c Tests/Tests.c $(LIBS_FOR_CHECK_PCKG) -o test 
	./test

clean:
	rm -f *.a *.o *.so *.out $(TESTFILE) $(TESTFILE).c *.info *.gcno *.gcda leak.log *.gz
	rm -rf report
	rm -rf *.gch
	rm -rf Build
	rm -rf Coverage

gcov_report:
	gcc -c $(FLAGS) -fprofile-arcs -ftest-coverage -O0 -fPIC parser/parser.c stack/stack.c Tests/Tests.c
	gcc -fprofile-arcs -ftest-coverage -O0 -fPIC -lcheck -o coverage.o parser.o stack.o Tests.o
	./coverage.o
	gcovr -r . --html --html-details -o cov-info.html
	mkdir Coverage
	mv cov-info.* Coverage
	open Coverage/cov-info.html
	rm *.gcda *.gcno *.o 

uninstall:
	rm -rf Calculator

dist:
	tar -czf SmartCalc.install.tar.gz ./*

dvi:
	open smartcalc.html

linter:
	clang-format -n -style=google stack/*.c stack/*.h parser/*.c parser/*.h  

linter_perform:
	clang-format -i -style=google stack/*.c stack/*.h parser/*.c parser/*.h 

