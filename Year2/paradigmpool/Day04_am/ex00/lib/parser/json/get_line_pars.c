/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "parser.h"

int getline(char **lineptr, size_t *n, FILE *stream);

char *get_line_pars(FILE *fd, char *variable)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (!variable) {
        fclose(fd);
        return NULL;
    }
    while ((read = getline(&line, &len, fd)) != -1) {
        if (my_strncmp(line, variable, my_strlen(variable)) == 0) {
            line = get_value(line, variable);
            free(variable);
            fclose(fd);
            return line;
        }
    }
    fclose(fd);
    free(line);
    free(variable);
    return NULL;
}
