/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mydefender-mael1.becel
** File description:
** draw_attack
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

void is_attack(tower_t *tower, monster_t **monster, sfRenderWindow *window)
{
    int e = 0;

    while(monster[e] != NULL) {
        if (get_distance(monster[e]->monster->pos,
                        tower->tower->pos) < tower->range) {
            display_attack(monster[e], tower, window);
        }
        e++;
    }
    return;
}

void draw_attack(game_t *game)
{
    tower_t *tmp = game->head;

    if (game->head->id != 0)
        for (; tmp != NULL;) {
            is_attack(tmp, game->monster, game->window);
            tmp = tmp->next;
        }
}