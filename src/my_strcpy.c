/*
** EPITECH PROJECT, 2019
** libs
** File description:
** my_strcpy
*/

#include "my_libc.h"

char *my_strcpy(char *dest, char const *src)
{
    size_t i;

    if (!dest || !src)
        return (0);
    for (i = 0; src[i]; ++i)
        dest[i] = src[i];
    dest[i] = 0;
    return (dest);
}

char *my_strncpy(char *dest, char const *src, size_t n)
{
    size_t i;

    if (!dest || !src)
        return (0);
    for (i = 0; src[i] && i < n; ++i)
        dest[i] = src[i];
    dest[i] = 0;
    return (dest);
}