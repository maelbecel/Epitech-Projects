/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "inter.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void get_arg(char **av, inter_t *inter)
{
    inter->opt = atoi(av[1]);
    inter->point = malloc(sizeof(int) * 3);
    inter->point[0] = atoi(av[2]);
    inter->point[1] = atoi(av[3]);
    inter->point[2] = atoi(av[4]);
    inter->vector = malloc(sizeof(int) * 3);
    inter->vector[0] = atoi(av[5]);
    inter->vector[1] = atoi(av[6]);
    inter->vector[2] = atoi(av[7]);
    inter->param = atoi(av[8]);
}

void print_vector(int *vector)
{
    printf("(");
    for(int i = 0; i < 3; i++) {
        if (i == 2) {
            printf("%i)", vector[i]);
        } else {
            printf("%i, ", vector[i]);
        }
    }
}

void option(inter_t *inter)
{
    switch (inter->opt) {
        case 1 : sphere(inter);
            break;
        case 2 : cylinder(inter);
            break;
        case 3 : cone(inter);
            break;
    }
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        printf("USAGE\n\t./104intersection opt xp yp zp xv yv zv p\n\nDESCRIPTION\n\topt \t\tsurface option: 1 for a sphere, 2 for a cylinder, 3 for a cone\n\t(xp, yp, zp) \tcoordinates of a point by which the light ray passes through\n\t(xv, yv, zv) \tcoordinates of a vector parallel to the light ray\n\tp \t\tparameter: radius of the sphere, radius of the cylinder, orangle formed by the cone and the Z-axis\n");
        return 0;
    }
    if (ac != 9 || atoi(av[1]) < 1 || atoi(av[1]) > 3)
        return 84;
    else if (atoi(av[1]) == 3 && (atoi(av[8]) < 0 || atoi(av[8]) > 90))
        return 84;
    inter_t *inter = malloc(sizeof(inter_t));
    get_arg(av, inter);
    option(inter);
}