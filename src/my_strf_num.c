/*
** EPITECH PROJECT, 2019
** libs
** File description:
** my_strf_num
*/

#include <stdarg.h>
#include "my_libc.h"
#include <stdio.h>

void my_strf_int(va_list args, char **str)
{
    int i = va_arg(args, int);
    char *tmp = my_itoa(i);

    *str = my_stradd(*str, tmp);
    free(tmp);
}