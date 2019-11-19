/*
** EPITECH PROJECT, 2019
** my_libc
** File description:
** my_math
*/

#include <stdio.h>

size_t my_power(size_t x, size_t y)
{
    size_t result = 1;

    for (; y; --y)
        result *= x;
    return (result);
}