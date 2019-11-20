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

Test(my_strf, floating_point_integer)
{
    char *str = my_strf("Float : %.2i :)", 123);

    cr_assert_str_eq(str, "Float : 123.00 :)");
    free(str);
}

Test(my_strf, simple_unsigned)
{
    char *str = my_strf("Integer : %u :)", 15);

    cr_assert_str_eq(str, "Integer : 15 :)");
    free(str);
}

Test(my_strf, big_unsigned)
{
    char *str = my_strf("Integer : %u :)", 3000000000);

    cr_assert_str_eq(str, "Integer : 3000000000 :)");
    free(str);
}

Test(my_strf, floating_point_unsigned)
{
    char *str = my_strf("Float : %.3u :)", 63);

    cr_assert_str_eq(str, "Float : 63.000 :)");
    free(str);
}

Test(my_strf, simple_float)
{
    char *str = my_strf("Float : %f :)", 123.12345);

    cr_assert_str_eq(str, "Float : 123.123450 :)");
    free(str);
}

Test(my_strf, advanced_float)
{
    char *str = my_strf("Float : %.2f :)", 123.12345);

    cr_assert_str_eq(str, "Float : 123.12 :)");
    free(str);
}

Test(my_strf, sci_float)
{
    char *str = my_strf("Float : %e :)", 123.456789);

    cr_assert_str_eq(str, "Float : 1.234567e+2 :)");
    free(str);
}

Test(my_strf, sci_float2)
{
    char *str = my_strf("Float : %e :)", 0.0012345678);

    cr_assert_str_eq(str, "Float : 1.234567e-3 :)");
    free(str);
}

Test(my_strf, advanced_sci_float)
{
    char *str = my_strf("Float : %.2e :)", 0.0012345678);

    cr_assert_str_eq(str, "Float : 1.23e-3 :)");
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

Test(my_strf, hexa)
{
    char *str = my_strf("test %x OK", 123456);

    cr_assert_str_eq(str, "test 1e240 OK");
    free(str);
}

Test(my_strf, uhexa)
{
    char *str = my_strf("test %X OK", 151515);

    cr_assert_str_eq(str, "test 24FDB OK");
    free(str);
}

Test(my_strf, octal)
{
    char *str = my_strf("test %o OK", 151515);

    cr_assert_str_eq(str, "test 447733 OK");
    free(str);
}

Test(my_strf, binary)
{
    char *str = my_strf("test %b OK", 25);

    cr_assert_str_eq(str, "test 11001 OK");
    free(str);
}

Test(my_strf, pointer)
{
    int *i = (int *)123;
    char *str = my_strf("test %p OK", i);

    cr_assert_str_eq(str, "test 0x7b OK");
    free(str);
}

Test(my_strf, simple_invalid)
{
    char *str = my_strf("ARGH ! %a :(", 71);

    cr_assert_str_eq(str, "ARGH ! %a :(");
    free(str);
}

Test(my_strf, floating_point_error)
{
    char *str = my_strf("Float : %.2a :)", 123);

    cr_assert_str_eq(str, "Float : %.2a :)");
    free(str);
}