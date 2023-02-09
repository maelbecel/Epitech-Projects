/*
** EPITECH PROJECT, 2021
** hit or miss
** File description:
** hit or miss
*/

#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include <signal.h>
#include <string.h>
#include "navy.h"
#include <stdio.h>

void attack_result(char *input, map_t *maps)
{
    if (waitchoose(MISSED, HIT) == 1) {
        maps->enemy_map[input[1] - '1'][input[0] - 'A'] = 'o';
        printf("\n%s: missed\n",input);
    } else {
        maps->enemy_map[input[1] - '1'][input[0] - 'A'] = 'x';
        printf("\n%s: hit\n",input);
    }
}

void defence_result(int pid, map_t *maps)
{
    wait(END);
    if (checkmap(GAME.last_letter, GAME.last_number, maps->my_map) == 1) {
        my_printf(": hit\n\n");
        maps->my_map[GAME.last_number - '1'][GAME.last_letter - 'A'] = 'x';
        send(HIT,pid);
    } else {
        maps->my_map[GAME.last_number - '1'][GAME.last_letter - 'A'] = 'o';
        my_printf(": missed\n\n");
        send(MISSED,pid);
    }
}
