/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "sokoban.h"

void get_row(infomap_t *infomap)
{
    infomap->row = 0;
    for (int i = 0; i < infomap->size; i++)
        if (infomap->buffer[i] == '\n')
            infomap->row++;
    infomap->row++;
}

void get_col(infomap_t *infomap)
{
    char *temp = malloc(infomap->size);

    infomap->col = 0;
    for (int i = 0; i < infomap->size; i++) {
        for (int x = 0; i < infomap->size && infomap->buffer[i] != '\n'; i++) {
            temp[x++] = infomap->buffer[i];
            temp[x] = '\0';
        }
        if (infomap->col < my_strlen(temp))
            infomap->col = my_strlen(temp);
        temp[0] = '\0';
    }
    infomap->col++;
}

void get_o(infomap_t *infomap)
{
    infomap->nbo = 0;
    for (int i = 0; i < infomap->row; i++)
        for (int j = 0; j < infomap->col; j++)
            infomap->nbo = (infomap->map[i][j] == 'O') ?
            infomap->nbo + 1: infomap->nbo;
    if (infomap->basic_map[infomap->posy][infomap->posx] == 'O')
        infomap->nbo++;
}

int get_p(infomap_t *infomap, int i)
{
    int nbp = 0;
    for (int j = 0; j < infomap->col; j++)
        if (infomap->map[i][j] == 'P') {
            infomap->posx = j;
            infomap->posy = i;
            nbp++;
        }
    return nbp;
}

void getinfo(infomap_t *infomap)
{
    int nbp = 0;
    for (int i = 0; i < infomap->row; i++)
        nbp += get_p(infomap, i);
    if (nbp < 1)
        my_exit(ERROR_FEW_P, 84);
    else if (nbp > 1)
        my_exit(ERROR_MNY_P, 84);
}