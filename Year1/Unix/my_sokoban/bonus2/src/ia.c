/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "sokoban.h"

// int ia(infomap_t *infomap)
// {
//     if ((infomap->map[infomap->posy][infomap->posx - 1] == 'O' || infomap->map[infomap->posy][infomap->posx - 1] == ' '  || (infomap->map[infomap->posy][infomap->posx - 1] == 'X' && infomap->map[infomap->posy][infomap->posx - 1] == 'O'))) {
//         infomap->last_move = KEY_LEFT;
//         return KEY_LEFT;
//     } else if ((infomap->map[infomap->posy + 1][infomap->posx] == 'O' || infomap->map[infomap->posy + 1][infomap->posx] == ' ' || (infomap->map[infomap->posy + 1][infomap->posx] == 'X' && infomap->map[infomap->posy + 1][infomap->posx] == 'O'))) {
//         infomap->last_move = KEY_DOWN;
//         return KEY_DOWN;
//     } else if ((infomap->map[infomap->posy][infomap->posx + 1] == 'O' || infomap->map[infomap->posy][infomap->posx + 1] == ' ' || (infomap->map[infomap->posy][infomap->posx + 1] == 'X' && infomap->map[infomap->posy][infomap->posx + 1] == 'O'))) {
//         infomap->last_move = KEY_RIGHT;
//         return KEY_RIGHT;
//     } else if ((infomap->map[infomap->posy - 1][infomap->posx] == 'O' || infomap->map[infomap->posy - 1][infomap->posx] == ' ' || (infomap->map[infomap->posy - 1][infomap->posx] == 'X' && infomap->map[infomap->posy - 1][infomap->posx] == 'O'))) {
//         infomap->last_move = KEY_UP;
//         return KEY_UP;
//     } else {
//         switch (random() % 4){
//         case 0 :
//             return KEY_LEFT;
//         case 1 :
//             return KEY_RIGHT;
//         case 2 :
//             return KEY_DOWN;
//         default :
//             return KEY_UP;
//          }
//     }
// }

int ia(infomap_t *infomap)
{
    if ((infomap->map[infomap->posx][infomap->posy + 1] == 'X' && infomap->map[infomap->posx][infomap->posy + 2] == 'O') && (infomap->map[infomap->posx][infomap->posy + 1] == 'X' && infomap->basic_map[infomap->posx][infomap->posy + 1] != 'O'))
        return KEY_DOWN;
    else if ((infomap->map[infomap->posx + 1][infomap->posy] == 'X' && infomap->map[infomap->posx + 2][infomap->posy] == 'O') && (infomap->map[infomap->posx + 1][infomap->posy] == 'X' && infomap->basic_map[infomap->posx + 1][infomap->posy] != 'O'))
        return KEY_RIGHT;
    else if ((infomap->map[infomap->posx][infomap->posy - 1] == 'X' && infomap->map[infomap->posx][infomap->posy - 2] == 'O') && (infomap->map[infomap->posx][infomap->posy - 1] == 'X' && infomap->basic_map[infomap->posx][infomap->posy - 1] != 'O'))
        return KEY_UP;
    else if ((infomap->map[infomap->posx - 1][infomap->posy] == 'X' && infomap->map[infomap->posx - 2][infomap->posy] == 'O') && (infomap->map[infomap->posx - 1][infomap->posy] == 'X' && infomap->basic_map[infomap->posx - 1][infomap->posy] != 'O'))
        return KEY_LEFT;
    else {
        switch (random() % 4){
            case 0 :
                return KEY_LEFT;
            case 1 :
                return KEY_RIGHT;
            case 2 :
                return KEY_DOWN;
            default :
                return KEY_UP;
        }
    }
}
