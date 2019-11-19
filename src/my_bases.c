/*
** EPITECH PROJECT, 2019
** my_libc
** File description:
** my_bases
*/

#include "my_libc.h"

char *my_tobase(size_t nb, char const *base)
{
    size_t bsize = my_strlen(base);
    size_t nb_len = 1;
    char *str = NULL;

    if (!bsize)
        return (NULL);
    for (size_t tmp = nb; tmp > bsize; ++nb_len)
        tmp /= bsize;
    str = malloc(sizeof(char) * (nb_len + 1));
    for (str[nb_len--] = 0; nb > bsize; nb /= bsize)
        str[nb_len--] = base[nb % bsize];
    str[nb_len] = base[nb];
    return (str);
}