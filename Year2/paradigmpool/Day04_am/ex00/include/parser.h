/*
** EPITECH PROJECT, 2022
** parser.h
** File description:
** @maelbecel
*/

#ifndef FORMATSTRING_H_
    #define FORMATSTRING_H_
    #include <stdarg.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <sys/file.h>
    #include "../../include/formatstring.h"
    #include "../../include/my.h"
    #include <stdio.h>

    /**
    * It returns the size of a file
    *
    * @param path The path to the file you want to get the size of.
    *
    * @return The size of the file in bytes.
    */
    int getsize(char *path);

    /**
    * It reads a file and returns a string containing the file's contents
    *
    * @param file the file to readl
    *
    * @return a pointer to the first character of the string.
    */
    char *read_file(char *file);

    /**
    * It returns the size of a balise
    *
    * @param content the content of the file
    * @param balise the name of the balise you want to get the size of.
    *
    * @return The size of the balise.
    */
    char *get_balise_size(char *content, char *balise);

    /**
    * It returns the content of a balise
    *
    * @param file the file to read
    * @param balise the name of the balise you want to get the content of.
    *
    * @return The content of a balise.
    */
    char *get_balise_content(char *file, char *balise);

    /**
    * It gets the balise from the place
    *
    * @param content the content of the file
    * @param i the index of the character in the string
    *
    * @return The balise of the content.
    */
    char *get_balise_from_place(char *content, int i);

    /**
    * It returns the content of a balise by his id
    *
    * @param file the file to read
    * @param id the id of the element you want to get the content from
    *
    * @return The content of the balise with the id given in parameter.
    */
    char *get_content_by_id(char *file, char *id);

    /**
    * It returns the content of a balise by his class
    *
    * @param file the file to read
    * @param id the class of the element you want to get the content from
    *
    * @return The content of the balise with the class given in parameter.
    */
    char *get_content_by_class(char *file, char *id);

    /**
    * Format a string like the printf function
    *
    * @param str the string to format
    * @param ... the format arguments
    *
    * @return The formatted string.
    */
    char *format(char const *str, ...);

    /**
    * It takes a line of text and a variable name, and returns the value of the
    * variable
    *
    * @param line the line of the file
    * @param var the variable name
    *
    * @return The value of the variable.
    */
    char *get_value(char *line, char *var);

    /**
    * It returns a string containing a double quote
    *
    * @return A pointer to a string.
    */
    char *coat(void);

    /**
    * It opens a file, reads it line by line, and returns the value of
    * the variable passed as a parameter
    *
    * @param fd the file descriptor
    * @param variable the name of the variable you want to get the value of.
    *
    * @return The value of the variable.
    */
    char *get_line_pars(FILE *fd, char *variable);

    /**
    * It opens a file, reads it line by line, and returns the value of a
    * variable
    *
    * @param file the file to parse
    * @param var The variable you want to get the value of.
    *
    * @return The value of the variable in the file.
    */
    char *parser(char *file, char *var);

    /**
    * It takes a JSON file and a variable name, and returns the value of
    * the variable
    *
    * @param file The file to parse
    * @param var The variable you want to get from the json file.
    *
    * @return A string
    */
    char *str_from_json(char *file, char *var);

    /**
    * It takes a file and a variable name, and returns an array of strings
    *
    * @param file the file to parse
    * @param var the variable you want to get from the json file
    *
    * @return A string array.
    */
    char **str_array_from_json(char *file, char *var);

    /**
    * It takes a file and a variable name, and returns the value of
    * the variable as an integer
    *
    * @param file the file to parse
    * @param var the variable you want to get the value from
    *
    * @return The value of the variable in the json file.
    */
    int int_from_json(char *file, char *var);

    /**
    * It takes a JSON file, a variable name, and a pointer to an integer,
    * and returns an array of integers
    *
    * @param file the path to the JSON file
    * @param var the name of the variable in the JSON file
    * @param size the size of the array
    *
    * @return An array of ints.
    */
    int *int_array_from_json(char *file, char *var, int *size);

    /**
    * It opens a file, writes a buffer to it, and then closes the file
    *
    * @param file the file to write to
    * @param buffer the buffer to write to the file
    */
    void fill_file(char *file, char *buffer);

    /**
    * It reads a file line by line, and if it finds a line that starts with the
    * variable name, it replaces it with the new value
    *
    * @param variable The variable to update.
    * @param fd the file descriptor of the file to be modified
    * @param value the value to set the variable to
    *
    * @return A string containing the updated file.
    */
    char *get_update(char *variable, FILE *fd, char *value);

    /**
    * It opens a file, reads it,
    * and writes it back to the same file
    *
    * @param file the file to update
    * @param var the variable you want to update
    * @param value the value to be updated
    *
    * @return the value of the variable buffer.
    */
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

    /**
    * It removes the first and last character of a string
    *
    * @param str The string to clean.
    *
    * @return A string without the first and last character.
    */
    char *clean_string(char *str);

#endif
