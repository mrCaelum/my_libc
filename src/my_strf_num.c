/*
** EPITECH PROJECT, 2019
** my_libc
** File description:
** my_strf_num
*/

#include <stdarg.h>
#include "my_libc.h"

void my_strf_int(va_list args, char **str)
{
    int i = va_arg(args, int);
    char *tmp = my_itoa(i);

    *str = my_stradd(*str, tmp);
    free(tmp);
}

void my_strf_uint(va_list args, char **str)
{
    unsigned int i = va_arg(args, unsigned int);
    char *tmp = my_utoa(i);

    *str = my_stradd(*str, tmp);
    free(tmp);
}

void my_strf_float(va_list args, char **str)
{
    double i = va_arg(args, double);
    char *tmp = my_ftoa(i, 6);

    *str = my_stradd(*str, tmp);
    free(tmp);
}

void my_strf_float_sci(va_list args, char **str)
{
    double i = va_arg(args, double);
    char *tmp = my_ftoa_sci(i, 6);

    *str = my_stradd(*str, tmp);
    free(tmp);
}