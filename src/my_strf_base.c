/*
** EPITECH PROJECT, 2019
** my_libc
** File description:
** my_strf_base
*/

#include <stdarg.h>
#include "my_libc.h"

void my_strf_hexa(va_list args, char **str)
{
    size_t i = va_arg(args, size_t);
    char *nb = my_tobase(i, "0123456789abcdef");

    *str = my_stradd(*str, nb);
    free(nb);
}

void my_strf_uhexa(va_list args, char **str)
{
    size_t i = va_arg(args, size_t);
    char *nb = my_tobase(i, "0123456789ABCDEF");

    *str = my_stradd(*str, nb);
    free(nb);
}

void my_strf_octal(va_list args, char **str)
{
    size_t i = va_arg(args, size_t);
    char *nb = my_tobase(i, "01234567");

    *str = my_stradd(*str, nb);
    free(nb);
}

void my_strf_binary(va_list args, char **str)
{
    size_t i = va_arg(args, size_t);
    char *nb = my_tobase(i, "01");

    *str = my_stradd(*str, nb);
    free(nb);
}

void my_strf_pointer(va_list args, char **str)
{
    size_t i = va_arg(args, size_t);
    char *nb = my_tobase(i, "0123456789abcdef");

    *str = my_stradd(*str, "0x");
    *str = my_stradd(*str, nb);
    free(nb);
}