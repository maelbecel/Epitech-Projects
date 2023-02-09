/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mydefender-mael1.becel
** File description:
** anim
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

void move_rect(sfIntRect *rect, int offset, int maxvalue)
{
    if (rect->left + offset >= maxvalue) {
        rect->left = 0;
    }
    else {
        rect->left += offset;
    }
}

void anim_tower(sfRenderWindow *window, tower_t *head)
{
    move_rect(&head->tower->rect, 80, 1200);
    sfSprite_setTextureRect(head->tower->sprite, head->tower->rect);
    sfSprite_setPosition(head->tower->sprite, head->tower->pos);
    sfRenderWindow_drawSprite(window, head->tower->sprite, NULL);
}