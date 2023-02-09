/*
** EPITECH PROJECT, 2021
** score.C
** File description:
** score
*/

#include "my_hunter.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void initialize_score(game_t *game)
{
    game->level = 0;
    game->score = 0;
    game->hit = 0;
    game->shot = 0;
}

void display_score(sfRenderWindow *window, game_t *game)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("fonts/SuperMario256.ttf");
    char *scr = malloc(sizeof(char) * 30);

    game->score += (game->level * game->level * 10);
    scr = inttochar(game->score);
    sfText_setString(text, scr);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    free(scr);
}