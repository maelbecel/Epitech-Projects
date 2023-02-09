/*
** EPITECH PROJECT, 2021
** wait
** File description:
** wait.c
*/

#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include <signal.h>
#include "navy.h"

int waitchoose(char *signal_a, char *signal_b)
{
    while (1) {
        if (GAME.letter == signal_a[0] && GAME.number == signal_a[1]){
            GAME.letter += 1;
            return 1;
        } else if (GAME.letter == signal_b[0] && GAME.number == signal_b[1]){
            GAME.letter += 1;
            return 2;
        }
        usleep(5000);
    }
}

void wait(char *signal)
{
    while (GAME.letter != signal[0] || GAME.number != signal[1]) {
        usleep(5000);
    }
    GAME.letter += 1;
}

void wait_for_connection(void)
{
    my_printf("waiting for enemy connection ...\n\n");
    while (GAME.letter != 'C' || GAME.number != '9'){
        usleep(5000);
    }
    my_printf("enemy connected...\n",GAME.enemy_pid);
}
