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
        my_exit(ERROR_MAP, 84);
    infomap->buffer = malloc(infomap->size);
    read(infomap->fd, infomap->buffer, infomap->size);
    infomap->buffer[infomap->size - 1] = '\0';
    close(infomap->fd);
}

void handle_error(infomap_t *infomap)
{
    int nbx = 0;

    for (int i = 0; i < infomap->size; i++) {
        if (infomap->buffer[i] == 'X')
            nbx++;
        if (infomap->buffer[i] != 'X' &&
            infomap->buffer[i] != 'O' &&
            infomap->buffer[i] != '#' &&
            infomap->buffer[i] != '\n' &&
            infomap->buffer[i] != ' ' &&
            infomap->buffer[i] != '\0' &&
            infomap->buffer[i] != 'P') {
            my_printf("'%c'", infomap->buffer[i]);
            my_exit(ERROR_FORMAT, 84);
            }
    }
    if (infomap->nbo > nbx)
        my_exit(ERROR_O, 84);
    else if (infomap->nbo < nbx)
        my_exit(ERROR_X, 84);
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
    free(infomap);
}

int my_sokoban(char *path)
{
    infomap_t *infomap = malloc(sizeof(infomap_t));
    if (infomap == NULL)
        return 84;
    readfile(infomap, path);
    parsemap(infomap);
    getinfo(infomap);
    getbasicmap(infomap);
    get_o(infomap);
    handle_error(infomap);
    initscr();
    keypad(stdscr, TRUE);
    refresh();
    while (actions(infomap));
    endwin();
    free_all(infomap);
    return 0;
}
