/*
** EPITECH PROJECT, 2019
** my_libc
** File description:
** my_strf_char
*/

#include <stdarg.h>
#include "my_libc.h"

void my_strf_char(va_list args, char **str)
{
    char i = va_arg(args, int);
    char *tmp = *str;
    size_t len = my_strlen(tmp);

    *str = malloc(len + 2);
    if (*str) {
        my_strcpy(*str, tmp);
        (*str)[len] = i;
        (*str)[len + 1] = 0;
        free(tmp);
    }
}

void my_strf_str(va_list args, char **str)
{
    char const *i = va_arg(args, char const *);

    *str = my_stradd(*str, i);
}