# Person_check
Person_check

This repository is a Person structure with a C Unit automated test framework.

This project started as an interview programming challenge from a potential employer 
who gave me an hour to create a person struct program in C which could also 
convert all class attributes to bytecode, and then write the python version for extra credit.

See https://github.com/jrom876/arrStructExample/arrStructExample.c for the early C version.

Please also see: https://github.com/jrom876/TestPerson for the ongiong python version of this project.

Its data structure and basic functionality are defined in personExample.c and personExample.h. 

The createHuman branch is used to develop and test new features such as passwords.

It has two make files, make.mk and make-test.mk. The make.mk version updates all dependencies in the main directory, 
while the make-test.mk version creates executable automated tests which immediately run on the command line. 

To run make-test on the linux command line, use these commands:

checkmk personExample-test.check >personExample-test.c

make -f make-test.mk pstest

or

make -f make-test.mk chtest

To update all dependencies, use:

make -f make.mk

or 

make -f make.mk main
