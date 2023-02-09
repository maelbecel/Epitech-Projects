/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

int get_nb_monster(monster_t **monster)
{
    int i = 0;
    while(monster[i++] != NULL);
    return i;
}

monster_t **add_monster(monster_t **monster, game_t *game)
{
    int nb_monster = get_nb_monster(monster);
    monster_t **new = malloc(sizeof(monster_t *) * (nb_monster + 2));
    int i = 0;

    while(monster[i] != NULL) {
        new[i] = monster[i];
        i++;
    }
    new[i] = create_monster(game, i);
    new[i + 1] = malloc(sizeof(monster_t));
    new[i + 1] = NULL;
    free(monster);
    return new;
}

void display_monster(monster_t **monster)
{
    int i = 0;
    while(monster[i] != NULL) {
        i++;
    }
}

monster_t **delete_monster(monster_t **monster, int id)
{
    int nb_monster = get_nb_monster(monster);
    monster_t **new = malloc(sizeof(monster_t *) * (nb_monster + 1));
    int i = 0;
    int j = 0;
    while(monster[j] != NULL) {
        if (monster[j]->id != id) {
            new[i] = monster[j];
            new[i]->id = i;
            i++;
        }
        j++;
    }
    new[i] = malloc(sizeof(monster_t));
    new[i] = NULL;
    return new;
}

void monster_is_kill(monster_t **monster, int id)
{
    if (monster[id]->life <= 0)
        monster = delete_monster(monster, id);
}
