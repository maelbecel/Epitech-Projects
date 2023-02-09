/*
** EPITECH PROJECT, 2021
** check_square.h
** File description:
** check square
*/

#include <stdio.h>
#include "my.h"
#include "bsq.h"

int get_lower(int x, int y, int *map, Len *square)
{
    int north = map[(y - 1) * (square->col + 1) + x];
    int west = map[y * (square->col + 1) + (x - 1)];
    int north_west = map[(y - 1) * (square->col + 1) + (x - 1)];
    int min = north;

    if (west < min)
        min = west;
    if (north_west < min)
        min = north_west;
    return min;
}

int check_square(int x, int y, int *map, Len *square)
{
    int point = map[y * (square->col + 1) + x];
    int north = map[(y-1) * (square->col + 1) + x];
    int west = map[y * (square->col + 1) + (x-1)];
    int north_west = map[(y-1) * (square->col + 1) + (x-1)];

    if ((point > 0 && north > 0) && (west > 0 && north_west > 0))
        return map[y * (square->col + 1) + x] + get_lower(x, y, map, square);
    return map[y * (square->col + 1) + x];
}
