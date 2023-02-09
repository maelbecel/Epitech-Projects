/*
** EPITECH PROJECT, 2021
** B-MAT-100-REN-1-1-104intersection-lucas.iglesia
** File description:
** sphere
*/

#include "inter.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void sphere(inter_t *inter)
{
    printf("Sphere of radius %i\n", inter->param);
    printf("Line passing through the point ");
    print_vector(inter->point);
    printf(" and parallel to the vector ");
    print_vector(inter->vector);
    printf("\n");
    geo_t *geo = get_geo_sphere(inter);
    int dis = discriminant(geo);
    nb_solution(dis, geo, inter);
}