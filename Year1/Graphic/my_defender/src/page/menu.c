/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mydefender-mael1.becel
** File description:
** menu
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

void draw_menu(sfRenderWindow *window, game_t *game, int type)
{
    int b = 0;
    int e = 0;
    tower_t *tmp;

    while (game->menu_tower[type].elements[e])
        draw_element(window, game->menu_tower[type].elements[e++]);
    while (game->menu_tower[type].buttons[b]) {
        game->menu_tower[type].buttons[b]->base->scale =
        (sfVector2f){0.15, 0.15};
        draw_button(window, game->menu_tower[type].buttons[b++]);
    }
    if (type == TOWER) {
        tmp = check_tower(game);
        draw_text("+100$", 20, (sfVector2f){1660, 130}, window);
        draw_text("-200$", 20, (sfVector2f){1810, 130}, window);
        draw_text("Level: ", 40, (sfVector2f){1620, 190}, window);
        draw_text((tmp->level == 10) ? "MAX" : inttochar(tmp->level), 40,
        (sfVector2f){1770, 190}, window);
        draw_text("Damage: ", 40, (sfVector2f){1620, 240}, window);
        draw_text(inttochar(tmp->damage), 40, (sfVector2f){1790, 240}, window);
        draw_text("Range: ", 40, (sfVector2f){1620, 290}, window);
        draw_text(inttochar(tmp->range / TILE_SIZE), 40,
        (sfVector2f){1770, 290}, window);
    } else {
        draw_text("-100$", 20, (sfVector2f){1660, 110}, window);
        draw_text("-100$", 20, (sfVector2f){1810, 110}, window);
        draw_text("-100$", 20, (sfVector2f){1660, 250}, window);
        draw_text("-100$", 20, (sfVector2f){1810, 250}, window);
    }
}

button_t **buttons_menu(void)
{
    button_t **buttons = malloc(sizeof(button_t) * 5);
    buttons[0] = init_button("", "resource/UI/TowerButtons/button_1.png",
                    (sfVector2f){1630, 20}, (sfVector2i){100, 120});
    buttons[0]->action_clicked = buy_tower_poison;
    buttons[1] = init_button("", "resource/UI/TowerButtons/button_2.png",
                    (sfVector2f){1780, 20}, (sfVector2i){100, 120});
    buttons[1]->action_clicked = buy_tower_fire;
    buttons[2] = init_button("", "resource/UI/TowerButtons/button_3.png",
                    (sfVector2f){1630, 160}, (sfVector2i){100, 120});
    buttons[2]->action_clicked = buy_tower_elec;
    buttons[3] = init_button("", "resource/UI/TowerButtons/button_4.png",
                    (sfVector2f){1780, 160}, (sfVector2i){100, 120});
    buttons[3]->action_clicked = buy_tower_ice;
    buttons[4] = NULL;
    return buttons;
}

element_t **elements_menu(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);
    elements[0] = init_element("resource/UI/TooltipBackground1.png",
                    (sfVector2f){1595,0}, (sfVector2f){1920,1080},
                    (sfVector2f){0.3, 0.3});
    elements[1] = NULL;
    return elements;
}

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t) * 2);
    menu[NO_TOWER].buttons = buttons_menu();
    menu[NO_TOWER].elements = elements_menu();
    menu[NO_TOWER].is_tower = false;
    menu[TOWER].buttons = buttons_menu_tower();
    menu[TOWER].elements = elements_menu_tower();
    menu[TOWER].is_tower = false;
    return menu;
}