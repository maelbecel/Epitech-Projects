/*
** EPITECH PROJECT, 2021
** clock
** File description:
** clock.c
*/

#include "my.h"
#include "runner.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>

clocking_t *init_clock(void)
{
    clocking_t *clocking = malloc(sizeof(clocking_t));
    clocking->clock = sfClock_create();
    clocking->time = sfClock_getElapsedTime(clocking->clock);
    clocking->seconds = 0;
    return clocking;
}

clocking_t **createclocks(void)
{
    clocking_t **clock = malloc(sizeof(clocking_t *)* 8);
    clock[0] = init_clock();
    clock[1] = init_clock();
    clock[2] = init_clock();
    clock[3] = init_clock();
    clock[4] = init_clock();
    clock[5] = init_clock();
    clock[6] = init_clock();
    return clock;
}

void update_clocks(clocking_t **clocks)
{
    for (int i = 0; i < 7; i++) {
        clocks[i]->time = sfClock_getElapsedTime(clocks[i]->clock);
        clocks[i]->seconds = clocks[i]->time.microseconds / 1000000.0;
    }
}

int check_clocks(game_object **game, game_object **objects,
                    clocking_t **clocks, gameinfo_t *info)
{
    update_clocks(clocks);
    if (clocks[0]->seconds > info->level_speed * 10) {
        move_all(game);
        sfClock_restart(clocks[0]->clock);
    }
    if (clocks[1]->seconds > 0.1) {
        sfClock_restart(clocks[1]->clock);
        return move_main(game, clocks[2], objects);
    }
    if (clocks[3]->seconds > info->level_speed) {
        sfClock_restart(clocks[3]->clock);
        return move_object(objects, info, clocks, game);
    }
    if (clocks[4]->seconds > 1 && info->infini == 1) {
        create_element(objects, info);
        sfClock_restart(clocks[4]->clock);
    } else if ((info->nb_elements == 0 ||
                objects[info->nb_elements - 1]->pos.x < 1500) &&
                info->infini == 0) {
        if (create_element_from_map(objects, info) == 5)
            return 5;
    }
    if (clocks[5]->seconds > 20) {
        info->level++;
        info->level_speed /= 1.2;
        sfClock_restart(clocks[5]->clock);
    }
    return check_collision(objects, info, clocks[2], game);
}
