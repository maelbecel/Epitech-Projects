/*
** EPITECH PROJECT, 2021
** check_square.c
** File description:
** check square
*/

#include <stdio.h>
#include "my.h"
#include "bsq.h"

int get_lower(int x, int y, int z, int *map, Len *square)
{
    int up = map[z*(square->line*(square->col+1)+1) + (y-1)*(square->col + 1) + x];
    int left = map[z*(square->line*(square->col+1)+1) + y*(square->col + 1) + (x-1)];
    int diag = map[z*(square->line*(square->col+1)+1) + (y-1)*(square->col + 1) + (x-1)];
    int front_point = map[(z-1)*(square->line*(square->col+1)+1) + y*(square->col + 1) + x];
    int front_up = map[(z-1)*(square->line*(square->col+1)+1) + (y-1)*(square->col + 1) + x];
    int front_left = map[(z-1)*(square->line*(square->col+1)+1) + y*(square->col + 1) + (x-1)];
    int front_diag = map[(z-1)*(square->line*(square->col+1)+1) + (y-1)*(square->col + 1) + (x-1)];
    int min = up;

    if (left < min)
        min = left;
    if (diag < min)
        min = diag;
    if (front_point < min)
        min = front_point;
    if (front_up < min)
        min = front_up;
    if (front_left < min)
        min = front_left;
    if (front_diag < min)
        min = front_diag;
    return min;
}

int check_square(int x, int y, int z, int *map, Len *square)
{
    int point = map[z*(square->line*(square->col+1)+1) + y*(square->col + 1) + x];
    int up = map[z*(square->line*(square->col+1)+1) + (y-1)*(square->col + 1) + x];
    int left = map[z*(square->line*(square->col+1)+1) + y*(square->col + 1) + (x-1)];
    int diag = map[z*(square->line*(square->col+1)+1) + (y-1)*(square->col + 1) + (x-1)];
    int front_point = map[(z-1)*(square->line*(square->col+1)+1) + y*(square->col + 1) + x];
    int front_up = map[(z-1)*(square->line*(square->col+1)+1) + (y-1)*(square->col + 1) + x];
    int front_left = map[(z-1)*(square->line*(square->col+1)+1) + y*(square->col + 1) + (x-1)];
    int front_diag = map[(z-1)*(square->line*(square->col+1)+1) + (y-1)*(square->col + 1) + (x-1)];

    if (point > 0 && up > 0 && left > 0 && diag > 0 &&
        front_point > 0 && front_up > 0 && front_left > 0 && front_diag > 0)
        return point + get_lower(x, y, z, map, square);
    return point;
}