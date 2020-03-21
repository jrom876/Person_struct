
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

// Global Variables
    struct Person *parray;
    // int arrSize = 0;

// Functions

    struct Person createHuman(char name[20], char subject[20], char grade, int id, short int age)
    {
      struct Person dave;
      strcpy(dave.name,name);
      strcpy(dave.subject,subject);
      dave.grade = grade;
      dave.id = id;
      dave.age = age;
      printf("Printing Dave's details\n");
      printf("Name: %s \tSubject: %s \tGrade: %c \tID: %d \tAge: %hi\n", dave.name,dave.subject,dave.grade,dave.id,dave.age);

      return dave;
    }

    struct Person createPerson()
    {
      struct Person thisPerson;
      char n[20] = "Yari";
      char s[20]  = "CS";
      char g = 'A';
      int d = 2007;
      short int a = 27;
      strcpy(thisPerson.name,n);
      strcpy(thisPerson.subject,s);
      thisPerson.grade = g;
      thisPerson.id = d;
      thisPerson.age = a;
      // printf("Enter the name, subject, grade, id, and age of person \n");
      // scanf("%s %s %c %d %hi",thisPerson.name,thisPerson.subject,&thisPerson.grade,&thisPerson.id,&thisPerson.age);
      printf("Printing the person's details\n");
      printf("Name: %s \tSubject: %s \tGrade: %c \tID: %d \tAge: %hi\n", thisPerson.name,thisPerson.subject,thisPerson.grade,thisPerson.id,thisPerson.age);
      return thisPerson;
    }

    // global: struct Person *parray;
    struct Person *createPersonArray(int size)
    {
      int arrSize = size;
      printf("How many people are we creating today? \n");
      scanf("%i",&arrSize);

      for (int ii=0; ii < arrSize; ii++)
      {
        printf("Enter the name, subject, grade, id, and age of person %d \n", ii+1);
        scanf("%s %s %c %d %hi",parray[ii].name,parray[ii].subject,&parray[ii].grade,&parray[ii].id,&parray[ii].age);
        printf("Printing the person's details\n");
        printf("Name: %s \tSubject: %s \tGrade: %c \tID: %d \tAge: %hi\n", parray[ii].name,parray[ii].subject,parray[ii].grade,parray[ii].id,parray[ii].age);
      }
      return parray;
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

    void convPerArr2bytecode(struct Person *parr, int asize)
    {
      int j = 0;
      for (j=0; j < asize; j++)
      {
        unsigned char *arrbuffer=(unsigned char*)malloc(sizeof(parr[asize]));
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
    //     // convPer2bytecode(Steve());
    //     // convPer2bytecode(Dave());
    //     // createHuman();
    //     createPerson();
    //     createHuman("Dave","Art",'A',2001,34);
    //     // convPer2bytecode(createPerson());
    //     // struct Person *students = createPersonArray(2);
    //     // convPerArr2bytecode(students,2);
    //
    //     return 0;
    // }
//////////////////////////////////////////////////
/// Construction Zone ///
    // struct Person createHuman(){
    //   struct Person dude;
    //   // struct Person steve = (struct)malloc(sizeof(struct Person));
    //   unsigned char *bufname=(char*)malloc(sizeof(dude.name));
    //   memcpy(bufname,(const unsigned char*)&dude.name,sizeof(dude.name));
    //   unsigned char *bufsub=(char*)malloc(sizeof(dude.subject));
    //   memcpy(bufsub,(const unsigned char*)&dude.subject,sizeof(dude.subject));
    //   unsigned char *bufgrade=(char*)malloc(sizeof(dude.grade));
    //   memcpy(bufgrade,(const unsigned char*)&dude.grade,sizeof(dude.grade));
    //   unsigned char *bufid=(char*)malloc(sizeof(dude.id));
    //   memcpy(bufid,(const unsigned char*)&dude.id,sizeof(dude.id));
    //   unsigned char *bufage=(char*)malloc(sizeof(dude.age));
    //   memcpy(bufage,(const unsigned char*)&dude.age,sizeof(dude.age));
    //
    //   return dude;
    // }
/// End of Construction Zone ///

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
