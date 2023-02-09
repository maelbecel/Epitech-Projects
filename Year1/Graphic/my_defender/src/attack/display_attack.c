/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mydefender-mael1.becel
** File description:
** display_attack
*/

#include "my.h"
#include "printf.h"
#include "defender.h"
#include <math.h>

static float get_angle(UNUSED sfVector2f *monster, UNUSED sfVector2f *tower)
{
    float ac = monster->x - tower->x;
    float ab = monster->y - tower->y;
    float tan_b = ac / ab;
    float angle_b = atan(tan_b);
    angle_b = (angle_b * 180) / PI;
    float angle_c = 90 - angle_b;
    return angle_c - 180;
}

static element_t *get_attack(tower_t *tower)
{
    if (my_strcmp(tower->type, "elec") == 0)
        return init_element("resource/Projectiles/lightning.png",
        (sfVector2f){tower->tower->pos.x + (tower->tower->rect.width / 2),
                    tower->tower->pos.y + (tower->tower->rect.height / 2)},
        (sfVector2f){272, 93}, (sfVector2f){0.5, 0.5});
    if (my_strcmp(tower->type, "fire") == 0)
        return init_element("resource/Projectiles/fire.png",
        (sfVector2f){tower->tower->pos.x + (tower->tower->rect.width / 2),
                    tower->tower->pos.y + (tower->tower->rect.height / 2)},
        (sfVector2f){146, 74}, (sfVector2f){0.8, 0.8});
    if (my_strcmp(tower->type, "ice") == 0)
        return init_element("resource/Projectiles/ice.png",
        (sfVector2f){tower->tower->pos.x + (tower->tower->rect.width / 2),
                    tower->tower->pos.y + (tower->tower->rect.height / 2)},
        (sfVector2f){285, 110}, (sfVector2f){0.4, 0.4});
    if (my_strcmp(tower->type, "poison") == 0)
        return init_element("resource/Projectiles/poison.png",
        (sfVector2f){tower->tower->pos.x + (tower->tower->rect.width / 2),
                    tower->tower->pos.y + (tower->tower->rect.height / 2)},
        (sfVector2f){187, 108}, (sfVector2f){0.6, 0.6});
    return NULL;
}

static void anim_attack(element_t *attack, sfRenderWindow *window, float angle,
                        sfVector2f *vector)
{
    static int i = 0;
    static int j = 0;
    if (i < 5) {
        i++;
        attack->pos.x += (vector->x / 5);
    }
    if (j < 5) {
        j++;
        attack->pos.y += (vector->y / 5);
    }
    sfSprite_setTextureRect(attack->sprite, attack->rect);
    sfSprite_setPosition(attack->sprite, attack->pos);
    sfSprite_setRotation(attack->sprite, angle);
    sfRenderWindow_drawSprite(window, attack->sprite, NULL);
    sfRenderWindow_display(window);
}

void display_attack(monster_t *monster, tower_t *tower, sfRenderWindow *window)
{
    sfVector2f vector = (sfVector2f)
                        {tower->tower->pos.x - monster->monster->pos.x,
                        tower->tower->pos.y - monster->monster->pos.y};
    float angle = get_angle(&monster->monster->pos, &tower->tower->pos);
    element_t *attack = get_attack(tower);
    anim_attack(attack, window, angle, &vector);
    free(attack);
}
