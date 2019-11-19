/*
** EPITECH PROJECT, 2019
** my_libc tests
** File description:
** my_math
*/

#include <criterion/criterion.h>
#include <stdlib.h>

size_t my_power(size_t, size_t);

Test(my_power, if_not)
{
    cr_assert_eq(my_power(0, 0), 1);
}

Test(my_power, if_not_y)
{
    cr_assert_eq(my_power(5, 0), 1);
}

Test(my_power, if_not_x)
{
    cr_assert_eq(my_power(0, 3), 0);
}

Test(my_power, simple)
{
    cr_assert_eq(my_power(5, 6), 15625);
}