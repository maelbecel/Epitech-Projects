/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mydefender-mael1.becel
** File description:
** list
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

sfVector2f get_start(game_t *game)
{
    for (int i = 0; i < MAP_ROW; i++) {
        if (game->map[i][0] == 'A' || game->map[i][0] == 'B') {
            return (sfVector2f){10, (i * TILE_SIZE) + 5};
        }
    }
    return (sfVector2f){100, 100};;
}

sfVector2f get_last(game_t *game)
{
    for (int i = 0; i < MAP_ROW; i++) {
        if (game->map[i][MAP_COL - 1] == 'A' ||
            game->map[i][MAP_COL - 1] == 'B') {
            return (sfVector2f){((MAP_COL - 1) * TILE_SIZE) + 10,
                                (i * TILE_SIZE) + 5};
        }
    }
    return (sfVector2f){100, 100};;
}