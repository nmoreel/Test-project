/*
** test-strncpy.c for libstring in /home/nmoreel/Documents/workshop_TUs/lib/libstring/tests/src
**
** Made by Nicolas MOREEL
** Login   <nicolas1.moreel-lebon@epitech.eu>
**
** Started on  Tue Apr 10 13:47:53 2018 Nicolas MOREEL
** Last update Fri Jun 28 11:07:55 2018 Nicolas MOREEL
*/

#include    <criterion/criterion.h>

char*       my_strncpy(char*, const char*, size_t);

Test(my_strncpy, normal_test_case)
{
    char string[42];

    cr_expect_str_eq(my_strncpy(string, "Hello world", 5), "Hello");
}

Test(my_strncpy, other_test_case)
{
    char string[42];

    cr_expect_str_eq(my_strncpy(string, "Epitech is cool", 7), "Epitech");
    cr_expect_str_eq(my_strncpy(string, "", 0), "");
}

Test(my_strncpy, dest_is_null)
{
    cr_expect_null(my_strncpy(NULL, "Epitech is cool", 7));
}

Test(my_strncpy, src_is_null)
{
    char string[42];

    cr_expect_not_null(my_strncpy(string, NULL, 0));
}