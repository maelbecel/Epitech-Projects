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
 * It returns the position of the first occurence of the string str in the
 * string this, starting at position pos
 *
 * @param this the string to search in
 * @param str The string to search in.
 * @param pos The position in the string to start searching from.
 *
 * @return The position of the first occurence of the string str in the string
 * this.
 */
int find_s(const string_t *this, const string_t *str, size_t pos)
{
    char *search = (this && this->str) ? this->str + pos : NULL;
    char *found = (str && str->str) ? str->str : NULL;

    if (search && found)
        return (strstr(search, found) - search);
    return (-1);
}

/**
 * It returns the position of the first occurence of the string str in the
 * string_t object this, starting at position pos
 *
 * @param this the string_t object
 * @param str The string to search for.
 * @param pos The position in the string to start searching from.
 *
 * @return The position of the first occurence of the string str in the
 * string_t object.
 */
int find_c(const string_t *this, const char *str, size_t pos)
{
    char *search = (this && this->str) ? this->str + pos : NULL;
    char *found = (str) ? str : NULL;

    if (search && found)
        return (strstr(search, found) - search);
    return (-1);
}

/**
 * It inserts a string into another string at a given position
 *
 * @param this the string_t object
 * @param pos the position in the string where the insertion will be made
 * @param str the string to insert
 *
 */
void insert_c(string_t *this, size_t pos, const char *str)
{
    char *new_str = NULL;
    size_t len = (this && this->str) ? strlen(this->str) : 0;

    if (pos > len)
        return;
    if (str) {
        new_str = malloc(len + strlen(str) + 1);
        if (new_str) {
            strncpy(new_str, this->str, pos);
            strcpy(new_str + pos, str);
            strcpy(new_str + pos + strlen(str), this->str + pos);
            free(this->str);
            this->str = new_str;
        }
    }
}

/**
 * It inserts a string into another string at a given position
 *
 * @param this the string_t object
 * @param pos the position in the string where the insertion will take place
 * @param str the string to insert
 *
 * @return A pointer to a string_t struct.
 */
void insert_s(string_t *this, size_t pos, const string_t *str)
{
    char *new_str = NULL;
    size_t len = (this && this->str) ? strlen(this->str) : 0;

    if (pos > len)
        return;
    if (str && str->str) {
        new_str = malloc(len + strlen(str->str) + 1);
        if (new_str) {
            strncpy(new_str, this->str, pos);
            strcpy(new_str + pos, str->str);
            strcpy(new_str + pos + strlen(str->str), this->str + pos);
            free(this->str);
            this->str = new_str;
        }
    }
}

/**
 * It converts a string to an integer
 *
 * @param this the string_t object
 *
 * @return the integer value of the string.
 */
int to_int(const string_t *this)
{
    return (this && this->str) ? atoi(this->str) : 0;
}
