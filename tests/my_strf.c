/*
** EPITECH PROJECT, 2019
** my_libc tests
** File description:
** my_strf
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "my_strf.h"

char *my_strf(char const *, ...);

Test(my_strf, if_null)
{
    cr_assert_null(my_strf(NULL));
}

Test(my_strf, simple)
{
    char *str = my_strf("Hello world !");

    cr_assert_str_eq(str, "Hello world !");
    free(str);
}

Test(my_strf, simple_decimal)
{
    char *str = my_strf("Decimal : %d :)", 31);

    cr_assert_str_eq(str, "Decimal : 31 :)");
    free(str);
}

Test(my_strf, negative_decimal)
{
    char *str = my_strf(": %d : negative", -12345);

    cr_assert_str_eq(str, ": -12345 : negative");
    free(str);
}

Test(my_strf, simple_integer)
{
    char *str = my_strf("Integer : %i :)", 15);

    cr_assert_str_eq(str, "Integer : 15 :)");
    free(str);
}

Test(my_strf, negative_integer)
{
    char *str = my_strf(": %i : negative", -44);

    cr_assert_str_eq(str, ": -44 : negative");
    free(str);
}

Test(my_strf, simple_char)
{
    char *str = my_strf("He%cl%c !", 'l', 'o');

    cr_assert_str_eq(str, "Hello !");
    free(str);
}

Test(my_strf, simple_str)
{
    char *str = my_strf("He%s !", "llo");

    cr_assert_str_eq(str, "Hello !");
    free(str);
}

Test(my_strf, str_begin)
{
    char *str = my_strf("%s OK", "test");

    cr_assert_str_eq(str, "test OK");
    free(str);
}

Test(my_strf, advenced_expr)
{
    char *str = my_strf("%c%s%d!%c%d%s", 'H', "ey ", 12, ' ', 901, " *-*");

    cr_assert_str_eq(str, "Hey 12! 901 *-*");
    free(str);
}

Test(my_strf, one_percent)
{
    char *str = my_strf("test % test");

    cr_assert_str_eq(str, "test % test");
    free(str);
}

Test(my_strf, two_percent)
{
    char *str = my_strf("test %% test");

    cr_assert_str_eq(str, "test % test");
    free(str);
}