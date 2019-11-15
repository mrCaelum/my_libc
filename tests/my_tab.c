/*
** EPITECH PROJECT, 2019
** my_libc tests
** File description:
** my_tab
*/

#include <criterion/criterion.h>
#include <stdlib.h>

char **my_str_split(char const *, char);

Test(my_str_split, if_null)
{
    cr_assert_null(my_str_split(NULL, 0));
}

Test(my_str_split, simple)
{
    char **tab = my_str_split("this is a test", ' ');

    cr_assert_str_eq(tab[0], "this");
    cr_assert_str_eq(tab[1], "is");
    cr_assert_str_eq(tab[2], "a");
    cr_assert_str_eq(tab[3], "test");
    cr_assert_null(tab[4]);
    for (size_t i = 0; tab[i]; ++i)
        free(tab[i]);
    free(tab);
}

Test(my_str_split, with_empty)
{
    char **tab = my_str_split("::firstname:lastname:email:", ':');

    cr_assert_str_eq(tab[0], "");
    cr_assert_str_eq(tab[1], "");
    cr_assert_str_eq(tab[2], "firstname");
    cr_assert_str_eq(tab[3], "lastname");
    cr_assert_str_eq(tab[4], "email");
    cr_assert_str_eq(tab[5], "");
    cr_assert_null(tab[6]);
    for (size_t i = 0; tab[i]; ++i)
        free(tab[i]);
    free(tab);
}