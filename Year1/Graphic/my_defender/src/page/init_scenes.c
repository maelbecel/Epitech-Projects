/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

scene_t *init_info(void)
{
    scene_t *scenes = malloc(sizeof(scene_t));
    scenes->buttons = info_buttons();
    scenes->elements = info_elements();
    return scenes;
}

scene_t *init_scenes(game_t *game)
{
    scene_t *scenes = malloc(sizeof(scene_t) * 5);
    scenes->page = 0;
    scenes[0].buttons = main_menu_buttons();
    scenes[0].elements = main_menu_elements();
    scenes[1].buttons = game_buttons(game);
    scenes[1].elements = game_elements();
    scenes[1].elements[0]->pos = get_start(game);
    scenes[1].elements[1]->pos = get_start(game);
    scenes[1].elements[2]->pos = get_last(game);
    scenes[1].elements[3]->pos = get_last(game);
    scenes[1].menu_tower = false;
    scenes[2].elements = help_elements();
    scenes[2].buttons = help_buttons();
    scenes[3].elements = help_elements();
    scenes[3].buttons = pause_buttons();
    scenes[4].elements = game_over_elements();
    scenes[4].buttons = game_over_buttons();
    game->info = init_info();
    game->score = 0;
    game->money = 200;
    game->life = 100;
    game->page = 0;
    return scenes;
}
