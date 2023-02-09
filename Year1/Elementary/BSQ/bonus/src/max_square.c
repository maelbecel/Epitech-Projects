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
    int size = map[point->z*(square->line*(square->col+1)+1) + point->y * (square->col + 1) + point->x];

    if (size > maxsquare->size){
        maxsquare->x = point->x - size + 1;
        maxsquare->y = point->y - size + 1;
        maxsquare->z = point->z - size + 1;
        maxsquare->size = size;
    }
}

void max_square(Point *maxsquare, Len *square, int *map)
{
    maxsquare->x = 0;
    maxsquare->y = 0;
    maxsquare->z = 0;
    maxsquare->size = 0;
    Point point;

    for (int z = 1; z < square->dimensions; z++){
        point.z = z;
        for (int y = 1; y < square->line; y++) {
            point.y = y;
            for (int x = 1; x < square->col; x++) {
                point.x = x;
                update_struct(maxsquare, &point, square, map);
            }
        }
    }
}