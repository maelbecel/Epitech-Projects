/*
** EPITECH PROJECT, 2022
** tetris.c
** File description:
** tetris
*/

#include "my.h"
#include "printf.h"
#include "tetris.h"

void draw_box(int x, int y, int nbcol, int nbrow)
{
    mvprintw(y, x, "%c", '/');
    mvprintw(nbrow + y, x, "%c", '\\');
    mvprintw(y, nbcol + x, "%c", '\\');
    mvprintw(nbrow + y, nbcol + x, "%c", '/');
    for(int i = 1; i < nbcol; i++) {
        mvprintw(y, x + i, "%c", '-');
        mvprintw(nbrow + y, x + i, "%c", '-');
    }
    for(int i = 1; i < nbrow; i++) {
        mvprintw(y + i, x, "%c", '|');
        mvprintw(y + i, nbcol + x, "%c", '|');
    }
}

void drawline(element_t *line, int len, int x, int y)
{
    for (int i = 0, s = 0; i < len; i++, s++) {
        mvprintw(y, x + i + s, "%c", line[i].c);
    }
}