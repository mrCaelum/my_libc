/*
** EPITECH PROJECT, 2019
** my_libc tests
** File description:
** my_strdup
*/

#include <criterion/criterion.h>
#include <stdlib.h>

char *my_strdup(char const *);
char *my_strndup(char const *, size_t);

Test(my_strdup, if_null)
{
    cr_assert_null(my_strdup(NULL));
}

Test(my_strdup, simple)
{
    char *str = my_strdup("OK");

    cr_assert_str_eq(str, "OK");
    free(str);
}

Test(my_strndup, if_null)
{
    cr_assert_null(my_strndup(NULL, 0));
}

Test(my_strndup, simple)
{
    char *str = my_strndup("OKornot", 2);

    cr_assert_str_eq(str, "OK");
    free(str);
}

Test(my_strndup, greater)
{
    char *str = my_strndup("OK", 10);

    cr_assert_str_eq(str, "OK");
    free(str);
}