/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "parser.h"

int *int_array_from_json(char *file, char *var, int *size)
{
    char **array = str_array_from_json(file, var);
    int *int_array;
    int i = 0;

    if (!array)
        return NULL;
    int_array = malloc(sizeof(int) * my_strarraylen(array));
    if (!int_array)
        return NULL;
    for (; array[i]; i++) {
        int_array[i] = my_getnbr(array[i]);
        free(array[i]);
    }
    if (size != NULL)
        *size = i;
    free(array);
    return int_array;
}
