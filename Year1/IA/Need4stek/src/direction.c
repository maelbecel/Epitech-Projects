/*
** EPITECH PROJECT, 2022
** B-AIA-200-REN-2-1-n4s-lucas.iglesia
** File description:
** direction
*/

#include "my.h"
#include "printf.h"
#include "ia.h"

void handle_sign(float val, int sign)
{
    dprintf(2, "val : %f, sign : %i\n", val, sign);
    if (sign < 0)
        turn_wheels(val * -1);
    else
        turn_wheels(val);
}

void get_direction(int dir, int sign)
{
    if (dir <= 1000) {
        handle_sign(0.1, sign);
        return;
    } else
        handle_sign(0, sign);
    // if (dir <= 1500) {
    //     handle_sign(0.05, sign);
    //     return;
    // }
}

void direction(void)
{
    int dir = get_distance();
    int sign = get_distance_far_left() - get_distance_far_right();

    dprintf(2, "dir : %d\n", dir);
    if (dir <= 200) {
        handle_sign(0.4, sign);
        return;
    }
    if (dir <= 400) {
        handle_sign(0.3, sign);
        return;
    }
    if (dir <= 600) {
        handle_sign(0.2, sign);
        return;
    }
    get_direction(dir, sign);
}