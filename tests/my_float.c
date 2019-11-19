/*
** EPITECH PROJECT, 2019
** my_libc tests
** File description:
** my_float
*/

#include <criterion/criterion.h>
#include <stdlib.h>

double my_atof(char const *);
char *my_ftoa(double, size_t);

Test(my_ftoa, if_not)
{
    char *str = my_ftoa(0, 3);

    cr_assert_str_eq(str, "0.000");
    free(str);
}

Test(my_ftoa, simple)
{
    char *str = my_ftoa(123.12345, 5);

    cr_assert_str_eq(str, "123.12345");
    free(str);
}

Test(my_ftoa, negative)
{
    char *str = my_ftoa(-43.5, 3);

    cr_assert_str_eq(str, "-43.500");
    free(str);
}

Test(my_atof, if_invalid)
{
    cr_assert_eq(my_atof("invalid"), 0);
}

Test(my_atof, if_invalid2)
{
    cr_assert_eq(my_atof("0.invalid"), 0);
}

Test(my_atof, if_invalid3)
{
    cr_assert_eq(my_atof("0."), 0);
}

Test(my_atof, if_not)
{
    cr_assert_eq(my_atof("0"), 0);
}

Test(my_atof, simple)
{
    cr_assert_eq(my_atof("123.123"), 123.123);
}

Test(my_atof, integer)
{
    cr_assert_eq(my_atof("123"), 123);
}

Test(my_atof, decimal)
{
    cr_assert_eq(my_atof("0.456"), 0.456);
}

Test(my_atof, negative)
{
    cr_assert_eq(my_atof("-123.456"), -123.456);
}