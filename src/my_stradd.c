/*
** EPITECH PROJECT, 2019
** libs
** File description:
** my_stradd
*/

#include "my_libc.h"

char *my_stradd(char *str1, char const *str2)
{
    char *new;
    size_t len1 = my_strlen(str1);
    size_t len2 = my_strlen(str2);

    if (!str2)
        return (str1);
    if (!str1)
        return (my_strdup(str2));
    new = malloc(len1 + len2 + 1);
    if (!new)
        return (NULL);
    my_strcpy(new, str1);
    my_strcpy(new + len1, str2);
    new[len1 + len2] = 0;
    free(str1);
    return (new);
}

char *my_strnadd(char *str1, char const *str2, size_t n)
{
    char *new;
    size_t len1 = my_strlen(str1);
    size_t len2 = my_strlen(str2);

    if (!str2 || !n)
        return (str1);
    if (!str1)
        return (my_strndup(str2, n));
    if (len2 > n)
        len2 = n;
    new = malloc(len1 + len2 + 1);
    if (!new)
        return (NULL);
    my_strcpy(new, str1);
    my_strncpy(new + len1, str2, n);
    new[len1 + len2] = 0;
    free(str1);
    return (new);
}