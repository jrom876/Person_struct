#************************************************************************
#  Makefile file for project arrStructExample
#************************************************************************

#
# Compiler flags
#
CC=gcc
CFLAGS=-Wall -g
#
# Debug build settings
#
DEBUG=-g
LIBS=-lcheck -lm -lpthread -lrt -lsubunit -lcheck_pic

all: personstruct #mult2ints fizzbuzz

personstruct: main.o arrStructExample.o
	$(CC) -o personstruct main.o arrStructExample.o

# mult2ints: main.o implementation.o
# 	$(CC) -o mult2ints main.o implementation.o

# fizzbuzz: main.o implementation.o
# 	$(CC) -o fizzbuzz main.o implementation.o

main.o: main.c arrStructExample.h
	$(CC) $(CFLAGS) -c main.c

arrStructExample.o: arrStructExample.c arrStructExample.h
	$(CC) $(CFLAGS) -c arrStructExample.c

test: personstruct-test
	./personstruct-test

personstruct-test: arrStructExample-test.o arrStructExample.o
	$(CC) -o personstruct-test arrStructExample.o arrStructExample-test.o $(LIBS)

# mult2ints-test: implementation-test.o implementation.o
# 	$(CC) -o mult2ints-test implementation.o implementation-test.o $(LIBS)

# fizzbuzz-test: implementation-test.o implementation.o
# 	$(CC) -o fizzbuzz-test implementation.o implementation-test.o $(LIBS)

arrStructExample-test.o: arrStructExample-test.c arrStructExample.h
	$(CC) $(CFLAGS) -c arrStructExample-test.c

clean:
	rm main main.o arrStructExample.o arrStructExample-test.o
