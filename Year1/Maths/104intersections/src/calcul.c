/*
** EPITECH PROJECT, 2021
** B-MAT-100-REN-1-1-104intersection-lucas.iglesia
** File description:
** calcul
*/

#include "inter.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

geo_t *get_geo_cylinder(inter_t *inter)
{
    geo_t *geo = malloc(sizeof(geo_t));
    geo->a = powf(inter->vector[0], 2) + powf(inter->vector[1], 2);
    geo->b = 2 * ((inter->point[0] * inter->vector[0]) + (inter->point[1] * inter->vector[1]));
    geo->c = powf(inter->point[0], 2) + powf(inter->point[1], 2) - powf(inter->param, 2);
    return geo;
}

geo_t *get_geo_sphere(inter_t *inter)
{
    geo_t *geo = malloc(sizeof(geo_t));
    geo->a = powf(inter->vector[0], 2) + powf(inter->vector[1], 2) + powf(inter->vector[2], 2);
    geo->b = 2 * ((inter->point[0] * inter->vector[0]) + (inter->point[1] * inter->vector[1]) + (inter->point[2] * inter->vector[2]));
    geo->c = powf(inter->point[0], 2) + powf(inter->point[1], 2) + powf(inter->point[2], 2) - powf(inter->param, 2);
    return geo;
}

int parametric(inter_t *inter, float res)
{
    float x = inter->point[0] + (res * inter->vector[0]);
    float y = inter->point[1] + (res * inter->vector[1]);
    float z = inter->point[2] + (res * inter->vector[2]);
    printf("(%.3f, %.3f, %.3f)\n", x, y, z);
    return 0;
}

int discriminant(geo_t *geo)
{
    return (powf(geo->b, 2) - (4 * (geo->a * geo->c)));
}