/*
** EPITECH PROJECT, 2019
** my_libc tests
** File description:
** my_strcmp
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdbool.h>

bool my_strcmp(char const *, char const *);
bool my_strncmp(char const *, char const *, size_t);
bool my_strcontains(char const *, char);

Test(my_strcmp, if_null)
{
    cr_assert(my_strcmp(NULL, NULL));
}

Test(my_strcmp, first_null)
{
    cr_assert_not(my_strcmp(NULL, "OK"));
}

Test(my_strcmp, is_true)
{
    cr_assert(my_strcmp("OK", "OK"));
}

Test(my_strcmp, is_false)
{
    cr_assert_not(my_strcmp("OK", "NO"));
}

Test(my_strcmp, longer)
{
    cr_assert_not(my_strcmp("OK", "OKornot"));
}

Test(my_strcmp, shorter)
{
    cr_assert_not(my_strcmp("OKornot", "OK"));
}

Test(my_strncmp, if_null)
{
    cr_assert(my_strncmp(NULL, NULL, 0));
}

Test(my_strncmp, first_null)
{
    cr_assert_not(my_strncmp(NULL, "OK", 10));
}

Test(my_strncmp, is_true)
{
    cr_assert(my_strncmp("OK", "OKornot", 2));
}

Test(my_strncmp, is_false)
{
    cr_assert_not(my_strncmp("OK", "OKornot", 5));
}

Test(my_strncmp, longer)
{
    cr_assert_not(my_strncmp("OK", "OKornot", 10));
}

Test(my_strncmp, shorter)
{
    cr_assert(my_strncmp("OKornot", "OK", 1));
}

Test(my_strcontains, if_null)
{
    cr_assert_not(my_strcontains(NULL, 'o'));
}

Test(my_strcontains, simple)
{
    cr_assert(my_strcontains("test", 'e'));
}

Test(my_strcontains, simple_not)
{
    cr_assert_not(my_strcontains("test", 'o'));
}