/*
** EPITECH PROJECT, 2019
** my_libc tests
** File description:
** my_strlen
*/

#include <criterion/criterion.h>
#include <stdlib.h>

size_t my_strlen(char const *);
size_t my_cstrlen(char const *, char);

Test(my_strlen, if_null)
{
    cr_assert_not(my_strlen(NULL));
}

Test(my_strlen, simple)
{
    cr_assert_eq(my_strlen("Hello world !"), 13);
}

Test(my_cstrlen, if_null)
{
    cr_assert_not(my_cstrlen(NULL, 0));
}

Test(my_cstrlen, simple)
{
    cr_assert_eq(my_cstrlen("Hello world !", 'w'), 6);
}