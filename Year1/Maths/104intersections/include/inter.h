/*
** EPITECH PROJECT, 2021
** inter.h
** File description:
** inter
*/

#ifndef INTER
    #define INTER

    typedef struct inter {
        int opt;
        int *point;
        int *vector;
        int param;
    } inter_t;

    typedef struct geo {
        float a;
        float b;
        float c;
        int nb_sol;
    } geo_t;

    void print_vector(int *vector);
    void sphere(inter_t *inter);
    void cylinder(inter_t *inter);
    void cone(inter_t *inter);
    geo_t *get_geo_cylinder(inter_t *inter);
    geo_t *get_geo_sphere(inter_t *inter);
    int parametric(inter_t *inter, float res);
    int discriminant(geo_t *geo);
    void nb_solution(int dis, geo_t *geo, inter_t *inter);

#endif /* !INTER */
