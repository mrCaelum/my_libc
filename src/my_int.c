/*
** EPITECH PROJECT, 2019
** my_libc
** File description:
** my_int
*/

#include "my_libc.h"

int my_atoi(char const *str)
{
    int i = 0;
    size_t pos = 0;
    bool is_neg = false;

    if (!str)
        return (0);
    if (str[pos] == '-') {
        is_neg = true;
        ++pos;
    }
    for (; str[pos]; ++pos) {
        if (str[pos] < '0' || str[pos] > '9')
            return (0);
        i = (i * 10) + (str[pos] - '0');
    }
    return (is_neg ? -i : i);
}

char *my_itoa(int i)
{
    char *str;
    size_t len = !i;
    bool is_neg = i < 0;

    if (is_neg)
        i = -i;
    for (int tmp = i; tmp; ++len)
        tmp /= 10;
    len += is_neg;
    str = malloc(len + 1);
    str[len] = 0;
    for (len -= 1; len > is_neg; --len, i /= 10)
        str[len] = i % 10 + '0';
    str[len] = i % 10 + '0';
    if (is_neg)
        str[0] = '-';
    return (str);
}

size_t my_atou(char const *str)
{
    size_t pos = 0;
    size_t i = 0;

    if (!str)
        return (0);
    for (; str[pos]; ++pos) {
        if (str[pos] < '0' || str[pos] > '9')
            return (0);
        i = (i * 10) + (str[pos] - '0');
    }
    return (i);
}

char *my_utoa(size_t i)
{
    char *str;
    size_t len = !i;

    for (int tmp = i; tmp; ++len)
        tmp /= 10;
    str = malloc(len + 1);
    str[len] = 0;
    for (len -= 1; len > 0; --len, i /= 10)
        str[len] = i % 10 + '0';
    str[len] = i % 10 + '0';
    return (str);
}
