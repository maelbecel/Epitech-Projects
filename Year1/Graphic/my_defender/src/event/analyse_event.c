/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mydefender-mael1.becel
** File description:
** analyse_event
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

static bool is_button_clicked(sfRenderWindow *window, sfVector2f pos,
        sfVector2f scale, sfTexture *texture)
{
    sfVector2u size = sfTexture_getSize(texture);
    sfVector2i click = sfMouse_getPositionRenderWindow(window);

    size.x *= scale.x;
    size.y *= scale.y;

    if (click.x > pos.x && click.x < (pos.x + size.x)) {
        if (click.y > pos.y && click.y < (pos.y + size.y)) {
            return 1;
        }
    }
    return 0;
}

static void button_game(sfRenderWindow *window, scene_t *scenes, game_t *game)
{
    for (int b = 0; scenes[1].buttons[b]; b++) {
        if (is_button_clicked(window, scenes[1].buttons[b]->pos,
            scenes[1].buttons[b]->base->scale,
            scenes[1].buttons[b]->base->texture)){
            scenes[1].buttons[b]->action_clicked(scenes, 1,
                                                game->menu_tower, b);
        }
    }
}

static void button_menu(sfRenderWindow *window, scene_t *scenes, game_t *game)
{
    for (int b = 0; game->menu_tower->buttons[b]; b++) {
        if (is_button_clicked(window, game->menu_tower->buttons[b]->pos,
            game->menu_tower->buttons[b]->base->scale,
            game->menu_tower->buttons[b]->base->texture) &&
            game->money >= 100) {
            game->menu_tower->buttons[b]->action_clicked(scenes,
                game->menu_tower, game);
            change_buttons(scenes, game->menu_tower);
            sfMusic_stop(game->sound_buy);
            sfMusic_play(game->sound_buy);
            game->money -= 100;
        }
    }
}

static void button_menu_tower(sfRenderWindow *window, scene_t *scenes,
                                game_t *game)
{
    for (int b = 0; game->menu_tower[TOWER].buttons[b]; b++) {
        if (is_button_clicked(window, game->menu_tower[TOWER].buttons[b]->pos,
            game->menu_tower[TOWER].buttons[b]->base->scale,
            game->menu_tower[TOWER].buttons[b]->base->texture)) {
            game->menu_tower[TOWER].buttons[b]->action_clicked(scenes,
                b, game);
            sfMusic_stop(game->sound_buy);
            sfMusic_play(game->sound_buy);
        }
    }
}

int analyse_event(sfRenderWindow *window, sfEvent *event,
                    game_t *game, scene_t *scenes)
{
    if (event->type == sfEvtClosed )
        return 0;
    if (scenes->page == 1 && event->key.code == sfKeyEscape)
        pause_menu(scenes, 0);
    if (event->type == sfEvtMouseButtonPressed &&
        scenes->page == 1 && scenes[1].menu_tower && game->type == NO_TOWER) {
        button_menu(window, scenes, game);
    }
    if (event->type == sfEvtMouseButtonPressed &&
        scenes->page == 1 && scenes[1].menu_tower && game->type == TOWER) {
        button_menu_tower(window, scenes, game);
    }
    if (event->type == sfEvtMouseButtonPressed && scenes->page == 1) {
        button_game(window, scenes, game);
        sfMusic_stop(game->sound_clicked);
        sfMusic_play(game->sound_clicked);
    }
    return 1;
}