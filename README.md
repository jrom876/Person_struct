# Person_struct
Person_struct

This project is basically the classic struct person program that every computer science student has done 
at one time or another. 

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

