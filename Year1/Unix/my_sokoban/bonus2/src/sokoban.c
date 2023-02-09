/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "sokoban.h"

void readfile(infomap_t *infomap, char *path)
{
    struct stat st;

    stat(path, &st);
    infomap->fd = open(path, O_RDONLY);
    infomap->size = st.st_size + 1;
    if (infomap->fd == -1)
        exit(84);
    infomap->buffer = malloc(infomap->size);
    read(infomap->fd, infomap->buffer, infomap->size);
    infomap->buffer[infomap->size - 1] = '\0';
    close(infomap->fd);
    parsemap(infomap);
}

void handle_error(infomap_t *infomap)
{
    (void)(infomap);
    return;
}

void free_all(infomap_t *infomap)
{
    free(infomap->buffer);
    for (int i = 0; i < infomap->row; i++) {
        free(infomap->basic_map[i]);
        free(infomap->map[i]);
    }
    free(infomap->basic_map);
    free(infomap->map);
}

void color(void)
{
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    init_pair(3, COLOR_BLACK, COLOR_CYAN);
    init_pair(4, COLOR_BLACK, COLOR_GREEN);
    init_pair(5, COLOR_BLACK, COLOR_RED);
    init_pair(6, COLOR_BLACK, COLOR_BLACK);
}

int my_sokoban(char *path)
{
    infomap_t *infomap = malloc(sizeof(infomap_t));
    if (infomap == NULL)
        return 84;
    readfile(infomap, path);
    getinfo(infomap);
    getbasicmap(infomap);
    get_o(infomap);
    handle_error(infomap);
    initscr();
    color();
    keypad(stdscr, TRUE);
    refresh();
    while (actions(infomap));
    sleep(2);
    endwin();
    free_all(infomap);
    return 0;
}