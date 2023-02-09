/*
** EPITECH PROJECT, 2022
** B-PSU-200-REN-2-1-tetris-mael1.becel
** File description:
** tetrimino
*/

#include "my.h"
#include "printf.h"
#include "tetris.h"

tetristoune_t *init_tetrimino(char *path, game_t *game)
{
    FILE *file;
    tetristoune_t *tet= malloc(sizeof(tetristoune_t));
    char **obj;
    char *buffer = malloc(sizeof(char) * 10);
    int end;
    int i = 0;
    size_t size = 10;
    file = fopen(path,  "r");
    end = getline(&buffer, &size, file);
    buffer[end - 1] = '\0';
    obj = my_str_to_word_array(buffer, ' ');
    tet->nbcol = my_getnbr(obj[0]);
    tet->nbrow = my_getnbr(obj[1]);
    tet->color = my_getnbr(obj[2]);
    tet->pos = (pos_t){(game->nbcol - tet->nbcol) / 2, 0};
    tet->form = malloc(sizeof(char *) * (tet->nbrow + 1));
    size = 0;
    for (; i < tet->nbrow; i++) {
        tet->form[i] = NULL;
        // tet->form[i] = malloc(sizeof(char) * tet->nbcol);
        end = getline(&tet->form[i], &size, file);
        tet->form[i][end - 1] = '\0';
    }
    tet->form[i] = NULL;
    return tet;
}

tetristoune_t **load_tetrimino(game_t* game)
{
    tetristoune_t **tetrimino = malloc(sizeof(tetristoune_t *) * (6 + 1));

    tetrimino[6] = NULL;
    tetrimino[0] = init_tetrimino("tetriminos/5.tetrimino", game);
    tetrimino[1] = init_tetrimino("tetriminos/6.tetrimino", game);
    tetrimino[2] = init_tetrimino("tetriminos/7.tetrimino", game);
    tetrimino[3] = init_tetrimino("tetriminos/bar.tetrimino", game);
    tetrimino[4] = init_tetrimino("tetriminos/inverted-L.tetrimino", game);
    tetrimino[5] = init_tetrimino("tetriminos/square.tetrimino", game);
    return tetrimino;
}