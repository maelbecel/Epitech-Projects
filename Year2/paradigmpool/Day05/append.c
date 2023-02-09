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
 * It appends the string
 * contained in the string_t *ap to the string_t *this
 *
 * @param this the string_t object that is calling the function.
 * @param ap The string to append to this.
 */
void append_s(string_t *this, const string_t *ap)
{
    if (ap->str) {
        if (this->str) {
            this->str = realloc(this->str, strlen(this->str)
                                            + strlen(ap->str) + 1);
            strcat(this->str, ap->str);
        } else {
            this->str = strdup(ap->str);
        }
    }
}

/**
 * It appends a string to a string_t object
 *
 * @param this the string_t object
 * @param ap The string to append to the string_t object.
 */
void append_c(string_t *this, const char *ap)
{
    if (ap) {
        if (this->str) {
            this->str = realloc(this->str, strlen(this->str)
                                            + strlen(ap) + 1);
            strcat(this->str, ap);
        } else {
            this->str = strdup(ap);
        }
    }
}

/**
 * It returns the character at the given position in the string
 *
 * @param this a pointer to the string_t object
 * @param pos The position of the character to return.
 *
 * @return The character at the given position.
 */
char inside(const string_t *this, size_t pos)
{
    if (this->str && pos < strlen(this->str))
        return (this->str[pos]);
    return (-1);
}

/**
 * It frees the string_t's string, and sets it to NULL
 *
 * @param this the string_t object
 */
void clear(string_t *this)
{
    if (this->str)
        free(this->str);
    this->str = strdup("");
}

/**
 * If the string exists, return its length, otherwise return -1.
 *
 * @param this the string_t object
 *
 * @return The length of the string.
 */
int length(const string_t *this)
{
    if (this->str)
        return (strlen(this->str));
    return (-1);
}
