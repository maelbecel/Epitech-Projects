/*
** EPITECH PROJECT, 2021
** create
** File description:
** create.c
*/

#include "my.h"
#include "runner.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>

game_object *create_object(const char * path_to_spritesheet, sfVector2f pos,
                            sfIntRect rect, int speed, type_t TYPE)
{
    game_object *obj = malloc(sizeof(game_object));
    obj->spritesheet = sfTexture_createFromFile(path_to_spritesheet, NULL);
    obj->place = NONE;
    obj->pos = pos;
    obj->rect = rect;
    obj->sprite = sfSprite_create();
    obj->speed = speed;
    obj->type = TYPE;
    sfSprite_setTexture(obj->sprite, obj->spritesheet, sfTrue);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, obj->pos);
    return obj;
}

game_object **create_gameobject(void)
{
    game_object **obj = malloc(sizeof(game_object *) * 6);
    obj[0] = create_object("pictures/background.png", (sfVector2f){0,0},
                        (sfIntRect){0,0,1600,900},1, (type_t)FOURTH_PLAN);
    obj[1] = create_object("pictures/draw.png", (sfVector2f){0,0},
                        (sfIntRect){0,0,1600,900},2, (type_t)THIRD_PLAN);
    obj[2] = create_object("pictures/sky.png", (sfVector2f){0,0},
                        (sfIntRect){0,0,1600,900},3, (type_t)SECOND_PLAN);
    obj[3] = create_object("pictures/plan.png", (sfVector2f){0,0},
                        (sfIntRect){0,0,1600,900},0, (type_t)FIRST_PLAN);
    obj[4] = create_object("pictures/main_run.png", (sfVector2f){276,470},
                        (sfIntRect){0,0,225,500},225, (type_t)MAIN_CHARACTERE);
    return obj;
}

void setjump(clocking_t **clocks, sfEvent event,
                game_object *game, sfMusic *music)
{
    if (clocks[2]->seconds >= 0.8 && event.key.code == sfKeySpace){
        sfClock_restart(clocks[2]->clock);
        sfMusic_play(music);
        sfMusic_play(music);
        game->rect.left = 0;
    }
}

void create_element(game_object **objects, gameinfo_t *info)
{
    int r = rand() % 6;

    if (r <= 2)
        objects[info->nb_elements] = malloc(sizeof(game_object *));
    switch (r) {
        case 0: {
            objects[info->nb_elements++] = create_object("pictures/spike.png",
            (sfVector2f){1600,595}, (sfIntRect){0,0,100,100},1, (type_t)SPIKE);
            break;
        } case 1: {
            objects[info->nb_elements++] = create_object("pictures/bloc.png",
            (sfVector2f){1600,595}, (sfIntRect){0,0,100,100},1, (type_t)BLOC);
            break;
        } case 2: {
            objects[info->nb_elements++] = create_object("pictures/bird.png",
            (sfVector2f){1600,275}, (sfIntRect){0,0,200,100},1, (type_t)BIRD);
            break;
        } default: break;
    }
}

int create_element_from_map(game_object **objects, gameinfo_t *info)
{
    char i = info->map[1][info->map_place];
    char bird = info->map[0][info->map_place];

    if (i == '5')
        return 5;
    objects[info->nb_elements] = malloc(sizeof(game_object *));
    switch (i) {
        case '2': {
            objects[info->nb_elements] = create_object("pictures/spike.png",
            (sfVector2f){1600,595}, (sfIntRect){0,0,100,100},1, (type_t)SPIKE);
            info->nb_elements += 1;
            break;
        } case '3': {
            objects[info->nb_elements] = create_object("pictures/bloc.png",
            (sfVector2f){1600,595}, (sfIntRect){0,0,100,100},1, (type_t)BLOC);
            info->nb_elements += 1;
            break;
        } case ' ' : {
            if (bird == ' ') {
                objects[info->nb_elements] = create_object(
                    "pictures/empty.png",(sfVector2f){1600,595},
                    (sfIntRect){0,0,100,100},1,(type_t)EMPTY);
                info->nb_elements += 1;
                break;
            }
        }
    }
    if (bird == '1') {
        objects[info->nb_elements] = create_object("pictures/bird.png",
        (sfVector2f){1600,275}, (sfIntRect){0,0,200,100},1, (type_t)BIRD);
        info->nb_elements += 1;
    }
    info->map_place++;
    return 0;
}
