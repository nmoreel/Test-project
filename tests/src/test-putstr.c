/*
** test_putstr.c for workshop_tu in /home/nmoreel/documents/workshop_TUs/tests/src
**
** Made by Nicolas MOREEL
** Login   <nicolas1.moreel-lebon@epitech.eu>
**
** Started on  Thu Jun 21 15:56:18 2018 Nicolas MOREEL
** Last update Thu Jun 21 15:56:18 2018 Nicolas MOREEL
*/

#include <criterion/criterion.h>

int     my_putstr(const char*);

Test(putstr, first_test)
{
    cr_assert(my_putstr("Hello World\n") == 14);
}
