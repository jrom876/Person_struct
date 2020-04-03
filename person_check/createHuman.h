// createHuman.h

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person createHuman(char fname[20], char lname[20], char pword[20], char grade, int id, int age);
void convHuman2bytecode(struct Person per);
//void convHumanArr2bytecode(struct Person *parr, int asize);
//struct Person createPerson(char *n, char *s, char g, int d, int a);
