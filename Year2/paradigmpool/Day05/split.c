/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"


static int count_line(char *str, char separator)
{
    int nb = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator)
            nb++;
    }
    return nb;
}

static int size_str(char *str, int i, char separator)
{
    int nb = 0;
    for (; str[i] != separator && str[i] != '\0'; i++) {
        nb++;
    }
    return nb;
}

static char *fill_array(char *str, int i, char separator)
{
    int j = 0;
    int size = size_str(str, i, separator);
    char *arg = malloc(sizeof(char) * (size + 1));

    for (; str[i] != separator && str[i] != '\0'; i++) {
        arg[j] = str[i];
        j++;
    }
    arg[j] = '\0';
    return arg;
}

/**
 * It splits a string into an array of strings, using a separator
 *
 * @param this the string_t * to split
 * @param separator the character to split the string on
 *
 * @return A pointer to a pointer to a string_t.
 */
string_t **split_s(const string_t *this, char separator)
{
    int j = 0;
    char *str = this->str;
    int size = count_line(str, separator);
    string_t **array = malloc(sizeof(string_t *) * (size + 2));

    for (int i = 0; i < strlen(str); i++) {
        for (; str[i] == separator && str[i] != '\0'; i++);
        array[j] = malloc(sizeof(string_t));
        string_init(array[j], fill_array(str, i, separator));
        j++;
        for (; str[i] != separator && str[i] != '\0'; i++);
    }
    array[j] = NULL;
    return array;
}

/**
 * It splits a string into an array of strings, using a separator
 *
 * @param this the string_t object
 * @param separator the character to split the string on
 *
 * @return A pointer to a pointer to a char.
 */
char **split_c(const string_t *this, char separator)
{
    int j = 0;
    char *str = this->str;
    int size = count_line(str, separator);
    char **array = malloc(sizeof(char *) * (size + 2));

    for (int i = 0; i < strlen(str); i++) {
        for (; str[i] == separator && str[i] != '\0'; i++);
        array[j] = fill_array(str, i, separator);
        j++;
        for (; str[i] != separator && str[i] != '\0'; i++);
    }
    array[j] = NULL;
    return array;
}
