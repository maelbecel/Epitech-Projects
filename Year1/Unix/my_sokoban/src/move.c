/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "sokoban.h"

void go_up(infomap_t *infomap)
{
    if (infomap->map[infomap->posy - 1][infomap->posx] == '#')
        return;
    if (infomap->map[infomap->posy - 1][infomap->posx] == 'X' &&
        infomap->map[infomap->posy - 2][infomap->posx] != '#' &&
        infomap->map[infomap->posy - 2][infomap->posx] != 'X') {
        infomap->map[infomap->posy - 1][infomap->posx] =
        infomap->basic_map[infomap->posy - 1][infomap->posx];
        infomap->map[infomap->posy - 2][infomap->posx] = 'X';
        infomap->map[infomap->posy][infomap->posx] =
        infomap->basic_map[infomap->posy][infomap->posx];
        infomap->posy--;
        infomap->map[infomap->posy][infomap->posx] = 'P';
    } else if (infomap->map[infomap->posy - 1][infomap->posx] == ' ' ||
        infomap->map[infomap->posy - 1][infomap->posx] == 'O') {
        infomap->map[infomap->posy][infomap->posx] =
        infomap->basic_map[infomap->posy][infomap->posx];
        infomap->posy--;
        infomap->map[infomap->posy][infomap->posx] = 'P';
    }
}

void go_down(infomap_t *infomap)
{
    if (infomap->map[infomap->posy + 1][infomap->posx] == '#')
        return;
    if (infomap->map[infomap->posy + 1][infomap->posx] == 'X' &&
        infomap->map[infomap->posy + 2][infomap->posx] != '#' &&
        infomap->map[infomap->posy + 2][infomap->posx] != 'X') {
        infomap->map[infomap->posy + 1][infomap->posx] =
        infomap->basic_map[infomap->posy + 1][infomap->posx];
        infomap->map[infomap->posy + 2][infomap->posx] = 'X';
        infomap->map[infomap->posy][infomap->posx] =
        infomap->basic_map[infomap->posy][infomap->posx];
        infomap->posy++;
        infomap->map[infomap->posy][infomap->posx] = 'P';
    } else if (infomap->map[infomap->posy + 1][infomap->posx] == ' ' ||
        infomap->map[infomap->posy + 1][infomap->posx] == 'O') {
        infomap->map[infomap->posy][infomap->posx] =
        infomap->basic_map[infomap->posy][infomap->posx];
        infomap->posy++;
        infomap->map[infomap->posy][infomap->posx] = 'P';
    }
}

void go_left(infomap_t *infomap)
{
    if (infomap->map[infomap->posy][infomap->posx - 1] == '#')
        return;
    if (infomap->map[infomap->posy][infomap->posx - 1] == 'X' &&
        infomap->map[infomap->posy][infomap->posx - 2] != '#' &&
        infomap->map[infomap->posy][infomap->posx - 2] != 'X') {
        infomap->map[infomap->posy][infomap->posx - 1] =
        infomap->basic_map[infomap->posy][infomap->posx - 1];
        infomap->map[infomap->posy][infomap->posx - 2] = 'X';
        infomap->map[infomap->posy][infomap->posx] =
        infomap->basic_map[infomap->posy][infomap->posx];
        infomap->posx--;
        infomap->map[infomap->posy][infomap->posx] = 'P';
    } else if (infomap->map[infomap->posy][infomap->posx - 1] == ' ' ||
        infomap->map[infomap->posy][infomap->posx - 1] == 'O') {
        infomap->map[infomap->posy][infomap->posx] =
        infomap->basic_map[infomap->posy][infomap->posx];
        infomap->posx--;
        infomap->map[infomap->posy][infomap->posx] = 'P';
    }
}

void go_right(infomap_t *infomap)
{
    if (infomap->map[infomap->posy][infomap->posx + 1] == '#')
        return;
    if (infomap->map[infomap->posy][infomap->posx + 1] == 'X' &&
        infomap->map[infomap->posy][infomap->posx + 2] != '#' &&
        infomap->map[infomap->posy][infomap->posx + 2] != 'X') {
        infomap->map[infomap->posy][infomap->posx + 1] =
        infomap->basic_map[infomap->posy][infomap->posx + 1];
        infomap->map[infomap->posy][infomap->posx + 2] = 'X';
        infomap->map[infomap->posy][infomap->posx] =
        infomap->basic_map[infomap->posy][infomap->posx];
        infomap->posx++;
        infomap->map[infomap->posy][infomap->posx] = 'P';
    } else if (infomap->map[infomap->posy][infomap->posx + 1] == ' ' ||
        infomap->map[infomap->posy][infomap->posx + 1] == 'O') {
        infomap->map[infomap->posy][infomap->posx] =
        infomap->basic_map[infomap->posy][infomap->posx];
        infomap->posx++;
        infomap->map[infomap->posy][infomap->posx] = 'P';
    }
}
