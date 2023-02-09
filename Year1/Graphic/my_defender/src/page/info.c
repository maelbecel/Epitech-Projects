/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

element_t **info_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 8);
    elements[0] = init_element("resource/UI/Moneybar.png",
                                (sfVector2f){10, 22}, (sfVector2f){691, 93},
                                (sfVector2f){0.4, 0.8});
    elements[1] = init_element("resource/UI/coin.png", (sfVector2f){15, 37},
                                (sfVector2f){900, 500},
                                (sfVector2f){0.08, 0.08});
    elements[2] = init_element("resource/UI/Moneybar.png",
                                (sfVector2f){570, 22}, (sfVector2f){691, 93},
                                (sfVector2f){1.2, 0.8});
    elements[3] = init_element("resource/UI/Healthbar.png",
                                (sfVector2f){690, 32}, (sfVector2f){70, 10},
                                (sfVector2f){10, 5});
    elements[4] = init_element("resource/UI/heart.png", (sfVector2f){600, 26},
                                (sfVector2f){210, 174},
                                (sfVector2f){0.34, 0.34});
    elements[5] = init_element("resource/UI/Moneybar.png",
                                (sfVector2f){10, 102}, (sfVector2f){691, 93},
                                (sfVector2f){0.4, 0.8});
    elements[6] = init_element("resource/UI/dead.png", (sfVector2f){25, 117},
                                (sfVector2f){900, 500},
                                (sfVector2f){0.08, 0.08});
    elements[7] = NULL;
    return elements;
}

button_t **info_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 1);
    buttons[0] = NULL;
    return buttons;
}