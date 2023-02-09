/*
** EPITECH PROJECT, 2021
** signal
** File description:
** signal.c
*/

#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include <signal.h>
#include <string.h>
#include "navy.h"

void signal_action(char letter, char number)
{
    if (number != '9'){
        my_printf("%c%c", letter, number);
        GAME.last_letter = letter;
        GAME.last_number = number;
    }
}

void signal_handler(int sign, siginfo_t *info, __attribute__((unused))void *v)
{
    if (sign == SIGUSR1){
        GAME.signals++;
    }else if (sign == SIGUSR2){
        if (GAME.l_or_i == 0){
            GAME.letter = (char)(GAME.signals + 'A');
        }else{
            GAME.number = (char)(GAME.signals + '0');
            GAME.enemy_pid = (int)info->si_pid;
            usleep(5000);
            signal_action(GAME.letter, GAME.number);
        }
        GAME.signals = 0;
        GAME.l_or_i = (GAME.l_or_i + 1) % 2;
    }
}

void register_signal(void)
{
    struct sigaction act = {0};

    act.sa_sigaction = signal_handler;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
}
