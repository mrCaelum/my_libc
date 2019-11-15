/*
** EPITECH PROJECT, 2019
** libs
** File description:
** my_strdup
*/

#include "my_libc.h"

char *my_strdup(char const *str)
{
    char *new;
    size_t len;

    if (!str)
        return (NULL);
    len = my_strlen(str);
    new = malloc(len + 1);
    if (!new)
        return (NULL);
    my_strcpy(new, str);
    return (new);
}

char *my_strndup(char const *str, size_t n)
{
    char *new;
    size_t len;

    if (!str)
        return (NULL);
    len = my_strlen(str);
    if (len > n)
        len = n;
    new = malloc(len + 1);
    if (!new)
        return (NULL);
    my_strncpy(new, str, len);
    return (new);
}