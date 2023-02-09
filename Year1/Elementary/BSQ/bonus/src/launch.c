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

int getdimensions(char *str)
{
    int nbdim = 0;
    int i = decal(str);

    while (str[i] != '\0'){
        if (str[i] == 'd')
            nbdim++;
        i++;
    }
    return nbdim;
}

int main (int ac, char **argv)
{
    long size = getsize(argv[1]);
    char *buffer = malloc(sizeof(char) * size);
    int *map = (int *)malloc(sizeof(int) * size);
    int fd = open(argv[1], O_RDONLY);
    int taille;

    read(fd, buffer, size);
    close(fd);
    Point maxsquare;
    Len square;
    square.col = getcol(buffer);
    square.line = getline(buffer);
    square.dimensions = getdimensions(buffer);
    map = buffer_to_matrix(buffer, &square);
    taille = (square.dimensions*square.line*(square.col+1)+square.dimensions);
    for (int z = 1; z < square.dimensions; z++) {
        for (int y = 1; y < square.line; y++) {
            for (int x = 1; x < square.col; x++) {
                map[z*(square.line*(square.col+1)+1) + y*(square.col + 1) + x] = check_square(x, y, z, map, &square);
            }
        }
    }
    //my_putmatrix(map,taille);
    max_square(&maxsquare, &square, map);
    display(&maxsquare, &square, buffer);
    return 0;
}