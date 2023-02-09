/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "parser.h"

char *conc(char *a, char *b)
{
    char *res = malloc(my_strlen(a) + my_strlen(b) + 1);
    int x = 0;

    if (!res)
        return NULL;
    for (int i = 0; i < my_strlen(a); i++, x++)
        res[x] = a[i];
    for (int i = 0; i < my_strlen(b); i++, x++)
        res[x] = b[i];
    res[x] = '\0';
    return res;
}

char *get_update(char *variable, FILE *fd, char *value)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *buffer = "";

    while ((read = getline(&line, &len, fd)) != -1) {
        line[read] = '\0';
        if (my_strcmp(line, "\n") == 0)
            continue;
        if (my_strcmp(line, "}\n") == 0)
            return format("%s%s", buffer, line);
        if (my_strncmp(line, variable, my_strlen(variable)) == 0) {
            buffer = format("%s%s%s%s", buffer, variable, value,
                                    (line[read - 2] == ',') ? ",\n" : "\n");
        } else
            buffer = conc(buffer, line);
    }
    free(variable);
    fclose(fd);
    return buffer;
}
