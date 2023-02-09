/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

int is_hoover(sfRenderWindow *window, scene_t *scenes, int b, int s)
{
    sfVector2f pos = scenes[s].buttons[b]->pos;
    sfVector2u size = sfTexture_getSize(scenes[s].buttons[b]->hoover->texture);
    sfVector2i click = sfMouse_getPositionRenderWindow(window);
    if (click.x > pos.x && click.x < (pos.x + size.x)) {
        if (click.y > pos.y && click.y < (pos.y + size.y)) {
            scenes[s].buttons[b]->action_hoover(scenes, b);
            return 1;
        }
    }
    return 0;
}

int is_click(sfRenderWindow *window, scene_t *scenes,
                game_t *game, int b, int s)
{
    if (!is_hoover(window, scenes, b, s) || !sfRenderWindow_isOpen(window))
        return 0;
    (void)game;
    scenes[s].buttons[b]->action_clicked(scenes, s, window, game);
    return 1;
}