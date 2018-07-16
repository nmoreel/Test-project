/*
** test-strcpy.c for libstring in /home/nmoreel/Documents/workshop_TUs/lib/libstring/tests/src
**
** Made by Nicolas MOREEL
** Login   <nicolas1.moreel-lebon@epitech.eu>
**
** Started on  Tue Apr 10 13:47:53 2018 Nicolas MOREEL
** Last update Fri Jun 28 11:03:05 2018 Nicolas MOREEL
*/

#include    <criterion/criterion.h>

char*       my_strcpy(char*, const char*);

Test(my_strcpy, normal_test_case)
{
    char string[42];

    cr_expect_str_eq(my_strcpy(string, "Hello world"), "Hello world");
}

Test(my_strcpy, other_test_case)
{
    char string[42];

    cr_expect_str_eq(my_strcpy(string, "Epitech is cool"), "Epitech is cool");
    cr_expect_str_eq(my_strcpy(string, ""), "");
}

Test(my_strcpy, dest_is_null)
{
    cr_expect_null(my_strcpy(NULL, "Epitech is cool"));
}

Test(my_strcpy, src_is_null)
{
    char string[42];

    cr_expect_not_null(my_strcpy(string, NULL));
}