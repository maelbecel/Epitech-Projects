/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

void prep_game(game_t *game, scene_t *scenes)
{
    int x = 0;
    game->head = malloc(sizeof(tower_t));
    game->head->id = 0;
    game->monster[0] = NULL;
    game->score = 0;
    game->speed = 2;
    game->money = 200;
    game->kill = 0;
    game->life = 100;
    game->menu_tower->is_tower = false;
    for (size_t i = 0; i < MAP_ROW; i++)
        for (size_t j = 0; j < MAP_COL; j++)
            scenes[1].buttons[x++]->is_tower = false;

}

void tower(scene_t *scenes, ...)
{
    va_list arg;
    va_start(arg, scenes);
    int i = va_arg(arg, int);
    if (scenes[i].menu_tower == true)
        scenes[i].menu_tower = false;
    va_end(arg);
}

void menu_tower(scene_t *scenes, ...)
{
    va_list arg;
    va_start(arg, scenes);
    int i = va_arg(arg, int);
    menu_t *menu = va_arg(arg, menu_t *);
    int b = va_arg(arg, int);
    if (scenes[i].menu_tower == true) {
        scenes[i].menu_tower = false;
    }
    else {
        menu->x = scenes[i].buttons[b]->x;
        menu->y = scenes[i].buttons[b]->y;
        scenes[i].menu_tower = true;
    }
    va_end(arg);
}

void go_game(scene_t *scenes, ...)
{
    scenes->page = 1;
}

button_t **game_buttons(game_t *game)
{
    button_t **buttons = malloc(sizeof(element_t *) *
                                ((MAP_COL + 1 )* MAP_ROW) + 3);
    int x = 0;
    for (size_t i = 0; i < MAP_ROW; i++) {
        for (size_t j = 0; j < MAP_COL; j++) {
            buttons[x] = init_tiles(i, j, game);
            buttons[x]->x = j * 120;
            buttons[x]->y = i * 120;
            buttons[x]->action_hoover = do_none;
            buttons[x]->is_tower = false;
            buttons[x++]->action_clicked = (game->map[i][j] == 'T') ?
            menu_tower : tower;
        }
    }
    game->directions = create_directions(game->map);
    buttons[x] = NULL;
    return buttons;
}


element_t **game_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 5);
    elements[0] = init_element("resource/Portal/blue_idle.png",
            (sfVector2f){0,0}, (sfVector2f){83, 113}, (sfVector2f){1, 1});
    elements[0]->max_sprite = 16;
    elements[1] = init_element("resource/Portal/blue_half.png",
            (sfVector2f){0,0}, (sfVector2f){83, 113}, (sfVector2f){1, 1});
    elements[1]->max_sprite = 16;
    elements[2] = init_element("resource/Portal/red_idle.png",
            (sfVector2f){0,0}, (sfVector2f){83, 113}, (sfVector2f){1, 1});
    elements[2]->max_sprite = 16;
    elements[3] = init_element("resource/Portal/red_half.png",
            (sfVector2f){0,0}, (sfVector2f){83, 113}, (sfVector2f){1, 1});
    elements[3]->max_sprite = 16;
    elements[4] = NULL;
    return elements;
}
