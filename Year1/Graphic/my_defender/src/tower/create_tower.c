/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mydefender-mael1.becel
** File description:
** create_tower
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

void create_tower_elec(game_t *game, sfVector2f pos)
{
    if (game->head->id == 0)
        game->head = create_first_tower("elec", 300, 60, pos);
    else
        game->head = create_other_tower("elec", game->head, 400, 60, pos);
}

void create_tower_fire(game_t *game, sfVector2f pos)
{
    if (game->head->id == 0)
        game->head = create_first_tower("fire", 100, 150, pos);
    else
        game->head = create_other_tower("fire", game->head, 200, 150, pos);
}

void create_tower_ice(game_t *game, sfVector2f pos)
{
    if (game->head->id == 0)
        game->head = create_first_tower("ice", 150, 100, pos);
    else
        game->head = create_other_tower("ice", game->head, 250, 100, pos);
}

void create_tower_poison(game_t *game, sfVector2f pos)
{
    if (game->head->id == 0)
        game->head = create_first_tower("poison", 120, 120, pos);
    else
        game->head = create_other_tower("poison", game->head, 220, 120, pos);
}