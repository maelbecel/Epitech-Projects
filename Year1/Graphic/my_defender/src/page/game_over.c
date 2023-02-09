/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mydefender-mael1.becel
** File description:
** anim
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

element_t **game_over_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 4);
    elements[0] = init_element("resource/UI/Background.png", (sfVector2f){0,0},
                                (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    elements[1] = init_element("resource/UI/TooltipBackground1.png",
                                (sfVector2f){570,120},
        (sfVector2f){1082, 1068}, (sfVector2f){0.7, 0.2});
    elements[2] = init_element("resource/UI/TooltipBackground1.png",
                                (sfVector2f){570,420},
        (sfVector2f){1082, 1068}, (sfVector2f){0.7, 0.2});
    elements[3] = NULL;
    return elements;
}

button_t **game_over_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 4);
    buttons[0] = init_button("Play again", "resource/UI/TitleStats.png",
                        (sfVector2f){0, 750}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = go_game;
    buttons[1] = init_button("Menu", "resource/UI/TitleStats.png",
                        (sfVector2f){630, 750}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = menu;
    buttons[2] = init_button("Quit", "resource/UI/TitleStats.png",
                        (sfVector2f){1260, 750}, (sfVector2i){300, 100});
    buttons[2]->action_clicked = quit;
    buttons[3] = NULL;
    return buttons;
}
