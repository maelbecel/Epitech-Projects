/*
** EPITECH PROJECT, 2022
** tetris.c
** File description:
** tetris
*/

#include "my.h"
#include "printf.h"
#include "tetris.h"


void draw_E(int x, int y)
{
    attron(COLOR_PAIR(2));
    mvprintw(y, x, "**********");
    mvprintw(y + 1, x, "**********");
    mvprintw(y + 2, x, "**        ");
    mvprintw(y + 3, x, "*****     ");
    mvprintw(y + 4, x, "**        ");
    mvprintw(y + 5, x, "**********");
    mvprintw(y + 6, x, "**********");
}

void draw_T(int x, int y)
{
    attron(COLOR_PAIR(3));
    mvprintw(y, x, "**********");
    mvprintw(y + 1, x, "**********");
    mvprintw(y + 2, x, "    **    ");
    mvprintw(y + 3, x, "    **    ");
    mvprintw(y + 4, x, "    **    ");
    mvprintw(y + 5, x, "    **    ");
    mvprintw(y + 6, x, "    **    ");
}

void draw_R(int x, int y)
{
    attron(COLOR_PAIR(4));
    mvprintw(y, x,"  ******  ");
    mvprintw(y + 1, x, "**********");
    mvprintw(y + 2, x, "**      **");
    mvprintw(y + 3, x, "********  ");
    mvprintw(y + 4, x, "** ****** ");
    mvprintw(y + 5, x, "**     ***");
    mvprintw(y + 6, x, "**      **");
}

void draw_I(int x, int y)
{
    attron(COLOR_PAIR(5));
    mvprintw(y, x, "**********");
    mvprintw(y + 1, x, "**********");
    mvprintw(y + 2, x, "    **    ");
    mvprintw(y + 3, x, "    **    ");
    mvprintw(y + 4, x, "    **    ");
    mvprintw(y + 5, x, "**********");
    mvprintw(y + 6, x, "**********");
}

void draw_S(int x, int y)
{
    attron(COLOR_PAIR(6));
    mvprintw(y, x, "  ******  ");
    mvprintw(y + 1, x, "**********");
    mvprintw(y + 2, x, "****      ");
    mvprintw(y + 3, x, "   *****  ");
    mvprintw(y + 4, x, "      ****");
    mvprintw(y + 5, x, "**********");
    mvprintw(y + 6, x, "  ******  ");
}