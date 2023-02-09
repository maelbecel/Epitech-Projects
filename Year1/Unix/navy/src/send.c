/*
** EPITECH PROJECT, 2021
** send
** File description:
** send.c
*/

#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include <signal.h>
#include "navy.h"

void sendletter(char c, int pid)
{
    int n = c - 'A' - 1;
    for (int i = 0; i <= n; i++) {
        usleep(5000);
        kill(pid,SIGUSR1);
    }
    usleep(5000);
    kill(pid,SIGUSR2);
}

void sendnumber(char c, int pid)
{
    int n = c - '1';
    for (int i = 0; i <= n; i++) {
        usleep(5000);
        kill(pid,SIGUSR1);
    }
    usleep(5000);
    kill(pid,SIGUSR2);
}

int send(char *pos, int pid)
{
    usleep(5000);
    sendletter(pos[0],pid);
    sendnumber(pos[1],pid);
    return 0;
}
