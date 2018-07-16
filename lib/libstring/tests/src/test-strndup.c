/*
** test-strndup.c for workshop_tus in /home/nmoreel/documents/workshop_TUs/lib/libstring/tests/src
**
** Made by Nicolas MOREEL
** Login   <nicolas1.moreel-lebon@epitech.eu>
**
** Started on  Thu Jun 28 14:29:09 2018 Nicolas MOREEL
** Last update Fri Jun 28 14:34:17 2018 Nicolas MOREEL
*/

#include    <criterion/criterion.h>
#include    "mimick.h"

char*   my_strndup(const char*, size_t);

Test(my_strndup, normal_test_case)
{
    char* str;

    str = my_strndup("Hello World", 5);
    cr_assert_not_null(str);
    cr_expect_str_eq(str, "Hello");
}

mmk_mock_define(mock_malloc, void*, size_t);

Test(my_strndup, malloc_faillure)
{
    mock_malloc mock = mmk_mock("malloc@self", mock_malloc);
    char* str;
    void *result = NULL;

    mmk_mock("malloc@self", mock_malloc);
    mmk_when(mock(mmk_any(size_t)),
        .then_return = &result,
        .then_errno = ENOMEM);

    str = my_strndup("Epitec c\'est cool", 7);
    cr_assert_null(str);

    mmk_reset(mock);
}

Test(my_strndup, src_is_null)
{
    char* str;

    str = my_strndup(NULL, 5);
    cr_expect_null(str);
}