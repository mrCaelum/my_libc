/*
** EPITECH PROJECT, 2019
** my_libc tests
** File description:
** my_stradd
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>

char *my_stradd(char *, char const *);
char *my_strnadd(char *, char const *, size_t);
char *my_addnchar(char *, char, size_t);

Test(my_stradd, if_null)
{
    cr_assert_null(my_stradd(NULL, NULL));
}

Test(my_stradd, first_null)
{
    char *str = my_stradd(NULL, "OK");

    cr_assert_str_eq(str, "OK");
    free(str);
}

Test(my_stradd, simple)
{
    char *str = my_stradd(strdup("test"), "OK");

    cr_assert_str_eq(str, "testOK");
    free(str);
}

Test(my_strnadd, if_null)
{
    cr_assert_null(my_strnadd(NULL, NULL, 0));
}

Test(my_strnadd, simple)
{
    char *str = my_strnadd(strdup("test"), "OKornot", 2);

    cr_assert_str_eq(str, "testOK");
    free(str);
}

Test(my_strnadd, greater)
{
    char *str = my_strnadd(strdup("test"), "OK", 10);

    cr_assert_str_eq(str, "testOK");
    free(str);
}

Test(my_addnchar, if_not)
{
    char *str = my_addnchar(strdup("test ok"), 'x', 0);

    cr_assert_str_eq(str, "test ok");
    free(str);
}

Test(my_addnchar, simple)
{
    char *str = my_addnchar(strdup("test o"), 'k', 5);

    cr_assert_str_eq(str, "test okkkkk");
    free(str);
}