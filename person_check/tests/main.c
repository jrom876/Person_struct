
#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrStructExample.h"


    struct Person
    {
        char name[20];
        char subject[20];
        char grade;
        int id;
        short int age;
    };

    int main()
    {
        // struct Person dude = createPerson();
        // convPer2bytecode(dude);
        struct Person king = createPerson();
        // createDave("Dave","Art",'A',2001,34);
        // convPer2bytecode(createPerson());
        // struct Person *students = createPersonArray(2);
        // convPerArr2bytecode(students,2);

        return 0;
    }
