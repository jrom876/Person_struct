
#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "createHuman.h"

// use these commands:
// 1) checkmk createHuman-test.check >createHuman-test.c
// Complile with:
// gcc test.c -Wall -o test -lcheck -lcheck_pic -pthread -lrt -lm -lsubunit
// To complie an executable test file from the .c and -test.c files:
// 2) gcc -Wall -o createHuman-test createHuman.c createHuman-test.c -lcheck -lm -lpthread -lrt -lsubunit -lcheck_pic
// To make and run a custom *.check test:
// 3) make -f make-test.mk test
// 4) make -f make.mk

/////////////////////////////////////////////
// == info about the gcc -Wall option flag ==
// gcc -Wall enables all compiler's warning messages.
// This option should always be used, in order to generate better code.
// Syntax: gcc -Wall [options] [source files] [object files] [-o output file]

struct Person
{
    char fname[20];
    char lname[20];
    char pword[20];
    char grade;
    int id;
    int age;
};

// Functions

    struct Person createHuman(char fname[20], char lname[20], char pword[20], char grade, int id, int age)
    {
      struct Person dave;
      strcpy(dave.fname,fname);
      strcpy(dave.lname,lname);
      strcpy(dave.pword,pword);
      dave.grade = grade;
      dave.id = id;
      dave.age = age;
      printf("Printing %s's details\n",dave.fname);
      printf("fname: %s \tlname: %s \tpword: %s \tGrade: %c \tID: %d \tAge: %d\n", dave.fname,dave.lname,dave.pword,dave.grade,dave.id,dave.age);

      return dave;
    }

    void convHuman2bytecode(struct Person per)
    {
      unsigned char *buffer=(unsigned char*)malloc(sizeof(struct Person));
      int i = 0;
      memcpy(buffer,(const unsigned char*)&per,sizeof(per));
      printf("\nCopied byte array for %s is:\n",per.fname);
      for(i=0;i<sizeof(per);i++)
        printf("%02X ",buffer[i]);
      printf("\n\n");
      free(buffer);
    }

    // int verifyPW(){
    // // int verifyPW(char *fn, char *ln, char *pw){
    //   int result = 0;
    //   FILE *fp = fopen("humanlist.txt", "a");
    //   fprintf(fp, "This is testing for fprintf...\n");
    //   fputs("This is testing for fputs...\n", fp);
    //   fclose(fp);
    //   return result;
    // }

    // int main()
    // {
    //     struct Person dude = createHuman("Yari","Art","Y",'A',2023,45);
    //     convHuman2bytecode(dude);
    //     //verifyPW();
    //     // createHuman("Dave","Art",'A',2001,34);
    //     convHuman2bytecode(createHuman("Dave","Art","Y",'A',2001,34));
    //     return 0;
    // }
