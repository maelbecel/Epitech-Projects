/*
** EPITECH PROJECT, 2022
** tetris.c
** File description:
** tetris
*/

#include "my.h"
#include "printf.h"
#include "tetris.h"
#include <time.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int check_tetrimino(char *filename)
{
    FILE *file;
    tetristoune_t *tet= malloc(sizeof(tetristoune_t));
    char **obj;
    char *buffer = malloc(sizeof(char) * 1024);
    int end;
    size_t size = 1024;

    file = fopen(conc("./tetriminos/", filename),  "r");
    end = getline(&buffer, &size, file);
    buffer[end - 1] = '\0';
    obj = my_str_to_word_array(buffer, ' ');
    if (my_strarraylen(obj) != 3){
        return 0;
    }
    tet->nbcol = my_getnbr(obj[0]);
    tet->color = my_getnbr(obj[2]);
    tet->nbrow = my_getnbr(obj[1]);

    my_printf("size %i*%i, color %i\n", tet->nbrow, tet->nbcol, tet->color);
    size = tet->nbcol;
    for (int i = 0; i < tet->nbrow; i++) {
        end = getline(&buffer, &size, file);
        buffer[end - 1] = '\0';
    }
    return 1;
}

int files(const struct dirent *dir)
{
    if (dir->d_type == 8)
        return 1;
    return 0;
}

int verif_tetrimino(void)
{
    struct dirent **namelist;
    int n;
    int valid = 0;

    n = scandir("./tetriminos", &namelist, files, alphasort);
    while (n--) {
        my_printf("Tetriminos '%s': ", getname(namelist[n]->d_name));
        valid += check_tetrimino(namelist[n]->d_name);
        free(namelist[n]);
    }
    free(namelist);
    if (valid == 0)
        exit(84);
    return 0;
}