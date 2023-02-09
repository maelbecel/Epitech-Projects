/*
** EPITECH PROJECT, 2021
** map
** File description:
** map.c
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "navy.h"
#include <stdlib.h>

void printmap(char **map)
{
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++){
        my_printf("%d|",i+1);
        for (int j = 0; j < 8 ; j++){
            my_printf("%c ",map[i][j]);
        }
        my_printf("\n");
    }
}

void initmap(map_t *maps)
{
    maps->enemy_map = malloc(sizeof(char *)*10);
    maps->my_map = malloc(sizeof(char *)*10);
    int j;
    for (int i = 0; i < 8; i++){
        maps->my_map[i] = malloc(sizeof(char)*10);
        maps->enemy_map[i] = malloc(sizeof(char)*10);
        for (j = 0; j < 8; j++){
            maps->my_map[i][j] = '.';
            maps->enemy_map[i][j] = '.';
        }
        maps->my_map[i][j] = '\0';
        maps->enemy_map[i][j] = '\0';
    }
}

void displaymaps(map_t *maps)
{
    my_printf("\nmy positions:\n");
    printmap(maps->my_map);
    my_printf("\nenemy's positions:\n");
    printmap(maps->enemy_map);
}

void fill(map_t *maps, vector_t from, vector_t to, char with)
{
    for (int i = from.y; i <= to.y; i++){
        for (int j = from.x; j <= to.x; j++){
            maps->my_map[i][j] = with;
        }
    }
}

int setposmap(map_t *maps, char *filepath)
{
    char buffer[32];
    int fd = open(filepath, O_RDONLY);
    int i = 0;
    vector_t from = {0,0};
    vector_t to = {0,0};

    read(fd, buffer, 32);
    close(fd);
    if (error_map(buffer) == 0)
        return 0;
    else {
        while (i < 30){
            from = (vector_t){buffer[i+2]-'A', buffer[i+3]-'1'};
            to = (vector_t){buffer[i+5]-'A', buffer[i+6]-'1'};
            fill(maps, from, to, buffer[i]);
            i += 8;
        }
    }
    return 1;
}
