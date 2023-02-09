/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "parser.h"

char *clean_string(char *str)
{
    int i = 1;
    char *res = malloc(sizeof(char) * my_strlen(str));

    if (!res || !str)
        return NULL;
    for (; str[i]; i++)
        res[i - 1] = str[i];
    res[i - 2] = '\0';
    return res;
}

int update_file(char *file, char *var, char *value)
{
    FILE *fd = fopen(file, "r");
    char *buffer;
    char *variable = format("    \"%s\": ", var);

    if (fd == NULL) {
        free(variable);
        return EXIT_FAILURE;
    }
    buffer = get_update(variable, fd, value);
    fill_file(file, buffer);
    return EXIT_SUCCESS;
}
