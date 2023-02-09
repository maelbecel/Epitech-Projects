/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mydefender-mael1.becel
** File description:
** anim
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

void draw_text(char *text, int size, sfVector2f pos, sfRenderWindow *window)
{
    sfText *score = sfText_create();
    sfText_setColor(score, sfBlack);
    sfText_setString(score, text);
    sfText_setFont(score, sfFont_createFromFile(POLICE));
    sfText_setCharacterSize(score, size);
    sfText_setPosition(score, pos);
    sfRenderWindow_drawText(window, score, NULL);
    sfText_destroy(score);
}