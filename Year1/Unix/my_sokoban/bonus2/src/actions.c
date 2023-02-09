/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "sokoban.h"

void my_exit(char *message, int ex)
{
    write(2, message, my_strlen(message));
    exit(ex);
}

void reload(infomap_t *infomap)
{
    infomap->row = 0;
    infomap->col = 0;
    parsemap(infomap);
    getinfo(infomap);
}

void handle_event(infomap_t *infomap, int key)
{
    switch (key) {
        case KEY_UP:
            go_up(infomap);
            break;
        case KEY_DOWN:
            go_down(infomap);
            break;
        case KEY_LEFT:
            go_left(infomap);
            break;
        case KEY_RIGHT:
            go_right(infomap);
            break;
        case 32:
            reload(infomap);
            break;
        case 27:
            endwin();
            exit(1);
    }
}

int actions(infomap_t *infomap)
{
    int key;

    clear();
    display_colormap(infomap);
    key = ia(infomap);
    refresh();
    usleep(90000);
    if (key == -1)
        exit(84);
    refresh();
    handle_event(infomap, key);
    get_o(infomap);
    if (infomap->nbo == 0)
        return 0;
    check_map(infomap);
    return 1;
}
