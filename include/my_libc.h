/*
** EPITECH PROJECT, 2019
** libs
** File description:
** my_libc
*/

#ifndef MY_LIBC_H_
    #define MY_LIBC_H_

    #include <stdlib.h>
    #include <stdbool.h>

    #define ABS(x) (x < 0 ? -x : x)

    typedef unsigned char byte_t;

    /* MY_STRLEN.C */
    size_t my_strlen(char const *);
    size_t my_cstrlen(char const *, char);

    /* MY_STRDUP.C */
    char *my_strdup(char const *);
    char *my_strndup(char const *, size_t);

    /* MY_STRCMP.C */
    bool my_strcmp(char const *, char const *);
    bool my_strncmp(char const *, char const *, size_t);
    bool my_strcontains(char const *, char);

    /* MY_STRCPY.C */
    char *my_strcpy(char *, char const *);
    char *my_strncpy(char *, char const *, size_t);

    /* MY_STRADD.C */
    char *my_stradd(char *, char const *);
    char *my_strnadd(char *, char const *, size_t);
    char *my_addnchar(char *, char, size_t);

    /* MY_STRCAT.C */
    char *my_strcat(char const *, char const *);

    /* MY_STRF.C */
    char *my_strf(char const *, ...);

    /* MY_INT.C */
    int my_atoi(char const *);
    char *my_itoa(int);
    size_t my_atou(char const *);
    char *my_utoa(size_t);

    /* MY_FLOAT.C */
    double my_atof(char const *);
    char *my_ftoa(double, size_t);
    char *my_ftoa_sci(double, size_t);

    /* MY_BASES.C */
    char *my_tobase(size_t, char const *);

    /* MY_MATH.C */
    size_t my_power(size_t, size_t);

    /* MY_TAB.C */
    char **my_str_split(char const *, char);

#endif /* !MY_LIBC_H_ */
