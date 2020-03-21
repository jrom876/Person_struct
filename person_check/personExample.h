#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct Person createHuman();
struct Person createHuman(char name[20], char subject[20], char grade, int id, short int age);
struct Person createPerson();
struct Person *createPersonArray();
void convPer2bytecode(struct Person per);
void convPerArr2bytecode(struct Person *parr, int asize);
//struct Person createPerson(char *n, char *s, char g, int d, short int a);
