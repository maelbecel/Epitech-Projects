/*
** EPITECH PROJECT, 2022
** get_content_by_id.c
** File description:
** id
*/

#include "parser.h"

char *get_content_by_class(char *file, char *id)
{
    char *content = read_file(file);
    char *start = format("class=\"%s\"", id);
    char *end;
    char *res = malloc(sizeof(char) * my_strlen(content));
    char *balise = NULL;
    size_t i = 0;
    size_t x = 0;

    for (; my_strncmp(content + i, start, my_strlen(start)) != 0; i++);
    balise = get_balise_from_place(content, i);
    end = format("</%s>", balise);
    i += my_strlen(start) + 1;
    for (; my_strncmp(content + i, end, my_strlen(end)) != 0; i++) {
        res[x++] = content[i];
    }
    free(content), free(start), free(end), free(balise);
    res[x] = '\0';
    return res;
}
