/*
** test-strlen.c for libstring in /home/nmoreel/Documents/workshop_TUs/lib/libstring/tests/src
**
** Made by Nicolas MOREEL
** Login   <nicolas1.moreel-lebon@epitech.eu>
**
** Started on  Tue Apr 10 13:23:34 2018 Nicolas MOREEL
** Last update Tue Apr 10 13:23:34 2018 Nicolas MOREEL
*/

#include    <criterion/criterion.h>

unsigned int my_strlen(const char*);

Test(my_strlen, normal_test_case)
{
    cr_expect_eq(my_strlen("test"), 4);
    cr_expect_eq(my_strlen("1"), 1);
    cr_expect_eq(my_strlen(""), 0);
}

Test(my_strlen, null_test_case)
{
    cr_expect_eq(my_strlen(NULL), 0);
}
