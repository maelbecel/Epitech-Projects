/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-lucas.iglesia
** File description:
** init
*/

#include "my.h"
#include "printf.h"
#include "dante.h"

static void init_cell(char **map, int i, int j)
{
    if (i == 0 || j == 0)
        map[i][j] = '*';
    else
        map[i][j] = 'X';
}

static char **init_map(int x , int y)
{
    char **map = malloc(sizeof(char *) * (y + 1));
    map[y] = NULL;
    for (int i = 0; i < y; i++) {
        map[i] = malloc(sizeof(char) * (x + 1));
        map[i][x] = '\0';
        for (int j = 0; j < x; j++) {
            init_cell(map, i, j);
        }
    }
    return map;
}

generator_t *init_generator(int x, int y)
{
    generator_t *map = malloc(sizeof(generator_t));
    map->x = x;
    map->y = y;
    map->map = init_map(x, y);
    return map;
}
