/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-lucas.iglesia
** File description:
** init
*/

#include "my.h"
#include "printf.h"
#include "dante.h"

static void first_path(char **map, int endx, int endy)
{
    int x = 0;
    int y = 0;
    float r = 0;

    while (x != endx - 1 || y != endy - 1) {
        r = (rand() % 100) / 10.0;
        r = (r >= 0) ? r :r * -1;
        if ((int)r <= 3 && map[y][x + 1] != '\0')
            x++;
        if ((int)r == 4 && x != 0)
            x--;
        if ((int)r == 5 && y != 0)
            y--;
        if ((int)r >= 6 && map[y + 1] != NULL)
            y++;
        map[y][x] = '*';
    }
}

static char **init_map(int x , int y)
{
    char **map = malloc(sizeof(char *) * (y + 1));
    map[y] = NULL;
    for (int i = 0; i < y; i++) {
        map[i] = malloc(sizeof(char) * (x + 1));
        for (int j = 0; j < x; j++) {
            map[i][j] = '.';
        }
    }
    return map;
}

static char get_char(char c)
{
    int r = rand() % 10;
    if (c != '.')
        return c;
    else if (r <= 2)
        return 'X';
    else
        return '*';
}

static void fill_map(char **map)
{
    for (size_t i = 0; map[i] != NULL; i++)
        for (size_t j = 0; map[i][j] != '\0'; j++)
            map[i][j] = get_char(map[i][j]);
}

void create_imperfect(int x, int y)
{
    char **map = init_map(x,y);
    int i = 0;
    time_t t;

    srand(time(&t));
    first_path(map, x, y);
    fill_map(map);
    map[0][0] = '*';
    map[y - 1][x - 1] = '*';
    while (map[i]) {
        if (map[i + 1] != NULL)
            my_printf("%s\n", map[i++]);
        else
            my_printf("%s", map[i++]);
    }
}