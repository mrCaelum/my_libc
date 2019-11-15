/*
** EPITECH PROJECT, 2019
** my_libc tests
** File description:
** my_strcat
*/

#include <criterion/criterion.h>
#include <stdlib.h>

char *my_strcat(char const *, char const *);

Test(my_strcat, if_null)
{
    cr_assert_null(my_strcat(NULL, NULL));
}

Test(my_strcat, first_null)
{
    char *str = my_strcat(NULL, "TEST");

    cr_assert_str_eq(str, "TEST");
    free(str);
}

Test(my_strcat, second_null)
{
    char *str = my_strcat("TEST", NULL);

    cr_assert_str_eq(str, "TEST");
    free(str);
}

Test(my_strcat, simple)
{
    char *str = my_strcat("test", "OK");

    cr_assert_str_eq(str, "testOK");
    free(str);
}