/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_hunter.h"

int get_over_click(sfMouseButtonEvent event)
{
    sfMusic* clic = sfMusic_createFromFile("sounds/clic.ogg");
    sfMusic_play(clic);

    if (event.x >= 470 && event.x <= 850) {
        if (event.y >= 700 && event.y <= 850) {
            return 1;
        }
    }
    return 0;
}

void printtext(sfRenderWindow *window, sfFont *font, sfText *score, game_t *Game)
{
    sfText *bestscore = sfText_create();
    int fd = open("log/bestscore.txt",O_RDONLY);
    char *scr = inttochar(Game->score);
    char high[10];
    read(fd, high, 10);
    close(fd);
    if (my_getnbr(high) < Game->score){
        fd = open("log/bestscore.txt",O_WRONLY);
        write(fd, inttochar(Game->score), my_strlen(inttochar(Game->score)));
        close(fd);
        sfText_setColor(bestscore, sfBlack);
        sfText_setString(bestscore, inttochar(Game->score));
        sfText_setFont(bestscore, font);
        sfText_setCharacterSize(bestscore, 50);
        sfText_setPosition(bestscore, (sfVector2f){600, 570});
        sfRenderWindow_drawText(window, bestscore, NULL);
    } else {
        sfText_setColor(bestscore, sfBlack);
        sfText_setString(bestscore, high);
        sfText_setFont(bestscore, font);
        sfText_setCharacterSize(bestscore, 50);
        sfText_setPosition(bestscore, (sfVector2f){600, 570});
        sfRenderWindow_drawText(window, bestscore, NULL);
    }
    sfText_setColor(score, sfBlack);
    sfText_setString(score, scr);
    sfText_setFont(score, font);
    sfText_setCharacterSize(score, 50);
    sfText_setPosition(score, (sfVector2f){600, 420});
    sfRenderWindow_drawText(window, score, NULL);
}

int analyse_over_events(sfRenderWindow *window, sfEvent event)
{
    int r = 0;
    switch (event.type){
        case sfEvtClosed :{
            sfRenderWindow_destroy(window);
            exit(0);
            break;
        }
        case sfEvtMouseButtonPressed : {
            sfVector2i vector = sfMouse_getPositionRenderWindow(window);
            sfMouseButtonEvent event;
            event.x = vector.x;
            event.y = vector.y;
            r = get_over_click(event);
            break;
        }
    }
    return r;
}

int gameover(sfRenderWindow *window, game_t *Game)
{
    sfEvent event;
    sfTexture *texture = sfTexture_createFromFile("pictures/gameover.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfMusic *music = sfMusic_createFromFile("sounds/gameover_music.ogg");
    sfFont *font = sfFont_createFromFile("fonts/SuperMario256.ttf");
    sfText *score = sfText_create();
    int r = 0;

    sfMusic_setVolume(music, getsoundlevel());
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)){
            r = analyse_over_events(window, event);
        }
        if (r != 0){
            sfMusic_destroy(music);
            break;
        }
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        printtext(window, font, score, Game);
        sfRenderWindow_display(window);
    }
    return r;
}