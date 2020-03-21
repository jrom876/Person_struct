/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "arrStructExample-test.check" instead.
 */

#include <check.h>

#line 1 "arrStructExample-test.check"
#include "arrStructExample.h"

struct Person
{
    char name[20];
    char subject[20];
    char grade;
    int id;
    short int age;
};

START_TEST(personstruct)
{
#line 13
    struct Person me;
    strcpy(&me, Steve());
    fail_unless(strcmp(me.name, "Steve"), "Wrong Name");

    fail_if(strcmp(me.name, "Steve"), "Right Name");
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, personstruct);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
