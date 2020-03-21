#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person createPerson();
struct Person *createPersonArray();
void convPer2bytecode(struct Person per);
void convPerArr2bytecode(struct Person *parr, int asize);
