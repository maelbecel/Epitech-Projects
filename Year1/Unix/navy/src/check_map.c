/*
** EPITECH PROJECT, 2021
** check_map
** File description:
** check_map.C
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "navy.h"

int check_line(int i, char **map)
{
    for (int j = 0; j < 8; j++){
        if (map[i][j] >= '0' && map[i][j] <= '9')
            return 0;
    }
    return 1;
}

int sink(char **map)
{
    for (int i = 0; i < 8; i++){
        if (check_line(i, map) == 0)
            return 0;
    }
    return 1;
}

int checkmap(char posx, char posy, char **map)
{
    int x = posx - 'A';
    int y = posy - '1';
    if (map[y][x] != '.')
        return 1;
    return 0;
}
