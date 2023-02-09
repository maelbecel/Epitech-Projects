/*
** EPITECH PROJECT, 2021
** my_params
** File description:
** xxx
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

int get_color(char red, char green, char blue)
{
    int   color = red;

    color = color << 8;
    color += green;
    color = color << 8;
    color += blue;
    return (color);
}