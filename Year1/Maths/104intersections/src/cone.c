/*
** EPITECH PROJECT, 2021
** B-MAT-100-REN-1-1-104intersection-lucas.iglesia
** File description:
** cone
*/

#include "inter.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void cone(inter_t *inter)
{
    printf("Cone with a %i degree angle\n", inter->param);
    printf("Line passing through the point ");
    print_vector(inter->point);
    printf(" and parallel to the vector ");
    print_vector(inter->vector);
    printf("\n");
    geo_t *geo = get_geo_cylinder(inter);
    int dis = discriminant(geo);
    nb_solution(dis, geo, inter);
}