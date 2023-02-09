/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include <signal.h>
#include <string.h>
#include "navy.h"
#include "printf.h"
#include <stdlib.h>

catcher_t GAME = {};

void launch_game(int pid, map_t *maps)
{
    char *input = malloc(sizeof(char) * 3);

    usleep(10000);
    displaymaps(maps);
    input = get_input();
    send(input,pid);
    send(END, pid);
    usleep(2000);
    attack_result(input, maps);
}

void client(int pid, map_t *maps)
{
    char *input = malloc(sizeof(char) * 3);

    my_printf("my_pid: %d\nsuccessfully connected\n", pid);
    send(CONNECT, pid);
    register_signal();
    launch_game(pid, maps);
    while (!sink(maps->my_map)) {
        usleep(10000);
        my_printf("\nwaiting for enemy's attack...\n");
        defence_result(pid, maps);
        usleep(4000);
        input = get_input();
        send(input,pid);
        usleep(4000);
        send(END, pid);
        usleep(4000);
        attack_result(input, maps);
        displaymaps(maps);
        input[1] = '\0';
    }
}

void host(map_t *maps)
{
    int pid = getpid();
    char *input = malloc(sizeof(char) * 3);

    my_printf("my_pid: %d\n", pid);
    register_signal();
    wait_for_connection();
    displaymaps(maps);
    while (!sink(maps->my_map)) {
        usleep(10000);
        my_printf("\nwaiting for enemy's attack...\n");
        defence_result(GAME.enemy_pid, maps);
        usleep(4000);
        input = get_input();
        send(input,GAME.enemy_pid);
        send(END, GAME.enemy_pid);
        attack_result(input, maps);
        displaymaps(maps);
        input[1] = '\0';
    }
}

int main(int argc, char **argv)
{
    GAME.signals = 0;
    GAME.l_or_i = 0;
    map_t *maps = malloc(sizeof(map_t));
    initmap(maps);

    if (argc == 2){
        if (setposmap(maps, argv[1]) == 0)
            return 84;
        host(maps);
    }else if (argc == 3){
        if (setposmap(maps, argv[2]) == 0)
            return 84;
        client(my_getnbr(argv[1]), maps);
    }
    return 0;
}
