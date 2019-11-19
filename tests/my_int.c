/*
** EPITECH PROJECT, 2019
** my_libc tests
** File description:
** my_int
*/

#include <criterion/criterion.h>
#include <stdlib.h>

int my_atoi(char const *);
char *my_itoa(int);
size_t my_atou(char const *);
char *my_utoa(size_t);

Test(my_atoi, if_null)
{
    cr_assert_not(my_atoi(NULL));
}

Test(my_atoi, positive_number)
{
    cr_assert_eq(my_atoi("12"), 12);
}

Test(my_atoi, negative_number)
{
    cr_assert_eq(my_atoi("-132"), -132);
}

Test(my_atoi, invalid)
{
    cr_assert_eq(my_atoi("Hello"), 0);
}

Test(my_itoa, if_not)
{
    char *str = my_itoa(0);

    cr_assert_str_eq(str, "0");
    free(str);
}

Test(my_itoa, simple)
{
    char *str = my_itoa(12);

    cr_assert_str_eq(str, "12");
    free(str);
}

Test(my_itoa, negative_number)
{
    char *str = my_itoa(-123);

    cr_assert_str_eq(str, "-123");
    free(str);
}

Test(my_itoa, big_number)
{
    char *str = my_itoa(123456);

    cr_assert_str_eq(str, "123456");
    free(str);
}

Test(my_atou, if_null)
{
    cr_assert_not(my_atou(NULL));
}

Test(my_atou, positive_number)
{
    cr_assert_eq(my_atou("12"), 12);
}

Test(my_atou, big_number)
{
    cr_assert_eq(my_atou("125364"), 125364);
}

Test(my_atou, invalid)
{
    cr_assert_eq(my_atou("Hello"), 0);
}

Test(my_utoa, if_not)
{
    char *str = my_utoa(0);

    cr_assert_str_eq(str, "0");
    free(str);
}

Test(my_utoa, simple)
{
    char *str = my_utoa(12);

    cr_assert_str_eq(str, "12");
    free(str);
}

Test(my_utoa, big_number)
{
    char *str = my_utoa(123456);

    cr_assert_str_eq(str, "123456");
    free(str);
}