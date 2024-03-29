/*
** EPITECH PROJECT, 2019
** my_libc
** File description:
** my_strf
*/

#include "my_libc.h"
#include "my_strf.h"

static const op_t ptr_tab[] = {
    {"d", &my_strf_int},
    {"i", &my_strf_int},
    {"u", &my_strf_uint},
    {"c", &my_strf_char},
    {"s", &my_strf_str},
    {"f", &my_strf_float},
    {"e", &my_strf_float_sci},
    {"x", &my_strf_hexa},
    {"X", &my_strf_uhexa},
    {"o", &my_strf_octal},
    {"b", &my_strf_binary},
    {"p", &my_strf_pointer},
    {NULL, NULL}
};

static const op_arg_t ptr_arg_tab[] = {
    {"d", &my_strf_fp_int},
    {"i", &my_strf_fp_int},
    {"u", &my_strf_fp_uint},
    {"f", &my_strf_fp_float},
    {"e", &my_strf_fp_float_sci},
    {NULL, NULL}
};

static size_t call_with_parameters(char const *opt, char **str, va_list args)
{
    size_t pos = 2;
    char *tmp;
    size_t nb;
    size_t len;

    for (; opt[pos] >= '0' && opt[pos] <= '9'; ++pos);
    tmp = my_strndup(opt + 2, pos - 2);
    nb = my_atou(tmp);
    free(tmp);
    for (byte_t i = 0; ptr_arg_tab[i].str; ++i) {
        len = my_strlen(ptr_arg_tab[i].str);
        if (my_strncmp(opt + pos, ptr_arg_tab[i].str, len)) {
            ptr_arg_tab[i].ptr(args, str, nb);
            return (pos + len);
        }
    }
    *str = my_strnadd(*str, opt, pos);
    return (pos);
}

static size_t call_function(char const *opt, char **str, va_list args)
{
    size_t len;

    if (opt[1] == '.')
        return (call_with_parameters(opt, str, args));
    for (byte_t i = 0; ptr_tab[i].str; ++i) {
        len = my_strlen(ptr_tab[i].str);
        if (my_strncmp(opt + 1, ptr_tab[i].str, len)) {
            ptr_tab[i].ptr(args, str);
            return (len + 1);
        }
    }
    *str = my_stradd(*str, "%");
    if (my_strncmp(opt + 1, "%", 1))
        return (2);
    return (1);
}

char *my_strf(char const *opt, ...)
{
    char *str = NULL;
    va_list args;

    if (!opt)
        return (NULL);
    va_start(args, opt);
    for (size_t i = 0; opt[i];) {
        if (opt[i] == '%') {
            str = my_strnadd(str, opt, i);
            opt += call_function(opt + i, &str, args) + i;
            i = 0;
        } else
            ++i;
    }
    str = my_stradd(str, opt);
    va_end(args);
    return (str);
}