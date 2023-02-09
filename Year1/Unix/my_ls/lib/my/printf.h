/*
** EPITECH PROJECT, 2021
** star.c
** File description:
** star.c
*/

#ifndef PRINTF_H_
    #define PRINTF_H_
    #include <stdarg.h>

    void displaychar(va_list argv);
    void displaystr(va_list argv);
    void displaynbr(va_list argv);
    void displaynbr_long(va_list argv);
    void displaybinary(va_list argv);
    void displaypercent(va_list argv);
    void displaypointer(va_list argv);
    void displaynbr_hexa(va_list argv);
    void displaynbr_hexa_capital(va_list argv);
    void displaystr_unprintable(va_list argv);
    void displaynbr_dec(va_list argv);
    void displaynbr_octal(va_list argv);
    void displaynbr_octal_hashtag(va_list argv);
    void displaynbr_hexa_hashtag(va_list argv);
    void displaynbr_hexa_capital_hashtag(va_list argv);
    int my_printf(char const *str, ...);

    struct flags {
        int(*func)(va_list);
        char flag;
    };

#endif
