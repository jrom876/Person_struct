# Person_struct
Person_struct

This project started as an interview programming challenge from a potential employer 
who gave me an hour to write and test a program in C that creates a struct with at least one string, one char, one int, and one short int
which would also convert all outputs to bytecode, and then write the python version for extra credit. 

This is similar to the classic struct person program that every computer science student has done 
at one time or another. 

Since then the C version has evolved into a Person/array structure 
with C Unit automated tests and the beginnings of a text object to sql converter. 

See: https://github.com/jrom876/Test_Person for the python version of this project.

Person_check has two make files: make.mk and make-test.mk. 

The make.mk version updates all dependencies in the main directory. 

To update all dependencies, use:

make -f make.mk

or 

make -f make.mk main


The make-test.mk version creates executable automated tests which immediately run on the command line. 

To run make-test on the linux command line, use:

checkmk createHuman-test.check >createHuman-test.c

make -f make-test.mk chtest

