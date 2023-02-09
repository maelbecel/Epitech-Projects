/*
** EPITECH PROJECT, 2021
** error.c
** File description:
** error
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "navy.h"
#include <stdlib.h>

static int absol(int nb)
{
    if (nb < 0)
        nb *= -1;
    return nb;
}

static int lenght_boat(char *map, int i, int lenght)
{
    if (map[i + 2] == map[i + 5]) {
        if (absol(map[i + 6] - map[i + 3]) != lenght - 1)
            return 0;
    }
    if (map[i + 3] == map[i + 6]) {
        if (absol(map[i + 5] - map[i + 2]) != lenght - 1)
            return 0;
    }
    if (map[i + 2] != map[i + 5] && map[i + 3] != map[i + 6]) {
        return 0;
    }
    return 1;
}

int error_map(char *map)
{
    int j = 2;
    for (int i = 0; i < 31; i += 8, j++) {
        if (map[i] - 48 != j || map[i + 1] != ':' || map[i + 4] != ':') {
            write(2, "Map not allowed\n", 16);
            return 0;
        }
        if (lenght_boat(map, i, j) == 0) {
            write(2, "Map not allowed\n", 16);
            return 0;
        }
    }
    return 1;
}
