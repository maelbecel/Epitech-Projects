/*
** EPITECH PROJECT, 2022
** tetris.c
** File description:
** tetris
*/

#include "my.h"
#include "printf.h"
#include "tetris.h"

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    game->info = init_info();
    game->key = init_keys();
    game->i = 0;
    game->nbcol = 10;
    game->nbrow = 20;
    game->level = 1;
    game->map = init_map(game);
    game->tetrimino = load_tetrimino(game);
    game->debug = false;
    game->next = true;
    game->open = true;
    game->help = false;
    return game;
}

keys_t *init_keys(void)
{
    keys_t *keys = malloc(sizeof(keys_t));
    keys->left = KEY_LEFT;
    keys->right = KEY_RIGHT;
    keys->turn = KEY_UP;
    keys->drop = KEY_DOWN;
    keys->quit = 'q';
    keys->pause = ' ';
    return keys;
}

info_t *init_info(void)
{
    info_t *info = malloc(sizeof(info_t));
    info->high_score = 0;
    info->score = 0;
    info->lines = 0;
    info->level = 1;
    info->timer = 0;
    return info;
}

element_t **init_map(game_t *game)
{
    element_t **map = malloc(sizeof(element_t *) * game->nbrow);
    for (int i = 0; i < game->nbrow; i++) {
        map[i] = malloc(sizeof(element_t) * game->nbcol);
        for (int j = 0; j < game->nbcol; j++)
            map[i][j] = (element_t){' ', 1};
    }
    return map;
}

void color(void)
{
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);
    init_pair(7, COLOR_BLACK, COLOR_BLACK);
}