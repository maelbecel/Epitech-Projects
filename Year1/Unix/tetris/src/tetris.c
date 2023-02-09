/*
** EPITECH PROJECT, 2022
** tetris.c
** File description:
** tetris
*/

#include "my.h"
#include "printf.h"
#include "tetris.h"
#include <time.h>

static void help(void)
{
    my_printf("Usage: ./tetris [options]\nOptions:\n\t--help \
    Display this help\n");
    my_printf("\t-L --level={num} Start Tetris at level num (def: 1)\n");
    my_printf("\t-l --key-left={K} Move the tetrimino LEFT using the K \
    key(def: left arrow)\n");
    my_printf("\t-r --key-right={K} Move the tetrimino RIGHT using the K key \
    (def: right arrow)\n");
    my_printf("\t-t --key-turn={K} TURN the tetrimino clockwise 90d using the \
    K key (def: top arrow)\n");
    my_printf("\t-d --key-drop={K} DROP the tetrimino using the K key \
    (def: down arrow)\n");
    my_printf("\t-q --key-quit={K} QUIT the game using the K key \
    (def: ‘q’ key)\n");
    my_printf("\t-p --key-pause={K} PAUSE/RESTART the game using the K key \
    (def: space bar)\n");
    my_printf("\t--map-size={row,col} Set the numbers of rows and columns of \
    the map (def: 20,10)\n");
    my_printf("\t-w --without-next Hide next tetrimino (def: false)\n");
    my_printf("\t-D --debug Debug mode (def: false)\n");
}

void key_event(int key, game_t * game)
{
    if (key == game->key->quit) {
        game->open = false;
    }
    if (key == game->key->left) {
        if (game->tetrimino[5]->pos.x != 0)
            game->tetrimino[5]->pos.x--;
    }
    if (key == game->key->right) {
        if (game->tetrimino[5]->pos.x + game->tetrimino[5]->nbcol < game->nbcol)
            game->tetrimino[5]->pos.x++;
    }
}

void play(game_t* game)
{
    clock_t start = clock();
    clock_t current;
    int key;
    clear();
    display(game);
    display_tet(game);
    key = getch();
    key_event(key, game);
    refresh();
    while((current = clock()) - start < 400000);
}

void print_array(tetristoune_t **tet)
{
    for (int i = 0; tet[i] != NULL; i++) {
        for (int j = 0; tet[i]->form[j] != NULL; j++)
            my_printf("%s\n", tet[i]->form[j]);
        printf("\n");
    }
}

int main (int ac, char **argv)
{
    WINDOW *win;
    game_t *game = init_game();
    get_option(game, ac, argv);
    if (game->help) {
        help();
        return 0;
    }
    if (game->debug) {
        debug(game);
        return 0;
    }
    win = initscr();
    nodelay(win, TRUE);
    noecho();
    keypad(stdscr, TRUE);
    refresh();
    color();
    verif_tetrimino();
    while(game->open)
        play(game);
    endwin();
    return 0;
}
