/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include "my_hunter.h"
#include "my.h"


int touch(sfMouseButtonEvent *Click, boo_t *Boo, boo_t *Boo2, game_t *Game)
{
    if (Click->x >= Boo->x && Click->x <= Boo->x + Boo->size &&
        Click->y >= Boo->y && Click->y <= Boo->y + Boo->size){
            Game->hit -= 1;
            Game->nbboo -= 1;
            Boo->x = 0;
            Boo->y = 1000;
            Game->score += (Game->level * Game->level *10);
    } else if (Click->x >= Boo2->x && Click->x <= Boo2->x + Boo2->size &&
        Click->y >= Boo2->y && Click->y <= Boo2->y + Boo2->size){
            Game->hit -= 1;
            Game->nbboo -= 1;
            Boo2->x = 1500;
            Boo2->y = 1000;
            Game->score += (Game->level * Game->level *10);
    }
    if (Game->nbboo < 1){
        Game->shot = 3;
        Boo->x = 0;
        Boo->y = rand()%600;
        Boo2->x = 1500;
        Boo2->y = rand()%600;
        Game->nbboo = 2;
    }
    return 0;
}

int analyse_play_events(sfRenderWindow *window, sfEvent event, sfMouseButtonEvent *Click, sfMusic *music)
{
    switch (event.type){
        case sfEvtClosed : {
            sfMusic_stop(music);
            sfMusic_destroy(music);
            sfRenderWindow_destroy(window);
            exit(0);
            return 0;
        }
        case sfEvtMouseButtonPressed : {
            sfVector2i vector = sfMouse_getPositionRenderWindow(window);
            Click->x = vector.x;
            Click->y  = vector.y;
            return 1;
        }
        default : {
            return 0;
        }
    }
}

void Drawtext(sfRenderWindow *window, sfFont *font, sfText *score, sfText *level, game_t *Game)
{
    char *scr = inttochar(Game->score);
    char *lvl = inttochar(Game->level);
    sfText_setColor(level, sfBlack);
    sfText_setColor(score, sfBlack);
    sfText_setString(score, scr);
    sfText_setFont(score, font);
    sfText_setCharacterSize(score, 50);
    sfText_setPosition(score, (sfVector2f){260, 855});
    sfRenderWindow_drawText(window, score, NULL);
    sfText_setString(level, lvl);
    sfText_setFont(level, font);
    sfText_setCharacterSize(level, 50);
    sfText_setPosition(level, (sfVector2f){230, 815});
    sfRenderWindow_drawText(window, level, NULL);
}

void UpdateWindow(sfRenderWindow *window, boo_t *Boo, boo_t *Boo2, game_t *Game, display_t *Boo_sprite, display_t *Boo2_sprite, display_t *Hit_sprite, display_t *Shot_sprite)
{
    Hit_sprite->rect = (sfIntRect){(10 - Game->hit) * 200,0,200,60};
    Shot_sprite->rect = (sfIntRect){(3 - Game->shot) * 80,0,80,80};
    Boo_sprite->rect = (sfIntRect){(Game->boo % 6) * 80,0,80,80};
    sfSprite_setPosition(Boo_sprite->sprite, (sfVector2f){Boo->x, Boo->y});
    sfSprite_setPosition(Boo2_sprite->sprite, (sfVector2f){Boo2->x, Boo2->y});
    sfSprite_setPosition(Hit_sprite->sprite, (sfVector2f){580,900});
    sfSprite_setPosition(Shot_sprite->sprite, (sfVector2f){1200,860});
    sfSprite_setTexture(Boo2_sprite->sprite, Boo2_sprite->texture, sfTrue);
    sfSprite_setTexture(Boo_sprite->sprite, Boo_sprite->texture, sfTrue);
    sfSprite_setTextureRect(Boo_sprite->sprite, Boo_sprite->rect);
    sfSprite_setTexture(Hit_sprite->sprite, Hit_sprite->texture, sfTrue);
    sfSprite_setTextureRect(Hit_sprite->sprite, Hit_sprite->rect);
    sfSprite_setTexture(Shot_sprite->sprite, Shot_sprite->texture, sfTrue);
    sfSprite_setTextureRect(Shot_sprite->sprite, Shot_sprite->rect);
    sfRenderWindow_drawSprite(window, Boo_sprite->sprite, NULL);
    sfRenderWindow_drawSprite(window, Boo2_sprite->sprite, NULL);
    sfRenderWindow_drawSprite(window, Hit_sprite->sprite, NULL);
    sfRenderWindow_drawSprite(window, Shot_sprite->sprite, NULL);
}

int play(sfRenderWindow *window)
{
    boo_t Boo = {80, 0,rand()%600};
    boo_t Boo2 = {80, 1500,rand()%600};
    sfMouseButtonEvent Click;
    game_t Game = {1, 0, 2, 10, 3, 2, 0};
    display_t Background_sprite = {sfTexture_createFromFile("pictures/play.png", NULL), (sfIntRect){0,0,1500,1000}, sfSprite_create()};
    display_t Boo_sprite = {sfTexture_createFromFile("pictures/boo2_spritesheet.png", NULL), (sfIntRect){0,0,80,80}, sfSprite_create()};
    display_t Boo2_sprite = {sfTexture_createFromFile("pictures/boo_spritesheet.png", NULL), (sfIntRect){0,0,80,80}, sfSprite_create()};
    display_t Hit_sprite = {sfTexture_createFromFile("pictures/hit_spritesheet.png", NULL), (sfIntRect){0,0,200,60}, sfSprite_create()};
    display_t Shot_sprite = {sfTexture_createFromFile("pictures/shoot_spritesheet.png", NULL), (sfIntRect){0,0,80,60}, sfSprite_create()};
    sfMusic *music = sfMusic_createFromFile("sounds/play_music.ogg");
    sfEvent event;
    sfClock *clock = sfClock_create();
    sfTime time;
    sfFont *font = sfFont_createFromFile("fonts/SuperMario256.ttf");
    sfText *score = sfText_create();
    sfText *level = sfText_create();
    float seconds;
    int analyse = 0;
    int lastevent = 0;

    sfSprite_setTexture(Background_sprite.sprite, Background_sprite.texture, sfTrue);
    sfRenderWindow_drawSprite(window, Background_sprite.sprite, NULL);
    UpdateWindow(window, &Boo, &Boo2, &Game, &Boo_sprite, &Boo2_sprite, &Hit_sprite, &Shot_sprite);
    sfMusic_setVolume(music, getsoundlevel());
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.01){
            Boo.x += Game.speed;
            Boo2.x -= Game.speed;
            sfClock_restart(clock);
        }
        if (Boo.x % 12 == 0){
            Game.boo += 1;
        }
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse = analyse_play_events(window, event, &Click, music);
        }
        if (analyse == lastevent)
            analyse = 0;
        lastevent = analyse;
        if (analyse == 1){
            Game.shot -= 1;
            touch(&Click, &Boo, &Boo2, &Game);
        }
        if (Game.hit <= 0) {
            Game.speed += 2;
            Game.level += 1;
            Game.hit = 10;
        } else if (Game.shot == 0 || Boo.x > 1500 || Boo2.x < 0) {
            sfMusic_destroy(music);
            break;
        }
        sfRenderWindow_drawSprite(window, Background_sprite.sprite, NULL);
        UpdateWindow(window, &Boo, &Boo2, &Game, &Boo_sprite, &Boo2_sprite, &Hit_sprite, &Shot_sprite);
        Drawtext(window, font, score, level, &Game);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
    gameover(window, &Game);
}
