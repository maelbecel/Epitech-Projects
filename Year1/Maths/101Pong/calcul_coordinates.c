/*
** EPITECH PROJECT, 2021
** calcul_coordinates.c
** File description:
** calcul_coordinates
*/

#include "pong.h"

void calcul_coordinates(Point *c0, Point *velocity, Point *res, int time)
{
    res->x = c0->x + (velocity->x * time);
    res->y = c0->y + (velocity->y * time);
    res->z = c0->z + (velocity->z * time);
}