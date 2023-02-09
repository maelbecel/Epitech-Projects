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
 * If both strings are not NULL, compare them. If only one is NULL, return 1 or
 * -1. If both are NULL, return 0
 *
 * @param this the string_t object
 * @param str The string to compare to.
 *
 * @return The difference between the two strings.
 */
int compare_s(const string_t *this, const string_t *str)
{
    if (this->str && str->str)
        return (strcmp(this->str, str->str));
    if (this->str && !str->str)
        return (1);
    if (!this->str && str->str)
        return (-1);
    return (0);
}

/**
 * If both strings are not NULL, compare them. If only one is NULL, return 1 or
 * -1. If both are NULL, return 0
 *
 * @param this the string_t object
 * @param str The string to compare to.
 *
 * @return The difference between the two strings.
 */
int compare_c(const string_t *this, const char *str)
{
    if (this->str && str)
        return (strcmp(this->str, str));
    if (this->str && !str)
        return (1);
    if (!this->str && str)
        return (-1);
    return (0);
}

/**
 * It copies the string pointed to by `this->str` into the string pointed to by
 * `s`, starting at position `pos` and copying at most `n` characters
 *
 * @param this a pointer to the string_t structure
 * @param s The destination string.
 * @param n The maximum number of characters to be copied from the string.
 * @param pos The position of the first character to be copied as a substring.
 *
 * @return The number of characters copied.
 */
size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t i = 0;

    if (this->str && s && pos < strlen(this->str)) {
        for (i = 0; i < n && this->str[pos + i]; i++)
            s[i] = this->str[pos + i];
        s[i] = '\0';
    }
    return (i);
}

/**
 * It returns the string contained in the string_t structure
 *
 * @param this the string_t object
 *
 * @return The string.
 */
const char *c_str(const string_t *this)
{
    if (this->str)
        return (this->str);
    return ("");
}

/**
 * If the string is not null and the first character is not null, return 0,
 * otherwise return 1
 *
 * @param this a pointer to the string_t object
 *
 * @return 0 if the string is not empty, 1 if it is.
 */
int empty(const string_t *this)
{
    if (this->str && this->str[0] != '\0')
        return (0);
    return (1);
}
