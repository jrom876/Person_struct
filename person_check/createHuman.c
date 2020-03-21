
#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personExample.h"

// use these commands:
// 1) checkmk personExample-test.check >personExample-test.c
// Complile with:
// gcc test.c -Wall -o test -lcheck -lcheck_pic -pthread -lrt -lm -lsubunit
// To complie an executable test file from the .c and -test.c files:
// 2) gcc -Wall -o personExample-test personExample.c personExample-test.c -lcheck -lm -lpthread -lrt -lsubunit -lcheck_pic
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
        char name[20];
        char subject[20];
        char grade;
        int id;
        short int age;
    };

// Functions

    struct Person createHuman(char name[20], char subject[20], char grade, int id, short int age)
    {
      struct Person dave;
      strcpy(dave.name,name);
      strcpy(dave.subject,subject);
      dave.grade = grade;
      dave.id = id;
      dave.age = age;
      printf("Printing %s's details\n",dave.name);
      printf("Name: %s \tSubject: %s \tGrade: %c \tID: %d \tAge: %hi\n", dave.name,dave.subject,dave.grade,dave.id,dave.age);

      return dave;
    }

    void convPer2bytecode(struct Person per)
    {
      unsigned char *buffer=(unsigned char*)malloc(sizeof(struct Person));
      int i = 0;
      memcpy(buffer,(const unsigned char*)&per,sizeof(per));
      printf("\nCopied byte array for %s is:\n",per.name);
      for(i=0;i<sizeof(per);i++)
        printf("%02X ",buffer[i]);
      printf("\n\n");
      free(buffer);
    }

    int main()
    {
        struct Person dude = createHuman("Yari","Art",'A',2023,45);
        convPer2bytecode(dude);

        // createHuman("Dave","Art",'A',2001,34);
        convPer2bytecode(createHuman("Dave","Art",'A',2001,34));
        return 0;
    }
