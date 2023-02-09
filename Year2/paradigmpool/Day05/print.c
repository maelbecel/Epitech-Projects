/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"


/**
 * It prints the string_t object's string to stdout
 *
 * @param this the string_t object
 */
void print(const string_t *this)
{
    if (this && this->str)
        printf("%s", this->str);
}

/**
 * It takes a string, a delimiter, and an array of strings, and appends the
 * strings in the array to the string, separated by the delimiter
 *
 * @param this the string_t object to append to
 * @param delim The delimiter to use between each string in the array.
 * @param array The array of strings to join.
 *
 * @return A pointer to the string_t object.
 */
void join_c(string_t *this, char delim, const char * const *array)
{
    char string[2] = {delim, '\0'};

    if (!this || !array)
        return;
    for (int i = 0; array[i]; i++) {
        if (i != 0) {
            append_c(this, string);
            append_c(this, array[i]);
        } else
            assign_c(this, array[i]);
    }
}

/**
 * It takes a string, a delimiter, and an array of strings, and appends the
 * strings in the array to the string, separated by the delimiter
 *
 * @param this the string_t object to append to
 * @param delim The delimiter to use between each string in the array.
 * @param array The array of strings to join.
 *
 * @return A pointer to the string_t object.
 */
void join_s(string_t *this, char delim, const string_t * const *array)
{
    char string[2] = {delim, '\0'};

    if (!this || !array)
        return;
    for (int i = 0; array[i]; i++) {
        if (i != 0) {
            append_c(this, string);
            append_s(this, array[i]);
        } else
            assign_c(this, array[i]);
    }
}

/**
 * It returns a new string_t object that contains a substring of the original
 * string_t object
 *
 * @param this the string to extract the substring from
 * @param offset the index of the first character to copy
 * @param length the length of the substring to extract.
 *
 * @return A new string_t object.
 */
string_t *substr(const string_t *this, int offset, int length)
{
    string_t *new = NULL;

    if (!this || !this->str)
        return (NULL);
    if (offset < 0)
        offset = strlen(this->str) + offset;
    if (length < 0)
        length = strlen(this->str) - offset + length;
    new = malloc(sizeof(string_t));
    new->str = malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++)
        new->str[i] = this->str[offset + i];
    new->str[length] = '\0';
    return (new);
}
