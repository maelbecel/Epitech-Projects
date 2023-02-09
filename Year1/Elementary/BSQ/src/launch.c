/*
** EPITECH PROJECT, 2021
** launch.c
** File description:
** launch
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "bsq.h"
#include "my.h"


int decal(char *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    return i + 1;
}

int getsize(char *path)
{
    struct stat stats;

    stat(path, &stats);
    return stats.st_size;
}

int getline(char *str)
{
    char *res = malloc(100);
    int i = 0;

    for (; str[i] != '\n'; i++)
        res[i] = str[i];
    res[i] = '\0';
    return my_getnbr(res);
}

int one(char *buffer)
{
    for (int x = 0; my_strlen(buffer); x++){
        if (buffer[x] == '.'){
            buffer[x] = 'x';
            break;
        }
    }
    my_putstr(buffer + decal(buffer));
    my_putchar('\n');
    return 0;
}

int getcol(char *str)
{
    int nbcol = 0;
    int i = decal(str);

    while (str[i] != '\n'){
        nbcol++;
        i++;
    }
    return nbcol;
}

int main (int ac, char **argv)
{
    long size = getsize(argv[1]) - 1;
    char *buffer = malloc(sizeof(char) * size);
    int *map = (int *)malloc(sizeof(int) * size);
    int fd = open(argv[1], O_RDONLY);
    Point maxsquare;
    Len square;
    read(fd, buffer, size);
    if (error(buffer) == 84)
        return 84;
    close(fd);
    square.col = getcol(buffer);
    square.line = getline(buffer);
    if (square.col == 1 || square.line == 1)
        return one(buffer);
    map = buffer_to_matrix(buffer, &square);
    for (int y = 1; y < square.line; y++) {
        for (int x = 1; x < square.col; x++) {
            map[y * (square.col + 1) + x] = check_square(x, y, map, &square);
        }
    }
    max_square(&maxsquare, &square, map);
    display(&maxsquare, &square, buffer);
    return 0;
}
