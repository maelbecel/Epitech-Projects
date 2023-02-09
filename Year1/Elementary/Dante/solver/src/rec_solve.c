/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "dante.h"

bool solve_maze(solver_t *maze)
{
    maze->here = malloc(sizeof(bool *) * maze->height + 1);
    maze->path = malloc(sizeof(bool *) * maze->height + 1);
    for (size_t row = 0; (int)row < maze->height; row++) {
        maze->here[row] = malloc(sizeof(bool) * maze->width + 1);
        maze->path[row] = malloc(sizeof(bool) * maze->width + 1);
        for (size_t col = 0; (int)col < maze->width; col++) {
            maze->here[row][col] = false;
            maze->path[row][col] = false;
        }
    }
    return rec_solve(0, 0, maze);
}

bool rec_solve(int x, int y, solver_t *maze)
{
    if (x == maze->width - 1 && y == maze->height - 1)
        return true;
    if (maze->maze[y][x] || maze->here[y][x])
        return false;
    maze->here[y][x] = true;
    if ((y != 0 && rec_solve(x, y - 1, maze)) ||
        (y != maze->height - 1 && rec_solve(x, y + 1, maze)) ||
        (x != maze->width - 1 && rec_solve(x + 1, y, maze)) ||
        (x != 0  && rec_solve(x - 1, y, maze))) {
        maze->path[y][x] = true;
        return true;
        }
    return false;
}
