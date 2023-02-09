/*
** EPITECH PROJECT, 2022
** B-PSU-200-REN-2-1-tetris-mael1.becel
** File description:
** display_tet
*/

#include "my.h"
#include "printf.h"
#include "tetris.h"

static void clean_tet(game_t* game)
{
    if (game->tetrimino[5]->pos.y != 0) {
        for (int j = 0; j < game->tetrimino[5]->nbcol; j++) {
            game->map[game->tetrimino[5]->pos.y - 1][game->tetrimino[5]->pos.x + j].c = ' ';
        }
    }

    if (game->tetrimino[5]->pos.x != 0 && game->tetrimino[5]->pos.y != 0) {
        for (int i = 0; i < game->tetrimino[5]->nbrow; i++) {
            game->map[game->tetrimino[5]->pos.y + i - 1][game->tetrimino[5]->pos.x - 1].c = ' ';
        }
    }
    if (game->tetrimino[5]->pos.x != 0 && game->tetrimino[5]->pos.y != 0) {
        for (int i = 0; i < game->tetrimino[5]->nbrow; i++) {
            game->map[game->tetrimino[5]->pos.y + i - 1][game->tetrimino[5]->pos.x + game->tetrimino[5]->nbcol].c = ' ';
        }
    }
}

void display_tet(game_t* game)
{
    for (int i = 0; i < game->tetrimino[5]->nbrow; i++) {
        for (int j = 0; j < game->tetrimino[5]->nbcol; j++) {
            game->map[i + game->tetrimino[5]->pos.y]
                    [game->tetrimino[5]->pos.x + j].c =
                    game->tetrimino[5]->form[i][j];
        }
    }
    clean_tet(game);
    if (game->tetrimino[5]->pos.y < game->nbrow - game->tetrimino[5]->nbrow)
        game->tetrimino[5]->pos.y++;
    else
        game->tetrimino[5]->pos.y = 0;
}