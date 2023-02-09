/*
** EPITECH PROJECT, 2022
** B-PSU-200-REN-2-1-tetris-mael1.becel
** File description:
** option
*/

#include "my.h"
#include "printf.h"
#include "tetris.h"
#include <getopt.h>

void option(int opt, game_t* game)
{
    switch (opt) {
        case 'L': game->info->level = my_getnbr(optarg);
            break;
        case 'l': game->key->left = optarg[0];
            break;
        case 'r': game->key->right = optarg[0];
            break;
        case 't': game->key->turn = optarg[0];
            break;
        case 'd': game->key->drop = optarg[0];
            break;
        case 'q': game->key->quit= optarg[0];
            break;
        case 'p': game->key->pause = optarg[0];
            break;
        case 'w' : game->next = false;
            break;
        case 'D': game->debug = true;
            break;
        case 'h' : game->help = true;
            break;
    }
}

void get_option(game_t *game, int ac, char **argv)
{
    int i = 0;
    int opt;
    static struct option long_options[] = {
        {"level", required_argument, 0, 'L' },
        {"key-left", required_argument, 0, 'l' },
        {"key-right", required_argument, 0, 'r' },
        {"key-turn", required_argument, 0, 't' },
        {"key-drop", required_argument, 0, 'd'},
        {"key-quit", required_argument, 0, 'q' },
        {"key-pause", required_argument, 0, 'p' },
        {"map-size", required_argument, 0, 0 },
        {"without-next", no_argument, 0, 'w' },
        {"debug", no_argument, 0, 'D' },
        {"help", no_argument, 0, 'h' },
        {0, 0, 0, 0 }
    };
    while ((opt = getopt_long(ac, argv, "L:l:r:t:d:q:p:wD", long_options, &i))
            != -1)
        option(opt, game);
}