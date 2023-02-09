/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mydefender-mael1.becel
** File description:
** list
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

tower_t *create_first_tower(char *type, int range, int damage, sfVector2f pos)
{
    tower_t *tmp = malloc(sizeof(tower_t));
    tmp->type = type;
    tmp->next = NULL;
    tmp->prev = NULL;
    tmp->pos = pos;
    tmp->level = 1;
    tmp->id = 1;
    tmp->range = range;
    tmp->damage = damage;
    tmp->tower = NULL;
    return tmp;
}

tower_t *create_other_tower(char *type, tower_t *head, int range,
                            int damage, sfVector2f pos)
{
    (void) type;
    tower_t *tmp = head;
    tower_t *new = malloc(sizeof(tower_t));

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
    new->next = NULL;
    new->prev = tmp;
    new->level = 1;
    new->pos = pos;
    new->id = new->prev->id + 1;
    new->type = type;
    new->range = range;
    new->damage = damage;
    new->tower = NULL;
    while (tmp->prev != NULL)
        tmp = tmp->prev;
    return tmp;
}

tower_t *check_tower(game_t *game)
{
    tower_t *tmp = game->head;
    for (; tmp != NULL;) {
        if (tmp->pos.x == game->menu_tower->x &&
            tmp->pos.y == game->menu_tower->y)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void destroy_tower(scene_t *scenes, ...)
{
    va_list arg;
    va_start(arg, scenes);
    UNUSED int i = va_arg(arg, int);
    game_t *game = va_arg(arg, game_t *);
    tower_t *tmp = check_tower(game);
    for (int i = 0; scenes[1].buttons[i] != NULL; i++) {
        if (scenes[1].buttons[i]->pos.x == tmp->pos.x &&
            scenes[1].buttons[i]->pos.y == tmp->pos.y)
                scenes[1].buttons[i]->is_tower = false;
    }
    if (tmp->next != NULL && tmp->prev != NULL) {
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
    }
    if (tmp->next != NULL && tmp->prev == NULL) {
        tmp->next->prev = NULL;
        game->head = tmp->next;
    }
    if (tmp->prev != NULL && tmp->next == NULL)
        tmp->prev->next = NULL;
    if (tmp->next == NULL && tmp->prev == NULL)
        tmp->id = 0;
     game->money += 100;
}

void upgrade_tower(scene_t *scenes, ...)
{
    va_list arg;
    va_start(arg, scenes);
    UNUSED int i = va_arg(arg, int);
    game_t *game = va_arg(arg, game_t *);
    tower_t *tmp = check_tower(game);
    if (game->money >= 200 && tmp->level < 10) {
        game->money -= 200;
        tmp->range += tmp->range * 0.2;
        tmp->damage += tmp->damage * 0.2;
        tmp->level++;
    }
}