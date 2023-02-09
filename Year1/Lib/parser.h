/*
** EPITECH PROJECT, 2021
** star.c
** File description:
** star.c
*/

#ifndef FORMATSTRING_H_
    #define FORMATSTRING_H_
    #include <stdarg.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <sys/file.h>
    #include "formatstring.h"
    #include "my.h"
    #include <stdio.h>

    ////////////////////////////////////////////////////////////
    /// \brief Get size of a file
    ///
    /// \param path Path of the file
    ///
    /// \return Size of the file
    ////////////////////////////////////////////////////////////
    int getsize(char *path);

    ////////////////////////////////////////////////////////////
    /// \brief Read a file
    ///
    /// \param file Path of the file
    ///
    /// \return Content of the file
    ////////////////////////////////////////////////////////////
    char *read_file(char *file);

    ////////////////////////////////////////////////////////////
    /// \brief Get the size of a balise
    ///
    /// \param content Content of the file
    /// \param balise Balise to get the size
    ///
    /// \return Entire balise
    ////////////////////////////////////////////////////////////
    char *get_balise_size(char *content, char *balise);

    ////////////////////////////////////////////////////////////
    /// \brief Get the content of a balise
    ///
    /// \param file Path of the file
    /// \param balise Balise to get the content
    ///
    /// \return Content of the balise
    ////////////////////////////////////////////////////////////
    char *get_balise_content(char *file, char *balise);

    ////////////////////////////////////////////////////////////
    /// \brief Get the name of the actual balise
    ///
    /// \param content Content of the file
    /// \param i Index of the balise
    ///
    /// \return Name of the balise
    ////////////////////////////////////////////////////////////
    char *get_balise_from_place(char *content, int i);

    ////////////////////////////////////////////////////////////
    /// \brief Get the content of a balise by id
    ///
    /// \param file Path of the file
    /// \param id Id of the balise
    ///
    /// \return Content of the balise
    ////////////////////////////////////////////////////////////
    char *get_content_by_id(char *file, char *id);

    ////////////////////////////////////////////////////////////
    /// \brief Get the content of a balise by class
    ///
    /// \param file Path of the file
    /// \param id Class of the balise
    ///
    /// \return Content of the balise
    ////////////////////////////////////////////////////////////
    char *get_content_by_class(char *file, char *id);

    ////////////////////////////////////////////////////////////
    /// \brief Format string representation
    ///
    /// \param str   string to format
    /// \param ...   list of arguments
    ///
    /// \return String of the string
    ///
    ////////////////////////////////////////////////////////////
    char *format(char const *str, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Get value for json format
    ///
    /// \param line  line to check
    /// \param var   variable to get
    ///
    /// \return Value of the variable
    ///
    ////////////////////////////////////////////////////////////
    char *get_value(char *line, char *var);

    ////////////////////////////////////////////////////////////
    /// \brief Coat in string representation
    ///
    /// \return Coat
    ///
    ////////////////////////////////////////////////////////////
    char *coat(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get the line to parse
    ///
    /// \param fd FILE type for file directory
    /// \param variable variable to get
    ///
    /// \return Line to parse
    ///
    ////////////////////////////////////////////////////////////
    char *get_line_pars(FILE *fd, char *variable);

    ////////////////////////////////////////////////////////////
    /// \brief Parse a JSON File
    ///
    /// \param file Path of the file
    /// \param var Variable to get
    ///
    /// \return Value of the variable
    ///
    ////////////////////////////////////////////////////////////
    char *parser(char *file, char *var);

    ////////////////////////////////////////////////////////////
    /// \brief Get the value of a string variable
    ///
    /// \param file Path of the file
    /// \param var Variable to get
    ///
    /// \return Value of the variable
    ///
    ////////////////////////////////////////////////////////////
    char *str_from_json(char *file, char *var);

    ////////////////////////////////////////////////////////////
    /// \brief Get the value of a string array variable
    ///
    /// \param file Path of the file
    /// \param var Variable to get
    ///
    /// \return Value of the variable
    ///
    ////////////////////////////////////////////////////////////
    char **str_array_from_json(char *file, char *var);

    ////////////////////////////////////////////////////////////
    /// \brief Get the value of a int variable
    ///
    /// \param file Path of the file
    /// \param var Variable to get
    ///
    /// \return Value of the variable
    ///
    ////////////////////////////////////////////////////////////
    int int_from_json(char *file, char *var);

    ////////////////////////////////////////////////////////////
    /// \brief Get the value of a int array variable
    ///
    /// \param file Path of the file
    /// \param var Variable to get
    /// \param size Size of the array
    ///
    /// \return Value of the variable
    ///
    ////////////////////////////////////////////////////////////
    int *int_array_from_json(char *file, char *var, int *size);

    ////////////////////////////////////////////////////////////
    /// \brief Fill a file with a buffer
    ///
    /// \param file Path of the file
    /// \param buffer Buffer to fill the file
    ///
    ////////////////////////////////////////////////////////////
    void fill_file(char *file, char *buffer);

    ////////////////////////////////////////////////////////////
    /// \brief Get the content of the file to update
    ///
    /// \param variable variable to update
    /// \param fd    File descriptor to update
    /// \param value value to update
    ///
    /// \return Content of the file
    ///
    ////////////////////////////////////////////////////////////
    char *get_update(char *variable, FILE *fd, char *value);

    ////////////////////////////////////////////////////////////
    /// \brief Update a JSON File
    ///
    /// \param file Path of the file
    /// \param var Variable to update
    /// \param value Value to update
    ///
    ////////////////////////////////////////////////////////////
    int update_file(char *file, char *var, char *value);

    ////////////////////////////////////////////////////////////
    /// \brief Concatenate the settings
    ///
    /// \param a  first element to concat
    /// \param b  second element to concat
    ///
    /// \return The concatenated string of a and b
    ///
    ////////////////////////////////////////////////////////////
    char *conc(char *a, char *b);

    ////////////////////////////////////////////////////////////
    /// \brief Clean a double coat at the start and end in a string
    ///
    /// \param str string to clean
    ///
    /// \return Return a str without coats
    ///
    ////////////////////////////////////////////////////////////
    char *clean_string(char *str);

#endif
