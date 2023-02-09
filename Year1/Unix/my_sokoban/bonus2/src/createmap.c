/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "sokoban.h"

void initmap(infomap_t *infomap)
{
    for (int i = 0; i < infomap->row; i++) {
        for (int j = 0; j < infomap->col; j++)
            infomap->map[i][j] = ' ';
        infomap->map[i][infomap->col] = '\0';
    }
    infomap->map[infomap->row] = NULL;
}

void parsemap(infomap_t *infomap)
{
    int x = 0;

    get_row(infomap);
    get_col(infomap);
    infomap->map = malloc(sizeof(char *) * infomap->row + 1);
    if (infomap->map == NULL)
        exit(84);
    for (int i = 0; i < infomap->row; i++) {
        infomap->map[i] = malloc(sizeof(char) * infomap->col + 1);
        if (infomap->map[i] == NULL)
            exit(84);
    }
    initmap(infomap);
    for (int i = 0; i < infomap->row; i++) {
        for (int j = 0; infomap->buffer[x] != '\n' &&
            x < infomap->size; j++, x++)
            infomap->map[i][j] = infomap->buffer[x];
        x++;
    }
}

void getbasicmap(infomap_t *infomap)
{
    infomap->basic_map = malloc(sizeof(char *) * infomap->row);
    for (int i = 0; i < infomap->row; i++) {
        infomap->basic_map[i] = malloc(infomap->col + 1);
        for (int j = 0; j < infomap->col; j++) {
            infomap->basic_map[i][j] =
            (infomap->map[i][j] == 'P' || infomap->map[i][j] == 'X') ?
            ' ': infomap->map[i][j];
        }
        infomap->basic_map[i][infomap->col] = '\0';
    }
}
