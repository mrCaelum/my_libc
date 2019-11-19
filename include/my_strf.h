/*
** EPITECH PROJECT, 2019
** libs
** File description:
** my_strf
*/

#ifndef MY_STRF_H_
    #define MY_STRF_H_

    #include <stdarg.h>

    typedef struct op {
        char *str;
        void (*ptr)(va_list, char **);
    } op_t;

    void my_strf_int(va_list, char **);
    void my_strf_uint(va_list, char **);
    void my_strf_float(va_list, char **);
    void my_strf_char(va_list, char **);
    void my_strf_str(va_list, char **);
    void my_strf_hexa(va_list, char **);
    void my_strf_uhexa(va_list, char **);
    void my_strf_octal(va_list, char **);
    void my_strf_binary(va_list, char **);
    void my_strf_pointer(va_list, char **);

#endif /* !MY_STRF_H_ */
