/*
** EPITECH PROJECT, 2019
** libs
** File description:
** my_int
*/

#include "my_libc.h"

int my_atoi(char *str)
{
    int i = 0;
    bool is_neg = false;

    if (!str)
        return (0);
    if (*str == '-') {
        is_neg = true;
        ++str;
    }
    for (; *str; ++str) {
        if (!my_strcontains("0123456789", *str))
            return (0);
        i = (i * 10) + (*str - 48);
    }
    if (is_neg)
        i = -i;
    return (i);
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
    if (!str)
        return (NULL);
    str[len] = 0;
    for (len -= 1; len > is_neg; --len, i /= 10)
        str[len] = i % 10 + 48;
    str[len] = i % 10 + 48;
    if (is_neg)
        str[0] = '-';
    return (str);
}

unsigned int my_atou(char *str)
{
    unsigned int i = 0;

    if (!str)
        return (0);
    for (; *str; ++str) {
        if (!my_strcontains("0123456789", *str))
            return (0);
        i = (i * 10) + (*str - 48);
    }
    return (i);
}

char *my_utoa(unsigned int i)
{
    char *str;
    size_t len = !i;

    for (int tmp = i; tmp; ++len)
        tmp /= 10;
    str = malloc(len + 1);
    if (!str)
        return (NULL);
    str[len] = 0;
    for (len -= 1; len > 0; --len, i /= 10)
        str[len] = i % 10 + 48;
    str[len] = i % 10 + 48;
    return (str);
}