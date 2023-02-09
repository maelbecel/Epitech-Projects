/*
** EPITECH PROJECT, 2021
** calcul_velocity.c
** File description:
** calcul velocity
*/

#include "pong.h"

void calcul_velocity(Point *t_0, Point *t_1, Point *t_v)
{
    t_v->x = t_1->x - t_0->x;
    t_v->y = t_1->y - t_0->y;
    t_v->z = t_1->z - t_0->z;
}