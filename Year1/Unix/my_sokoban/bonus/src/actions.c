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
    sfMusic *music = sfMusic_createFromFile("sounds/rewind.ogg");
    sfMusic_play(music);
    sleep(2);
    infomap->row = 0;
    infomap->col = 0;
    parsemap(infomap);
    getinfo(infomap);
    sfMusic_destroy(music);
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
    int last = infomap->nbo;
    sfMusic *music = sfMusic_createFromFile("sounds/valid.ogg");

    clear();
    display_colormap(infomap);
    refresh();
    get_o(infomap);
    if (infomap->nbo < last)
        sfMusic_play(music);
    if (infomap->nbo == 0)
        return 0;
    key = getch();
    handle_event(infomap, key);
    if (key == -1)
        exit(84);
    refresh();
    if (infomap->nbo == 0)
        return 0;
    check_map(infomap);
    return 1;
}
