#************************************************************************
#  Makefile for project createHuman
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

all: createHuman

main: main.o
	./main

main.o: main.c createHuman.h
	$(CC) $(CFLAGS) -c main.c

createHuman: main.o createHuman.o createHuman.o
	$(CC) -o createHuman main.o createHuman.o

createHuman.o: createHuman.c createHuman.h
	$(CC) $(CFLAGS) -c createHuman.c

chtest: createHuman-test
	./createHuman-test

createHuman-test: createHuman-test.o createHuman.o
	$(CC) -o createHuman-test createHuman.o createHuman-test.o $(LIBS)

## clean != working right now
clean:
	rm main main.o createHuman.o createHuman-test.o
