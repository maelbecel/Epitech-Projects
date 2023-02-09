/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

void help(scene_t *scenes, ...)
{
    scenes->page = 2;
}

element_t **help_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);
    elements[0] = init_element("resource/UI/Mainmenu.png", (sfVector2f){0,0},
        (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    elements[1] = NULL;
    return elements;
}

button_t **help_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 3);
    buttons[0] = init_button("", "resource/UI/TooltipBackground.png",
        (sfVector2f){420, 0}, (sfVector2i){500, 500});
    buttons[0]->action_clicked = do_none;
    buttons[0]->action_hoover = do_none;
    buttons[1] = init_button("Menu", "resource/UI/TitleStats.png",
        (sfVector2f){650, 820}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = menu;
    buttons[2] = NULL;
    return buttons;
}
