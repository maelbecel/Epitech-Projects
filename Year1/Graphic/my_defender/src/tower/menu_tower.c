/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mydefender-mael1.becel
** File description:
** menu_tower
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

void draw_menu_tower(sfRenderWindow *window, game_t *game)
{
    int b = 0;
    int e = 0;

    while (game->menu_tower[TOWER].elements[e])
        draw_element(window, game->menu_tower[TOWER].elements[e++]);
    while (game->menu_tower[TOWER].buttons[b]) {
        game->menu_tower[TOWER].buttons[b]->base->scale =
        (sfVector2f){0.15, 0.15};
        draw_button(window, game->menu_tower[TOWER].buttons[b++]);
    }
}

button_t **buttons_menu_tower(void)
{
    button_t **buttons = malloc(sizeof(button_t) * 3);
    buttons[0] = init_button("", "resource/UI/TowerButtons/sell_button.png",
                    (sfVector2f){1630, 45}, (sfVector2i){100, 120});
    buttons[0]->action_clicked = destroy_tower;
    buttons[1] = init_button("", "resource/UI/TowerButtons/upgrade_button.png",
                    (sfVector2f){1780, 45}, (sfVector2i){100, 120});
    buttons[1]->action_clicked = upgrade_tower;
    buttons[2] = NULL;
    return buttons;
}

element_t **elements_menu_tower(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);
    elements[0] = init_element("resource/UI/TooltipBackground1.png",
                    (sfVector2f){1595,0}, (sfVector2f){1920,1080},
                    (sfVector2f){0.3, 0.35});
    elements[1] = NULL;
    return elements;
}

void change_buttons(scene_t *scenes, menu_t *menu)
{
    for (int i = 0; scenes[1].buttons[i]; i++) {
        if (scenes[1].buttons[i]->pos.x == menu->x &&
            scenes[1].buttons[i]->pos.y == menu->y){
            scenes[1].buttons[i]->is_tower = true;
            scenes[1].buttons[i]->action_clicked = menu_tower;
        }
    }
}