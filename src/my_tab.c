/*
** EPITECH PROJECT, 2019
** my_libc
** File description:
** my_tab
*/

#include "my_libc.h"

char **my_str_split(char const *str, char separator)
{
    char **tab = NULL;
    size_t len = 1;

    if (!str)
        return (NULL);
    for (size_t i = 0; str[i]; ++i)
        if (str[i] == separator)
            ++len;
    tab = malloc(sizeof(char *) * (len + 1));
    for (size_t i = 0, tmp = 0; i < len; ++i, str += tmp + 1) {
        tmp = my_cstrlen(str, separator);
        tab[i] = my_strndup(str, tmp);
    }
    tab[len] = NULL;
    return (tab);
}