/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mydefender-mael1.becel
** File description:
** list
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

char check_left(char **map, int i, int j)
{
    if ( j > 0 && (map[i][j - 1] == 'A' || map[i][j - 1] == 'B'))
        return 'L';
    if ( i < MAP_ROW - 1 && (map[i + 1][j] == 'A' || map[i + 1][j] == 'B'))
        return 'D';
    if ( i > 0 && (map[i - 1][j] == 'A' || map[i - 1][j] == 'B'))
        return 'U';
    return 'R';
}

char check_right(char **map, int i, int j)
{
    if ( j < MAP_COL - 1 && (map[i][j + 1] == 'A' || map[i][j + 1] == 'B'))
        return 'R';
    if ( i < MAP_ROW - 1 && (map[i + 1][j] == 'A' || map[i + 1][j] == 'B'))
        return 'D';
    if ( i > 0 && (map[i - 1][j] == 'A' || map[i - 1][j] == 'B'))
        return 'U';
    return 'L';
}

char check_up(char **map, int i, int j)
{
    if ( j > 0 && (map[i][j - 1] == 'A' || map[i][j - 1] == 'B'))
        return 'L';
    if ( j < MAP_COL - 1 && (map[i][j + 1] == 'A' || map[i][j + 1] == 'B'))
        return 'R';
    if ( i > 0 && (map[i - 1][j] == 'A' || map[i - 1][j] == 'B'))
        return 'U';
    return 'D';
}

char check_down(char **map, int i, int j)
{
    if ( j > 0 && (map[i][j - 1] == 'A' || map[i][j - 1] == 'B'))
        return 'L';
    if ( j < MAP_COL - 1 && (map[i][j + 1] == 'A' || map[i][j + 1] == 'B'))
        return 'R';
    if ( i < MAP_ROW - 1 && (map[i + 1][j] == 'A' || map[i + 1][j] == 'B'))
        return 'D';
    return 'U';
}

char check_all(char **map, int i, int j)
{
    if ( j < MAP_COL - 1 && (map[i][j + 1] == 'A' || map[i][j + 1] == 'B'))
        return 'R';
    if ( j > 0 && (map[i][j - 1] == 'A' || map[i][j - 1] == 'B'))
        return 'L';
    if ( i < MAP_ROW - 1 && (map[i + 1][j] == 'A' || map[i + 1][j] == 'B'))
        return 'D';
    if ( i > 0 && (map[i - 1][j] == 'A' || map[i - 1][j] == 'B'))
        return 'U';
    return 'R';
}
