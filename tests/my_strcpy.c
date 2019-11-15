/*
** EPITECH PROJECT, 2019
** my_libc tests
** File description:
** my_strcpy
*/

#include <criterion/criterion.h>
#include <stdlib.h>

char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, size_t);

Test(my_strcpy, if_null)
{
    cr_assert_null(my_strcpy(NULL, NULL));
}

Test(my_strcpy, simple)
{
    char *str = malloc(14);

    str = my_strcpy(str, "Hello world !");
    cr_assert_str_eq(str, "Hello world !");
    free(str);
}

Test(my_strncpy, if_null)
{
    cr_assert_null(my_strncpy(NULL, NULL, 0));
}

Test(my_strncpy, simple)
{
    char *str = malloc(6);

    str = my_strncpy(str, "Hello world !", 5);
    cr_assert_str_eq(str, "Hello");
    free(str);
}

Test(my_strncpy, greater)
{
    char *str = malloc(11);

    str = my_strncpy(str, "OK", 10);
    cr_assert_str_eq(str, "OK");
    free(str);
}