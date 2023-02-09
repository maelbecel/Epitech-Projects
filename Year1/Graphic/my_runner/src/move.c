/*
** EPITECH PROJECT, 2021
** move
** File description:
** move.c
*/

#include "my.h"
#include "runner.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdlib.h>

game_object *get_fist_object(game_object **object, int elmt)
{
    for (int i = 0; i < elmt; i++) {
        if (object[i]->type != EMPTY)
            return object[i];
    }
    return object[0];
}

int check_collision(game_object **object, gameinfo_t *info,
                    clocking_t *clock, game_object **game)
{
    game_object *obj;
    if (info->nb_elements > 0){
        obj = get_fist_object(object, info->nb_elements);
        if ((clock->seconds > 0.3 && clock->seconds < 0.6) &&
            (obj->pos.x > 370 && obj->pos.x < 470) && obj->type == BIRD){
            return 1;
        }else if (clock->seconds > 0.8 && (obj->pos.x > 370 &&
            obj->pos.x < 390) && obj->type == BLOC){
            return 1;
        }else if (clock->seconds > 0.8 && (obj->pos.x > 370 &&
            obj->pos.x < 470) && obj->type == SPIKE){
            return 1;
        }else if (clock->seconds > 0.55 && (obj->pos.x > 270 &&
            obj->pos.x < 370) && obj->type == BLOC){
            game[4]->place = UP;
            game[4]->pos = (sfVector2f){276,120};
        }
    }
    return 0;
}

int move_object(game_object **object, gameinfo_t *info,
                clocking_t **clocks, game_object **game)
{
    for (int i = 0; i < info->nb_elements; i++) {
        if (object[i]->pos.x > 100){
            object[i]->pos.x -= object[i]->speed;
            sfSprite_setPosition(object[i]->sprite, object[i]->pos);
        }else {
            sfSprite_destroy(object[i]->sprite);
            sfTexture_destroy(object[i]->spritesheet);
            for (int j = 1; j < info->nb_elements; j++){
                object[j-1] = object[j];
            }
            info->nb_elements--;;
            info->score += clocks[5]->seconds;
            object[info->nb_elements] = NULL;
        }
    }
    return check_collision(object, info, clocks[2], game);
}

int move_main(game_object **game, clocking_t *clock, game_object **obj)
{
    if (clock->seconds < 0.8){
        game[4]->place = JUMP;
        sfSprite_setTexture(game[4]->sprite,
            sfTexture_createFromFile("pictures/main_jump.png", NULL), sfTrue);
        sfSprite_setTexture(game[3]->sprite,
            sfTexture_createFromFile("pictures/plan_jump.png", NULL), sfTrue);
        game[4]->pos = (sfVector2f){276,195};
        game[4]->rect.height = 500;
    }else if (game[4]->place != UP || obj[0]->pos.x < 210){
        game[4]->place = DOWN;
        sfSprite_setTexture(game[4]->sprite,
            sfTexture_createFromFile("pictures/main_run.png", NULL), sfTrue);
        sfSprite_setTexture(game[3]->sprite,
            sfTexture_createFromFile("pictures/plan.png", NULL), sfTrue);
        game[4]->pos = (sfVector2f){276,470};
        game[4]->rect.height = 225;
    }
    if (game[4]->rect.left >= 1575)
        game[4]->rect.left = 0;
    else
        game[4]->rect.left += game[4]->speed;
    sfSprite_setTextureRect(game[4]->sprite, game[4]->rect);
    return 0;
}

void move_plan(game_object *plan, int size)
{
    if (plan->rect.left >= size)
        plan->rect.left = 0;
    else
        plan->rect.left += plan->speed;
    sfSprite_setTextureRect(plan->sprite, plan->rect);
}

void move_all(game_object **game)
{
    for (int i = 0; i < 5; i++){
        switch (game[i]->type){
            case FOURTH_PLAN:{
                move_plan(game[i], 1600);
                break;
            }case THIRD_PLAN:{
                move_plan(game[i], 4800);
                break;
            }case SECOND_PLAN:{
                move_plan(game[i], 3200);
                break;
            } default: break;
        }
    }
}
