/*
** EPITECH PROJECT, 2021
** aedsfg
** File description:
** qdsfghj
*/

#include "architect.h"

float **create_identity(void)
{
    float **identity = create_matrix(3, 3);
    identity[0][0] = 1;
    identity[0][1] = 0;
    identity[0][2] = 0;
    identity[1][0] = 0;
    identity[1][1] = 1;
    identity[1][2] = 0;
    identity[2][0] = 0;
    identity[2][1] = 0;
    identity[2][2] = 1;
    return identity;
}

float **create_identity_empty(void)
{
    float **identity = create_matrix(3, 3);
    identity[0][0] = 1;
    identity[0][1] = 1;
    identity[0][2] = 1;
    identity[1][0] = 1;
    identity[1][1] = 1;
    identity[1][2] = 1;
    identity[2][0] = 1;
    identity[2][1] = 1;
    identity[2][2] = 1;
    return identity;
}