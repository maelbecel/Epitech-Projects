/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mydefender-mael1.becel
** File description:
** list
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

bool collision(sfVector2f point, sfIntRect square)
{
    if ((point.x >= square.left && point.x <= square.left + square.width) &&
        (point.y >= square.top && point.y <= square.top + square.height))
        return true;
    return false;
}

direction_t *new_direction(char **map, int i, int j, char last)
{
    direction_t *new = malloc(sizeof(direction_t));
    new->place = (sfIntRect){j * TILE_SIZE + 9, i * TILE_SIZE + 15, 30, 15};
    switch (last) {
        case 'L': new->direction = check_left(map, i, j);
            break;
        case 'R': new->direction = check_right(map, i, j);
            break;
        case 'U': new->direction = check_up(map, i, j);
            break;
        case 'D': new->direction = check_down(map, i, j);
            break;
        default : new->direction = check_all(map, i, j);
    }
    return new;
}

direction_t **create_directions(char **map)
{
    direction_t **directions = malloc(sizeof(direction_t) * (MAP_COL + 1) * (MAP_ROW + 1));
    int x = 0;
    int y = 0;
    int d = 0;
    int end = 0;

    for (; y < MAP_ROW; y++)
        if (map[y][0] == 'A' || map[y][0] == 'B')
            break;
    for (; end < MAP_ROW; end++)
        if (map[end][MAP_COL - 1] == 'A' || map[end][MAP_COL - 1] == 'B')
            break;

    directions[d++] = new_direction(map, y, x, 'S');
    directions[d] = NULL;

    while (x != MAP_COL - 1 || y != end) {
        switch (directions[d - 1]->direction) {
            case 'U': y--;
                break;
            case 'D': y++;
                break;
            case 'L': x--;
                break;
            case 'R': x++;
                break;
        }
        directions[d] = new_direction(map, y, x, directions[d - 1]->direction);
        if (x == MAP_COL - 1 && y == end)
            directions[d]->direction = 'R';
        directions[d + 1] = NULL;
        d++;
    }
    return directions;
}

void check_monster(monster_t *monster, direction_t **directions, int speed)
{
    for (int i = 0; directions[i] != NULL; i++) {
        if (collision(monster->monster->pos, directions[i]->place)) {
            get_dir(monster, directions[i]->direction, speed);
            break;
        }
    }
    monster->monster->pos.x += monster->direction.x;
    monster->monster->pos.y += monster->direction.y;
}

void get_dir(monster_t *monster, char dir, int speed)
{
    switch (dir) {
        case 'L': monster->direction = (sfVector2f){-speed, 0};
            break;
        case 'R': monster->direction = (sfVector2f){speed, 0};
            break;
        case 'U': monster->direction = (sfVector2f){0, -speed};
            break;
        case 'D': monster->direction = (sfVector2f){0, speed};
            break;
    }
}