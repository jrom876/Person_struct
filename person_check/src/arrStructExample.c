
#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrStructExample.h"

// use this command:
// 1) checkmk arrStructExample-test.check >arrStructExample-test.c
// complile with:
// gcc test.c -Wall -o test -lcheck -lcheck_pic -pthread -lrt -lm -lsubunit
// 2) gcc -Wall -o arrStructExample-test arrStructExample.c arrStructExample-test.c -lcheck -lm -lpthread -lrt -lsubunit -lcheck_pic
// 3) make -f make.mk test

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

// Global Variables
    // struct Person parray[] = {};
    // int arrSize = 0;

// Functions
    struct Person createSteve(){
      // struct Person steve = (struct)malloc(sizeof(struct Person));
      struct Person steve = {"Steve","Art 202",'A',2007,25};
      return steve;
    }

    struct Person createDave(){
      struct Person dave = {.name = "Dave",.subject = "Art 202",.grade = 'B',.id = 2005,.age = 27};
      return dave;
    }

    struct Person createPerson()
    {
      struct Person thisPerson;
      printf("Enter the name, subject, grade, id, and age of person \n");
      scanf("%s %s %c %d %hi",thisPerson.name,thisPerson.subject,&thisPerson.grade,&thisPerson.id,&thisPerson.age);
      printf("Printing the person's details\n");
      printf("Name: %s \tSubject: %s \tGrade: %c \tID: %d \tAge: %hi\n", thisPerson.name,thisPerson.subject,thisPerson.grade,thisPerson.id,thisPerson.age);
      return thisPerson;
    }

    struct Person *createPersonArray(int size)
    {
      int arrSize = size;
      printf("How many people are we creating today? \n");
      scanf("%i",&arrSize);
      struct Person parray[arrSize];
      char buffer[arrSize];

      for (int ii=0; ii < arrSize; ii++)
      {
        struct Person parray[ii];
        printf("Enter the name, subject, grade, id, and age of person %d \n", ii+1);
        scanf("%s %s %c %d %hi",parray[ii].name,parray[ii].subject,&parray[ii].grade,&parray[ii].id,&parray[ii].age);
        printf("Printing the person's details\n");
        printf("Name: %s \tSubject: %s \tGrade: %c \tID: %d \tAge: %hi\n", parray[ii].name,parray[ii].subject,parray[ii].grade,parray[ii].id,parray[ii].age);

      }
      return parray;
    }

    void convPer2bytecode(struct Person per)
    {
      unsigned char *buffer=(char*)malloc(sizeof(struct Person));
      int i = 0;
      memcpy(buffer,(const unsigned char*)&per,sizeof(per));
      printf("\nCopied byte array for %s is:\n",per.name);
      for(i=0;i<sizeof(per);i++)
        printf("%02X ",buffer[i]);
      printf("\n\n");
      free(buffer);
    }

    void convPerArr2bytecode(struct Person *parr, int asize)
    {
      int j = 0;
      for (j=0; j < asize; j++)
      {
        unsigned char *arrbuffer=(char*)malloc(sizeof(parr));
        int i = 0;
        memcpy(arrbuffer,(const unsigned char*)&parr[j],sizeof(parr[j]));
        printf("\nCopied byte array for %s is:\n",parr[j].name);
        for(i=0;i<sizeof(parr[j]);i++)
          printf("%02X ",arrbuffer[i]);
        printf("\n\n");
        free(arrbuffer);
      }
    }

    // int main()
    // {
    //     // struct Person dude = createPerson();
    //     // convPer2bytecode(dude);
    //     convPer2bytecode(Steve());
    //     convPer2bytecode(Dave());
    //
    //     // struct Person *students = createPersonArray(2);
    //     // convPerArr2bytecode(students,2);
    //
    //     return 0;
    // }

// // Stable byte array converter code. Do not erase!!
//         //declare character buffer (byte array)
//         unsigned char *buffer0=(char*)malloc(sizeof(parray));
//         int k;
//         //copying parray to buffer byte array object
//         memcpy(buffer0,(const unsigned char*)&parray,sizeof(parray));
//         // //printing buffer byte array object to screen
//         printf("Copied byte array is:\n");
//         for(k=0;k<sizeof(parray);k++)
//           printf("%02X ",buffer0[k]);
//         printf("\n");
//         // //freeing memory
//         free(buffer0);
// // End of stable byte array converter code
