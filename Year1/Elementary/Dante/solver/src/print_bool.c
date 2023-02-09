/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "dante.h"

void print_map(char **map, bool **path, int height, int width)
{
    char *string = malloc(sizeof(char) * 2);
    string[1] = '\0';
    for (size_t i = 0; (int)i < height; i++) {
        for (size_t j = 0; (int)j < width; j++) {
            string[0] = map[i][j];
            my_printf((path[i][j] == true) ? "o" : string);
        }
        if ((int)i + 1 != height)
            my_printf("\n");
    }
}