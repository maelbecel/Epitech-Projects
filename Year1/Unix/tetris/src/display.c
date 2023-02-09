/*
** EPITECH PROJECT, 2022
** tetris.c
** File description:
** tetris
*/

#include "my.h"
#include "printf.h"
#include "tetris.h"

void display_map(game_t* game)
{
    draw_box(75, 4, game->nbcol * 2, game->nbrow + 1);
    for (int i = 0; i < game->nbrow; i++) {
        drawline(game->map[i], game->nbcol, 76, 5 + i);
    }
}
void display_next(game_t* game)
{
    draw_box(79 + game->nbcol * 2, 4, 11, 3);
    mvprintw(4, 81 + game->nbcol * 2, "next");
}
void display_info(game_t* game)
{
    draw_box(10, 10, 30, 15);
    mvprintw(12, 12, "High Score:\t%i", game->info->high_score);
    mvprintw(14, 12, "Score:\t%i", game->info->score);
    mvprintw(18, 12, "Lines:\t%i", game->info->lines);
    mvprintw(20, 12, "Level:\t%i", game->info->level);
    mvprintw(24, 12, "Timer:\t%i", game->info->timer);
}

void display_tetris()
{
    draw_T(0, 0);
    draw_E(12, 0);
    draw_T(24, 0);
    draw_R(36, 0);
    draw_I(48, 0);
    draw_S(60, 0);

}

void display(game_t* game)
{
    display_map(game);
    display_next(game);
    display_info(game);
    display_tetris();
    attron(COLOR_PAIR(1));
}