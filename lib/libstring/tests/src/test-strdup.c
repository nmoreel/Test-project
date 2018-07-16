/*
** test-strdup.c for libstring in /home/nmoreel/Documents/workshop_TUs/lib/libstring/tests/src
**
** Made by Nicolas MOREEL
** Login   <nicolas1.moreel-lebon@epitech.eu>
**
** Started on  Tue Apr 10 14:09:20 2018 Nicolas MOREEL
** Last update Fri Jun 7 17:24:27 2018 Nicolas MOREEL
*/

#include    <criterion/criterion.h>
#include    "mimick.h"

char*   my_strdup(const char*);

Test(my_strdup, normal_test_case)
{
    char* str;

    str = my_strdup("Hello World");
    cr_assert_not_null(str);
    cr_expect_str_eq(str, "Hello World");
}

mmk_mock_define(mock_malloc, void*, size_t);

Test(my_strdup, malloc_faillure)
{
    mock_malloc mock = mmk_mock("malloc@self", mock_malloc);
    char* str;
    void *result = NULL;

    mmk_mock("malloc@self", mock_malloc);
    mmk_when(mock(mmk_any(size_t)),
        .then_return = &result,
        .then_errno = ENOMEM);

    str = my_strdup("Hello World");
    cr_assert_null(str);

    mmk_reset(mock);
}