#************************************************************************
#  Makefile for project personExample
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

all: personstruct createPerson1 createHuman pstruct

main: main.o
	./main

personstruct: main.o personstruct.o personExample.o
	$(CC) -o personstruct main.o personExample.o

createPerson1: main.o createPerson1.o personExample.o
	$(CC) -o createPerson1 main.o createPerson1.o

createHuman: main.o createHuman.o personExample.o
	$(CC) -o createHuman main.o personExample.o

pstruct: main.o pstruct.o personExample.o
	$(CC) -o pstruct main.o personExample.o

main.o: main.c personExample.h
	$(CC) $(CFLAGS) -c main.c

personExample.o: personExample.c personExample.h
	$(CC) $(CFLAGS) -c personExample.c

pstest: personstruct-test
	./personstruct-test

cp1test: createPerson1-test
	./createPerson1-test

chtest: createHuman-test
	./createHuman-test

personstruct-test: personExample-test.o personExample.o
	$(CC) -o personstruct-test personExample.o personExample-test.o $(LIBS)

createPerson1-test: createPerson1-test.o createPerson1.o
	$(CC) -o createPerson1-test personExample.o createPerson1-test.o $(LIBS)

createHuman-test: createHuman-test.o createHuman.o
	$(CC) -o createHuman-test personExample.o createHuman-test.o $(LIBS)

pstruct-test: personExample-test.o personExample.o
	$(CC) -o pstruct-test personExample.o personExample-test.o $(LIBS)

personExample-test.o: personExample-test.c personExample.h
	$(CC) $(CFLAGS) -c personExample-test.c

clean:
	rm main main.o personExample.o personExample-test.o
