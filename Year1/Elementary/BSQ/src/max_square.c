/*
** EPITECH PROJECT, 2021
** max_square.c
** File description:
** get thr max square of a map
*/

#include "my.h"
#include "bsq.h"

void update_struct(Point *maxsquare, Point *point, Len *square, int *map)
{
    if (map[point->y * (square->col + 1) + point->x] > maxsquare->size){
        maxsquare->x = point->x - map[point->y * (square->col + 1) + point->x]
        + 1;
        maxsquare->y = point->y - map[point->y * (square->col + 1) + point->x]
        + 1;
        maxsquare->size = map[point->y * (square->col + 1) + point->x];
    }
}

void max_square(Point *maxsquare, Len *square, int *map)
{
    maxsquare->x = 0;
    maxsquare->y = 0;
    maxsquare->size = 0;
    Point point;

    for (int y = 1; y < square->line; y++) {
        point.y = y;
        for (int x = 1; x < square->col; x++) {
            point.x = x;
            update_struct(maxsquare, &point, square, map);
        }
    }
}
