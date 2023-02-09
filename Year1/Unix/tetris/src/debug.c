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

char *conc(char *a, char *b)
{
    char *res = malloc(my_strlen(a) + my_strlen(b) + 1);
    int x = 0;

    for (int i = 0; i < my_strlen(a); i++, x++)
        res[x] = a[i];
    for (int i = 0; i < my_strlen(b); i++, x++)
        res[x] = b[i];
    res[x] = '\0';
    return res;
}

int get_tetrimino(char *filename)
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
        my_printf("error\n");
        return 84;
    }
    tet->nbcol = my_getnbr(obj[0]);
    tet->color = my_getnbr(obj[2]);
    tet->nbrow = my_getnbr(obj[1]);

    my_printf("size %i*%i, color %i\n", tet->nbrow, tet->nbcol, tet->color);
    size = tet->nbcol;
    for (int i = 0; i < tet->nbrow; i++) {
        end = getline(&buffer, &size, file);
        buffer[end - 1] = '\0';
        my_printf("%s\n", buffer);
    }
    return 0;
}

int filter_files(const struct dirent *dir)
{
    if (dir->d_type == 8)
        return 1;
    return 0;
}

char *getname(char *filename)
{
    char **array = my_str_to_word_array(filename, '.');
    return array[0];
}

int getnb_tetrimino(void)
{
    struct dirent **namelist;
    int n;

    n = scandir("./tetriminos", &namelist, filter_files, alphasort);
    my_printf("Number of tetriminos: %i\n", n);
    while (n--) {
        my_printf("Tetriminos '%s': ", getname(namelist[n]->d_name));
        get_tetrimino(namelist[n]->d_name);
        free(namelist[n]);
    }
    free(namelist);
    return 0;
}


void print_key(char *start, int key)
{
    my_printf("%s ", start);
    switch (key) {
        case 258 : my_printf("KEY_DOWN");
            break;
        case 259 : my_printf("KEY_UP");
            break;
        case 260 : my_printf("KEY_LEFT");
            break;
        case 261 : my_printf("KEY_RIGHT");
            break;
        default : my_printf("%c", key);
    }
    my_printf(" (%i)\n", key);

}

void debug(game_t *game)
{
    print_key("Key left:", game->key->left);
    print_key("Key right:", game->key->right);
    print_key("Key turn:", game->key->turn);
    print_key("Key drop:", game->key->drop);
    print_key("Key quit:", game->key->quit);
    print_key("Key pause:", game->key->pause);
    my_printf("Next: %s\n", (game->next) ? "Yes" : "No");
    my_printf("Level: %i\n", game->level);
    my_printf("Size: %i*%i\n", game->nbrow, game->nbcol);
    getnb_tetrimino();
}