/*
** EPITECH PROJECT, 2021
** printf.h
** File description:
** printf.h
*/

#ifndef PRINTF_H
    #define PRINTF_H

    #include <stdarg.h>

    struct flag {
        int (*func)(va_list arg);
        char flag_f;
    };

#endif
