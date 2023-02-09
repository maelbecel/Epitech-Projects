/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

void move_game_elements(scene_t *scenes, sfRenderWindow *window)
{
    int el = 0;
    while(scenes[1].elements[el]) {
        move_rect(&scenes[1].elements[el]->rect,
        scenes[1].elements[el]->rect.width,
        scenes[1].elements[el]->rect.width *
        (scenes[1].elements[el]->max_sprite - 2));
        draw_element(window, scenes[1].elements[el++]);
    }
}

void draw_monster(game_t *game, sfRenderWindow *window)
{
    int m = 0;

    while(game->monster[m]){
        if (game->monster[m]->monster->rect.left >
            game->monster[m]->monster->rect.width *
            (game->monster[m]->monster->max_sprite - 2))
            game->monster[m]->monster->rect.left = 0;
        else
            game->monster[m]->monster->rect.left +=
            game->monster[m]->monster->rect.width;
        check_monster(game->monster[m], game->directions, game->speed);
        if (game->monster[m]->monster->pos.x >= 1815) {
            game->life -= 5;
            sfMusic_stop(game->die);
            sfMusic_play(game->die);
            game->monster = delete_monster(game->monster, m);
        }
        monster_is_kill(game->monster, m);
        draw_element(window, game->monster[m]->monster);
        m++;
    }
}