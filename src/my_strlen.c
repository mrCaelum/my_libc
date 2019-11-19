/*
** EPITECH PROJECT, 2019
** my_libc
** File description:
** my_strlen
*/

#include <stdlib.h>

size_t my_strlen(char const *str)
{
    char *tmp;

    if (!str)
        return (0);
    tmp = (char *)str;
    while (*tmp)
        ++tmp;
    return (tmp - str);
}

size_t my_cstrlen(char const *str, char endc)
{
    char *tmp;

    if (!str)
        return (0);
    tmp = (char *)str;
    while (*tmp && *tmp != endc)
        ++tmp;
    return (tmp - str);
}