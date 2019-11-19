/*
** EPITECH PROJECT, 2019
** my_libc
** File description:
** my_strcmp
*/

#include <stdbool.h>
#include <stdlib.h>

bool my_strcmp(char const *str1, char const *str2)
{
    if (!str1 && !str2)
        return (true);
    else if (!str1 || !str2)
        return (false);
    for (; *str1 && *str1 == *str2; ++str1, ++str2);
    return (*str1 == *str2);
}

bool my_strncmp(char const *str1, char const *str2, size_t n)
{
    size_t i;

    if (!str1 && !str2)
        return (true);
    else if (!str1 || !str2)
        return (false);
    for (i = 0; str1[i] && str1[i] == str2[i] && i < n; ++i);
    if (i >= n)
        --i;
    return (str1[i] == str2[i]);
}

bool my_strcontains(char const *str, char i)
{
    if (!str)
        return (false);
    for (; *str; ++str)
        if (*str == i)
            return (true);
    return (false);
}