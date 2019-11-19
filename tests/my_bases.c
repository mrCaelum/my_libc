/*
** EPITECH PROJECT, 2019
** my_libc tests
** File description:
** my_bases
*/

#include <criterion/criterion.h>
#include <stdlib.h>

char *my_tobase(unsigned int, char const *);

Test(my_tobase, if_null)
{
    cr_assert_null(my_tobase(4, NULL));
}

Test(my_tobase, if_empty)
{
    cr_assert_null(my_tobase(31, ""));
}

Test(my_tobase, simple_decimal)
{
    char *str = my_tobase(123456, "0123456789");

    cr_assert_str_eq(str, "123456");
    free(str);
}

Test(my_tobase, simple_binaire)
{
    char *str = my_tobase(54, "01");

    cr_assert_str_eq(str, "110110");
    free(str);
}

Test(my_tobase, simple_hexa)
{
    char *str = my_tobase(4652, "0123456789ABCDEF");

    cr_assert_str_eq(str, "122C");
    free(str);
}

Test(my_tobase, simple_hexa2)
{
    char *str = my_tobase(123456, "0123456789abcdef");

    cr_assert_str_eq(str, "1e240");
    free(str);
}

Test(my_tobase, with_special_chars)
{
    char *str = my_tobase(54, "@!");

    cr_assert_str_eq(str, "!!@!!@");
    free(str);
}