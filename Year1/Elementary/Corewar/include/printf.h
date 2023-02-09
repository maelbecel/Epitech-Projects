/*
** EPITECH PROJECT, 2021
** star.c
** File description:
** star.c
*/

#ifndef PRINTF_H_
    #define PRINTF_H_
    #include <stdarg.h>
    #include <unistd.h>

    ////////////////////////////////////////////////////////////
    /// \brief Write a char in the standard output
    ///
    /// \param argv char to display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int displaychar(va_list argv);

    ////////////////////////////////////////////////////////////
    /// \brief Write a string in the standard output
    ///
    /// \param argv string to display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int displaystr(va_list argv);

    ////////////////////////////////////////////////////////////
    /// \brief Write an int in the standard output
    ///
    /// \param argv int to display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int displaynbr(va_list argv);

    ////////////////////////////////////////////////////////////
    /// \brief Write a long int in the standard output
    ///
    /// \param argv long int to display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int displaynbr_long(va_list argv);

    ////////////////////////////////////////////////////////////
    /// \brief Write an int in binary format in the standard output
    ///
    /// \param argv int to display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int displaybinary(va_list argv);

    ////////////////////////////////////////////////////////////
    /// \brief Write a '%' in the standard output
    ///
    /// \param argv useless
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int displaypercent(va_list argv);

    ////////////////////////////////////////////////////////////
    /// \brief Write a pointer in the standard output
    ///
    /// \param argv string to display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int displaypointer(va_list argv);

    ////////////////////////////////////////////////////////////
    /// \brief Write an int in hexadecimal format in the standard output
    ///
    /// \param argv int to display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int displaynbr_hexa(va_list argv);

    ////////////////////////////////////////////////////////////
    /// \brief Write an int in upper case hexadecimal
    /// format in the standard output
    ///
    /// \param argv int to display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int displaynbr_hexa_capital(va_list argv);

    ////////////////////////////////////////////////////////////
    /// \brief Write a string with unprintable
    /// characters in the standard output
    ///
    /// \param argv string to display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int displaystr_unprintable(va_list argv);

    ////////////////////////////////////////////////////////////
    /// \brief Write an int in the standard output
    ///
    /// \param argv int to display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int displaynbr_dec(va_list argv);

    ////////////////////////////////////////////////////////////
    /// \brief Write an int in octal base in the standard output
    ///
    /// \param argv int to display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int displaynbr_octal(va_list argv);

    ////////////////////////////////////////////////////////////
    /// \brief Write an int in octal base in the standard output
    ///
    /// \param argv int to display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int displaynbr_octal_hashtag(va_list argv);

    ////////////////////////////////////////////////////////////
    /// \brief Write an int in hexadecimal format in the standard output
    ///
    /// \param argv int to display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int displaynbr_hexa_hashtag(va_list argv);

    ////////////////////////////////////////////////////////////
    /// \brief Write an int in upper case hexadecimal
    /// format in the standard output
    ///
    /// \param argv int to display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int displaynbr_hexa_capital_hashtag(va_list argv);

    ////////////////////////////////////////////////////////////
    /// \brief Write a string with arguments in the standard output
    ///
    /// \param argv string to display
    /// \param ... params for the string
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int my_printf(char const *str, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Struct for a flag,
    ///
    /// Contains a pointer on function for the flag and the flag
    ///
    ////////////////////////////////////////////////////////////
    struct flags {
        int(*func)(va_list);
        char flag;
    };

#endif