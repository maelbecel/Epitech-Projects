/*
** EPITECH PROJECT, 2021
** B-MAT-100-REN-1-1-104intersection-lucas.iglesia
** File description:
** cylinder
*/

#include "inter.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void nb_solution(int dis, geo_t *geo, inter_t *inter)
{
    float x = 0;
    if (dis > 0) {
        printf("2 intersection points:\n");
        geo->nb_sol = 2;
        x = ((geo->b * -1) + sqrtf(dis)) / (2 * geo->a);
        parametric(inter, x);
        x = ((geo->b * -1) - sqrtf(dis)) / (2 * geo->a);
        parametric(inter, x);
    } else if (dis == 0) {
        printf("1 intersection point:\n");
        geo->nb_sol = 1;
        x = (geo->b * -1) / (2 * geo->a);
        parametric(inter, x);
    } else {
        printf("No intersection point.\n");
        geo->nb_sol = 0;
    }
}

void cylinder(inter_t *inter)
{
    printf("Cylinder of radius %i\n", inter->param);
    printf("Line passing through the point ");
    print_vector(inter->point);
    printf(" and parallel to the vector ");
    print_vector(inter->vector);
    printf("\n");
    geo_t *geo = get_geo_cylinder(inter);
    int dis = discriminant(geo);
    nb_solution(dis, geo, inter);
}