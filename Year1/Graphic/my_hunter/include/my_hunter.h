/*
** EPITECH PROJECT, 2021
** my_hunter.h
** File description:
** my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef my_hunter
#define my_hunter

typedef struct Boo {
    int size;
    int x;
    int y;
}boo_t;

typedef struct Click {
    int x;
    int y;
}click_t;

typedef struct Display {
    sfTexture *texture;
    sfIntRect rect;
    sfSprite *sprite;
}display_t;

typedef struct Game {
    int level;
    int score;
    int speed;
    int hit;
    int shot;
    int nbboo;
    int boo;
}game_t;

void setsoundlevel(int level);
int getsoundlevel(void);

#endif
