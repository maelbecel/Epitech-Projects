/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

void menu(scene_t *scenes, ...)
{
    scenes->page = 0;
}

element_t **main_menu_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);
    elements[1] = NULL;
    elements[0] = init_element("resource/UI/Mainmenu.png", (sfVector2f){0,0},
                                (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    return elements;
}

button_t **main_menu_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 4);
    buttons[0] = init_button("Play", "resource/UI/TitleStats.png",
                        (sfVector2f){1200, 150}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = go_game;
    buttons[1] = init_button("Help", "resource/UI/TitleStats.png",
                        (sfVector2f){1200, 400}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = help;
    buttons[2] = init_button("Quit", "resource/UI/TitleStats.png",
                        (sfVector2f){1200, 650}, (sfVector2i){300, 100});
    buttons[2]->action_clicked = quit;
    buttons[3] = NULL;
    return buttons;
}