/*
** EPITECH PROJECT, 2019
** my_libc
** File description:
** my_strf_floating_point
*/

#include <stdarg.h>
#include "my_libc.h"

void my_strf_fp_int(va_list args, char **str, size_t n)
{
    int i = va_arg(args, int);
    char *tmp = my_itoa(i);

    *str = my_stradd(*str, tmp);
    free(tmp);
    *str = my_stradd(*str, ".");
    *str = my_addnchar(*str, '0', n);
}

void my_strf_fp_uint(va_list args, char **str, size_t n)
{
    size_t i = va_arg(args, size_t);
    char *tmp = my_utoa(i);

    *str = my_stradd(*str, tmp);
    free(tmp);
    *str = my_stradd(*str, ".");
    *str = my_addnchar(*str, '0', n);
}

void my_strf_fp_float(va_list args, char **str, size_t n)
{
    double i = va_arg(args, double);
    char *tmp = my_ftoa(i, n);

    *str = my_stradd(*str, tmp);
    free(tmp);
}

void my_strf_fp_float_sci(va_list args, char **str, size_t n)
{
    double i = va_arg(args, double);
    char *tmp = my_ftoa_sci(i, n);

    *str = my_stradd(*str, tmp);
    free(tmp);
}