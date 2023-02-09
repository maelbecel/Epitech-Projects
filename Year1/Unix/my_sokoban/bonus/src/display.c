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
    else if (infomap->map[i][j] == 'X' && infomap->basic_map[i][j] == 'O')
        return 1;
    return 0;
}

void check_map(infomap_t *infomap)
{
    int cross = 0;
    int nbx = 0;
    sfMusic *music = sfMusic_createFromFile("sounds/lose.ogg");

    for (int i = 0; i < infomap->size; i++)
        if (infomap->buffer[i] == 'X')
            nbx++;
    for (int i = 0; i < infomap->row; i++)
        for (int j = 0; j < infomap->col; j++)
            cross += is_not_locked(infomap, i, j);
    if (cross == nbx)
        return;
    sfMusic_play(music);
    sleep(1);
    sfMusic_destroy(music);
    endwin();
    free_all(infomap);
    exit(1);
}

void select_color(infomap_t *infomap, int i, int j)
{
    if (infomap->map[i][j] == '#')
        attron(COLOR_PAIR(2));
    if (infomap->map[i][j] == 'O')
        attron(COLOR_PAIR(3));
    if (infomap->map[i][j] == 'P')
        attron(COLOR_PAIR(1));
    if (infomap->map[i][j] == ' ')
        attron(COLOR_PAIR(6));
    if (infomap->map[i][j] == 'X') {
        if (infomap->basic_map[i][j] == 'O')
            attron(COLOR_PAIR(4));
        else
            attron(COLOR_PAIR(5));
    }
}

void wait_size(infomap_t *infomap)
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
        attron(COLOR_PAIR(5));
        mvprintw(a / 2, (b - my_strlen(ERROR_MAP_SIZE)) / 2, ERROR_MAP_SIZE);
        refresh();
    }
}

void display_colormap(infomap_t *infomap)
{
    int x = 0;
    int y = 0;

    wait_size(infomap);
    getmaxyx(stdscr, y, x);
    x = (x - infomap->col) / 2;
    y = (y - infomap->row ) / 2;
    clear();
    for (int i = 0; infomap->map[i] != NULL; i++) {
        for (int j = 0; infomap->map[i][j] != '\0'; j++) {
            select_color(infomap, i, j);
            mvprintw(y + i, x + j, "%c", ' ');
            attron(COLOR_PAIR(6));
        }
        printw("\n");
    }
}
