/*
** EPITECH PROJECT, 2021
** display.C
** File description:
** display
*/

#include "bsq.h"
#include "my.h"

void display (Point *maxsquare, Len *square, char *buffer)
{
    char *res = buffer + decal(buffer);

    for (int y = maxsquare->y; y < maxsquare->y + maxsquare->size ;y++){
        for (int x = maxsquare->x; x < maxsquare->x + maxsquare->size; x++){
            res[y * (square->col + 1) + x] = 'x';
        }
    }
    my_putstr(res);
    my_putchar('\n');
}
