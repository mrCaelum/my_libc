/*
** EPITECH PROJECT, 2019
** my_libc
** File description:
** my_strcat
*/

#include "my_libc.h"

char *my_strcat(char const *str1, char const *str2)
{
    char *new;
    size_t len = my_strlen(str1);

    if (!str1 && !str2)
        return (NULL);
    if (!str1)
        return (my_strdup(str2));
    if (!str2)
        return (my_strdup(str1));
    new = malloc(len + my_strlen(str2) + 1);
    my_strcpy(new, str1);
    my_strcpy(new + len, str2);
    return (new);
}