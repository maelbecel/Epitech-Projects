/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

element_t **init_save_pic(void)
{
    element_t **save_pic = malloc(sizeof(element_t *) * 4);

    save_pic[0] = init_element("saves/pictures/save1.jpeg", (sfVector2f) {100, 225},
        (sfVector2f) {1200, 675}, (sfVector2f) {0.1, 0.1});
    save_pic[1] = init_element("saves/pictures/save2.jpeg", (sfVector2f) {100, 475},
        (sfVector2f) {1200, 675}, (sfVector2f) {0.1, 0.1});
    save_pic[2] = init_element("saves/pictures/save3.jpeg", (sfVector2f) {100, 725},
        (sfVector2f) {1200, 675}, (sfVector2f) {0.1, 0.1});
    save_pic[3] = NULL;

    for (int i = 0; i < 3; i++) {
        if (!(save_pic[i]))
            save_pic[i] = init_element("saves/pictures/nopic.jpg", (sfVector2f) {100, 225 + (250 * i)},
            (sfVector2f) {1200, 675}, (sfVector2f) {0.1, 0.1});
    }
    return save_pic;
}
