/*
** EPITECH PROJECT, 2021
** pong.c
** File description:
** pong
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pong.h"

void print_usage(void)
{
    printf("USAGE\n./101pong x0 y0 z0 x1 y1 z1 n\n\nDESCRIPTION\nx0 ball abscissa at time t - 1\ny0 ball ordinate at time t - 1\nz0 ball altitude at time t - 1\nx1 ball abscissa at time t\ny1 ball ordinate at time t\nz1 ball altitude at time t\nn time shift (greater than or equal to zero, integer)\n");
}

int checkarg(char **av)
{
    for (int i = 1; i < 8; i++){
        for(int j = 0; j < my_strlen(av[i]);j++)
            if ((av[i][j] - '0' < 0 || av[i][j] - '0' > 9) && av[i][j] != '.')
                return 1;
    }
    return 0;
}

int main (int ac, char **av)
{
    int time_shift;
    float angle;

    if (ac != 8) {
        print_usage();
        return 84;
    }
    if (checkarg(av) == 1)
        return 84;
    if (av[7][0] == '-')
        return 84;
    for (int i = 0; i < strlen(av[7]); i++) {
        if (av[7][i] == '.')
            return 84;
    }
    time_shift = atoi(av[7]);
    Point balle0;
    balle0.x = atof(av[1]);
    balle0.y = atof(av[2]);
    balle0.z = atof(av[3]);
    Point balle1;
    balle1.x = atof(av[4]);
    balle1.y = atof(av[5]);
    balle1.z = atof(av[6]);
    Point velocity;
    Point ball_time;

    calcul_velocity(&balle0, &balle1, &velocity);
    calcul_coordinates(&balle1, &velocity, &ball_time, time_shift);
    angle = calcul_angle(&velocity);

    printf("The velocity vector of the ball is:\n");
    printf("(%.2f, %.2f, %.2f)\n",velocity.x, velocity.y, velocity.z);
    printf("At time t + %d, ball coordinates will be:\n",time_shift);
    printf("(%.2f, %.2f, %.2f)\n",ball_time.x, ball_time.y, ball_time.z);
    // if (velocity.z == 0 && balle0.z == 0)
    //     printf("The incidence angle is:\n0.00 degrees\n");
    if (velocity.z != 0 && ((-balle1.z)/velocity.z) >= 0 && balle1.x != 0)
        printf("The incidence angle is:\n%.2f degrees\n",angle);
    else
        printf("The ball won't reach the paddle.\n");
    return 0;
}