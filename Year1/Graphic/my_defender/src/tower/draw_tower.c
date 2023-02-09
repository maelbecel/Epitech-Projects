/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mydefender-mael1.becel
** File description:
** draw_menu
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

static element_t *init_tower(char *tower, game_t *game)
{
    if (my_strcmp(tower, "elec") == 0)
        return init_element("resource/Towers/storm_idle.png",
        (sfVector2f){game->menu_tower->x + 20, game->menu_tower->y - 52},
        (sfVector2f){80, 144}, (sfVector2f){1, 1});
    if (my_strcmp(tower, "fire") == 0)
        return init_element("resource/Towers/fire_idle.png",
        (sfVector2f){game->menu_tower->x + 20, game->menu_tower->y - 52},
        (sfVector2f){80, 144}, (sfVector2f){1, 1});
    if (my_strcmp(tower, "ice") == 0)
        return init_element("resource/Towers/ice_idle.png",
        (sfVector2f){game->menu_tower->x + 20, game->menu_tower->y - 52},
        (sfVector2f){80, 144}, (sfVector2f){1, 1});
    if (my_strcmp(tower, "poison") == 0)
        return init_element("resource/Towers/poison_idle.png",
        (sfVector2f){game->menu_tower->x + 20, game->menu_tower->y - 52},
        (sfVector2f){80, 144}, (sfVector2f){1, 1});
    return NULL;
}

static void display_tower(tower_t *head, game_t *game, sfRenderWindow *window)
{
    if (my_strcmp(head->type, "elec") == 0) {
        if (head->tower == NULL)
            head->tower = init_tower(head->type, game);
        else
            anim_tower(window, head);
    }
    if (my_strcmp(head->type, "fire") == 0) {
        if (head->tower == NULL)
            head->tower = init_tower(head->type, game);
        else
            anim_tower(window, head);
    }
    if (my_strcmp(head->type, "ice") == 0) {
        if (head->tower == NULL)
            head->tower = init_tower(head->type, game);
        else
            anim_tower(window, head);
    }
    if (my_strcmp(head->type, "poison") == 0) {
        if (head->tower == NULL)
            head->tower = init_tower(head->type, game);
        else
            anim_tower(window, head);
    }
}

void draw_tower(sfRenderWindow *window, game_t *game)
{
    tower_t *tmp = game->head;
    for (; tmp != NULL;) {
        display_tower(tmp, game, window);
        tmp = tmp->next;
    }
}