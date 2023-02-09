/*
** EPITECH PROJECT, 2021
** calcul_angle.c
** File description:
** calcul angle
*/

#include <math.h>
#include "pong.h"

float calcul_angle(Point *velocity)
{
    float angle;
    float hyp = (sqrt(pow(velocity->x, 2) + pow(velocity->y, 2) + pow(velocity->z, 2)));
    float adj = (sqrt(pow(velocity->x, 2) + pow(velocity->y, 2)));
    float res;
    angle = acos(adj / hyp);
    res = angle *(180 / M_PI);
    return (res);
}