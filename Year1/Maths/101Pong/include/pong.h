/*
** EPITECH PROJECT, 2021
** pong.h
** File description:
** pong.h
*/

#ifndef pong
#define pong

typedef struct Point Point;
struct Point {
    float x;
    float y;
    float z;
};

void calcul_velocity(Point *balle0, Point *balle1, Point *velocity);
void calcul_coordinates(Point *c0, Point *velocity, Point *res, int time);
float calcul_angle(Point *velocity);

#endif /* !pong */
