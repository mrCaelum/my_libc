/*
** EPITECH PROJECT, 2019
** my_libc
** File description:
** my_float
*/

#include "my_libc.h"

static bool is_float_str(char const *str, bool *negative)
{
    bool is_one_separator = false;

    for (size_t i = 0; str[i]; ++i) {
        if (!i && str[i] == '-')
            *negative = true;
        else if (str[i] == '.' && !is_one_separator)
            is_one_separator = true;
        else if (str[i] < '0' || str[i] > '9')
            return (false);
    }
    return (true);
}

double my_atof(char const *str)
{
    double result;
    size_t len[2];
    char *tmp;
    bool negative = false;

    if (!my_strcontains(str, '.'))
        return (my_atou(str));
    if (!is_float_str(str, &negative))
        return (0);
    len[0] = my_cstrlen(str, '.');
    len[1] = my_strlen(str + len[0] + 1);
    if (!len[0] || !len[1])
        return (0);
    tmp = my_strndup(str, len[0]);
    result = my_atou(tmp + negative);
    free(tmp);
    tmp = my_strndup(str + len[0] + 1, len[1]);
    result += (double)((double)my_atou(tmp) / (double)my_power(10, len[1]));
    free(tmp);
    return (negative ? -result : result);
}

char *my_ftoa(double nb, size_t digits)
{
    char *str = NULL;
    char *tmp = NULL;
    size_t integer = ABS(nb);
    size_t decimal = (double)(ABS(nb) - integer) * my_power(10, digits);

    if (nb < 0)
        str = my_stradd(str, "-");
    tmp = my_utoa(integer);
    str = my_stradd(str, tmp);
    free(tmp);
    str = my_stradd(str, ".");
    tmp = my_utoa(decimal);
    str = my_strnadd(str, tmp, digits);
    integer = my_strlen(tmp);
    if (digits > integer)
        str = my_addnchar(str, '0', digits - integer);
    free(tmp);
    return (str);
}

char *my_ftoa_sci(double nb, size_t digits)
{
    char *str = NULL;
    char *tmp = NULL;
    size_t integer;
    size_t decimal;
    int power_lvl = 0;

    for (; nb >= 10; ++power_lvl, nb /= 10);
    for (; nb < 1; --power_lvl, nb *= 10);
    tmp = my_ftoa(nb, digits);
    str = my_stradd(str, tmp);
    free(tmp);
    str = my_stradd(str, power_lvl < 0 ? "e" : "e+");
    tmp = my_itoa(power_lvl);
    str = my_stradd(str, tmp);
    free(tmp);
    return (str);
}