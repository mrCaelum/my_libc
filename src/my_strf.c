/*
** EPITECH PROJECT, 2019
** libs
** File description:
** my_strf
*/

#include "my_libc.h"
#include "my_strf.h"

static const op_t ptr_tab[] = {
    {"d", &my_strf_int},
    // {"ld", &my_strf_long},
    {"i", &my_strf_int},
    // {"li", &my_strf_long},
    // {"u", &my_strf_uint},
    // {"lu", &my_strf_ulong},
    {"c", &my_strf_char},
    {"s", &my_strf_str},
    // {"S", &string_with_hidden_char},
    // {"x", &my_strf_hexa},
    // {"lx", &hexa},
    // {"llx", &hexa},
    // {"hx", &hexa},
    // {"hhx", &hexa},
    // {"X", &my_strf_uhexa},
    // {"lX", &upcase_hexa},
    // {"llX", &upcase_hexa},
    // {"hX", &upcase_hexa},
    // {"hhX", &upcase_hexa},
    // {"o", &octal},
    // {"b", &binary},
    // {"p", &pointer},
    {NULL, NULL}
};

static size_t call_function(char const *opt, char **str, va_list args)
{
    size_t len;

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