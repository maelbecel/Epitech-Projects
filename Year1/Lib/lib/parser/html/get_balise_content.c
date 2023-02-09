/*
** EPITECH PROJECT, 2022
** get_balise_content.c
** File description:
** get_balise_content
*/

#include "parser.h"

int getsize(char *path)
{
    struct stat stats;

    stat(path, &stats);
    return stats.st_size;
}

char *read_file(char *file)
{
    char *buffer = malloc(sizeof(char) * (getsize(file) + 1));
    int fd = open(file, O_RDONLY);
    int size = read(fd, buffer, getsize(file));

    if (fd == -1)
        return (NULL);
    buffer[size] = '\0';
    return buffer;
}

char *get_balise_size(char *content, char *balise)
{
    char *start = format("<%s", balise);
    char *res = malloc(sizeof(char) * my_strlen(content));
    int i = 0;
    int j = 0;

    for (; my_strncmp(content + i, start, my_strlen(start)) != 0; i++);
    for (; content[i] != '>'; j++, i++) {
        res[j] = content[i];
    }
    res[j] = '>';
    res[j + 1] = '\0';
    free(start);
    return res;
}

char *get_balise_content(char *file, char *balise)
{
    char *content = read_file(file);
    char *start = get_balise_size(content, balise);
    char *end = format("</%s>", balise);
    char *res = malloc(sizeof(char) * my_strlen(content));
    size_t i = 0;
    size_t x = 0;

    for (; my_strncmp(content + i, start, my_strlen(start)) != 0; i++);
    i += my_strlen(start);
    for (; my_strncmp(content + i, end, my_strlen(end)) != 0; i++) {
        res[x++] = content[i];
    }
    free(content), free(start), free(end);
    res[x] = '\0';
    return res;
}
