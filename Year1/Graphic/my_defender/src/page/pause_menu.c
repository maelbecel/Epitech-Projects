/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

void pause_menu(scene_t *scenes, ...)
{
    scenes->page = 3;
}

button_t **pause_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 4);
    buttons[0] = init_button("Resume", "resource/UI/TitleStats.png",
        (sfVector2f){650, 200}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = go_game;
    buttons[1] = init_button("Menu", "resource/UI/TitleStats.png",
        (sfVector2f){650, 400}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = menu;
    buttons[2] = init_button("Quit", "resource/UI/TitleStats.png",
        (sfVector2f){650, 600}, (sfVector2i){300, 100});
    buttons[2]->action_clicked = quit;
    buttons[3] = NULL;
    return buttons;
}