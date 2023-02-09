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
 * It initializes a string_t object next
 *
 * @param this the object itself
 * @param s the string to be split
 */
static void string_init_next (string_t *this)
{
    this->split_c = &split_c;
    this->split_s = &split_s;
    this->print = &print;
    this->join_c = &join_c;
    this->join_s = &join_s;
    this->substr = &substr;
}

/**
 * It initializes a string_t object
 *
 * @param this the pointer to the string_t object
 * @param s the string to be copied
 */
void string_init (string_t *this, const char *s)
{
    this->str = (s) ? strdup(s) : NULL;
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_c = &append_c;
    this->append_s = &append_s;
    this->at = &inside;
    this->clear = &clear;
    this->length = &length;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = &find_s;
    this->find_c = &find_c;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    this->to_int = &to_int;
    string_init_next(this);
}

/**
 * This function frees the memory allocated to the string_t object.
 *
 * @param this the string_t object
 */
void string_destroy (string_t *this)
{
    if (this->str)
        free(this->str);
}

/**
 * It assigns the string of str to this.
 *
 * @param this the string_t object that is calling the function.
 * @param str The string to be assigned to the string_t object.
 */
void assign_s(string_t *this , const string_t *str)
{
    if (str->str) {
        if (this->str)
            free(this->str);
        this->str = strdup(str->str);
    }
}

/**
 * It takes a string_t pointer and a C string, and assigns the C string to the
 * string_t
 *
 * @param this the string_t object
 * @param s the string to assign to the string_t object
 */
void assign_c(string_t *this, const char *s)
{
    if (this->str)
        free(this->str);
    if (s)
        this->str = strdup(s);
}
