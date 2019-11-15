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

    /* MY_STRCAT.C */
    char *my_strcat(char const *, char const *);

    /* MY_STRF.C */
    char *my_strf(char const *, ...);

    /* MY_INT.C */
    int my_atoi(char *);
    char *my_itoa(int);
    unsigned int my_atou(char *);
    char *my_utoa(unsigned int);

    /* MY_TAB.C */
    char **my_str_split(char const *, char);

#endif /* !MY_LIBC_H_ */
