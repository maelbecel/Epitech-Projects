/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

char **readfile(char *path)
{
    int size = (MAP_COL + 1) * MAP_ROW;
    char **map = malloc(size + 2);
    char *buffer = malloc(sizeof(char) * size);
    int fd = open(path, O_RDONLY);
    int x = 0;

    if (buffer == NULL)
        return (NULL);
    read(fd, buffer, size);
    buffer[size - 1] = '\0';
    close(fd);
    for (int i = 0; i < MAP_ROW + 1; i++) {
        map[i] = malloc(sizeof(char) * MAP_COL + 1);
        if (map[i] == NULL)
            return NULL;
        for (int j = 0; x < size - 1 && buffer[x] != '\n'; j++, x++)
            map[i][j] = buffer[x];
        map[i][MAP_COL] = '\0';
        x++;
    }
    map[MAP_ROW + 1] = NULL;
    return map;
}