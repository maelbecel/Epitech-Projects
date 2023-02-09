/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

int get_distance(sfVector2f from, sfVector2f to)
{
    int x = from.x - to.x;
    int y = from.y - to.y;

	return sqrt((x * x) + (y * y));
}

void attack(tower_t *tower, monster_t **monster, sfRenderWindow *window)
{
    int e = 0;

    while(monster[e] != NULL) {
        if (get_distance(monster[e]->monster->pos, tower->tower->pos)
            < tower->range) {
            display_attack(monster[e], tower, window);
            monster[e]->life -= tower->damage;
        }
        e++;
    }
    return;
}

void towers_attack(game_t *game)
{
    int e = 0;
    tower_t *tmp = game->head;

    if (game->head->id != 0)
        for (; tmp != NULL;) {
            attack(tmp, game->monster, game->window);
            tmp = tmp->next;
        }
    while(game->monster[e]) {
        if (game->monster[e++]->life <= 0) {
            game->monster = delete_monster(game->monster, e - 1);
            game->speed = (game->speed < 15) ? game->speed + 1 : game->speed;
            game->money += 50;
            game->kill += 1;
        }
    }
}