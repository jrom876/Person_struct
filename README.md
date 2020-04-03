# Person_check
Person_check

This project started as an interview programming challenge from a potential employer 
who gave me an hour to create a struct program in C with at least one string, one char, one int, and one short int
which would also convert all outputs to bytecode, and then write the python version for extra credit. 

This is similar to the classic struct person program that every computer science student has done 
at one time or another. So wrote the first struct Person program, then later expanded their requirements to include both C and python versions of a robust .txt object to sql converter, and started this project.

Since then (about a month ago as of this writing), the C version has evolved into a Person/array structure 
with nascent text to sql conversion code and a C Unit automated test framework. I am currently working on the sql 
conversion code.

See: https://github.com/jrom876/TestPerson for the python version of this project.

Person_check has two make files: make.mk and make-test.mk. 

The make.mk version updates all dependencies in the main directory, 
while the make-test.mk version creates executable automated tests 
which immediately run on the command line. 

To run make-test on the linux command line, use these commands:

checkmk createHuman-test.check >createHuman-test.c

make -f make-test.mk chtest

To update all dependencies, use:

make -f make.mk

or 

make -f make.mk main
