/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "sokoban.h"

int is_not_locked(infomap_t *infomap, int i, int j)
{
    if (infomap->map[i][j] == 'X' &&
        (((infomap->map[i][j - 1] != '#' &&
        infomap->map[i][j - 1] != 'X') &&
        (infomap->map[i][j + 1] != '#' &&
        infomap->map[i][j + 1] != 'X')) ||
        ((infomap->map[i - 1][j] != '#' &&
        infomap->map[i - 1][j] != 'X') &&
        (infomap->map[i + 1][j] != '#' &&
        infomap->map[i + 1][j] != 'X'))))
        return 1;
    return 0;
}

void check_map(infomap_t *infomap)
{
    int cross = 0;
    int nbx = 0;

    for (int i = 0; i < infomap->size; i++)
        if (infomap->buffer[i] == 'X')
            nbx++;
    for (int i = 0; i < infomap->row; i++)
        for (int j = 0; j < infomap->col; j++)
            cross += is_not_locked(infomap, i, j);
    if (cross == nbx)
        return;
    endwin();
    free_all(infomap);
    exit(1);
}

void displaymap(infomap_t *infomap)
{
    int x = -1;
    int y = -1;
    int a = 0;
    int b = 0;

    while (x < 0 || y < 0) {
        getmaxyx(stdscr, a, b);
        x = (b - infomap->col) / 2;
        y = (a - infomap->row ) / 2;
        clear();
        mvprintw(a / 2, (b - my_strlen(ERROR_MAP_SIZE)) / 2, ERROR_MAP_SIZE);
        refresh();
    }
    clear();
    for (int i = 0; infomap->map[i] != NULL; i++) {
        for (int j = 0; infomap->map[i][j] != '\0'; j++) {
            mvprintw(y + i, x + j, "%c", infomap->map[i][j]);
        }
        printw("\n");
    }
}
