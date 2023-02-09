/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mydefender-mael1.becel
** File description:
** tower
*/

#include "my.h"
#include "printf.h"
#include "defender.h"


void buy_tower_elec(scene_t *scenes, ...)
{
    va_list arg;
    va_start(arg, scenes);
    menu_t *menu = va_arg(arg, menu_t*);
    game_t *game = va_arg(arg, game_t*);
    if (!menu->is_tower) {
        create_tower_elec(game, (sfVector2f){menu->x, menu->y});
    }
    va_end(arg);
}

void buy_tower_fire(scene_t *scenes, ...)
{
    va_list arg;
    va_start(arg, scenes);
    menu_t *menu = va_arg(arg, menu_t*);
    game_t *game = va_arg(arg, game_t*);
    if (!menu->is_tower) {
        create_tower_fire(game, (sfVector2f){menu->x, menu->y});
    }
    va_end(arg);
}

void buy_tower_ice(scene_t *scenes, ...)
{
    va_list arg;
    va_start(arg, scenes);
    menu_t *menu = va_arg(arg, menu_t*);
    game_t *game = va_arg(arg, game_t*);
    if (!menu->is_tower) {
        create_tower_ice(game, (sfVector2f){menu->x, menu->y});
    }
    va_end(arg);
}

void buy_tower_poison(scene_t *scenes, ...)
{
    va_list arg;
    va_start(arg, scenes);
    menu_t *menu = va_arg(arg, menu_t*);
    game_t *game = va_arg(arg, game_t*);
    if (!menu->is_tower) {
        create_tower_poison(game, (sfVector2f){menu->x, menu->y});
    }
    va_end(arg);
}