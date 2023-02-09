/*
** EPITECH PROJECT, 2022
** B-AIA-200-REN-2-1-n4s-lucas.iglesia
** File description:
** speed
*/

#include "my.h"
#include "printf.h"
#include "ia.h"

void get_speed(int spd)
{
	if (spd >= 600) {
		forward(0.15);
        return;
    } else if (spd >= 400) {
		forward(0.1);
        return;
    } else {
		forward(0.08);
        return;
    }
}

void speed(void)
{
    int spd = get_distance();

    if (spd >= 2000) {
        forward(0.4);
        return;
    }
    if (spd >= 1500) {
		forward(0.35);
        return;
    }
	if (spd >= 1000) {
		forward(0.25);
        return;
    }
    get_speed(spd);
}
