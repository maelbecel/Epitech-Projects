/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

monster_t *create_monster_blue(game_t *game, int i)
{
    monster_t *ne = malloc(sizeof(monster_t));
    ne->monster = init_element("resource/Monsters/blue_right.png",
                    get_start(game), (sfVector2f){60, 79}, (sfVector2f){1, 1});
    ne->monster->pos.y += 10;
    ne->monster->pos.x += 10;
    ne->monster->max_sprite = 14;
    ne->direction = (sfVector2f){0, 0};
    ne->id = i;
    ne->life = (game->kill + 1) * 25;
    return ne;
}

monster_t *create_monster_purple(game_t *game, int i)
{
    monster_t *ne = malloc(sizeof(monster_t));
    ne->monster = init_element("resource/Monsters/purple_right.png",
                    get_start(game), (sfVector2f){72, 70}, (sfVector2f){1, 1});
    ne->monster->pos.y += 13;
    ne->monster->max_sprite = 14;
    ne->direction = (sfVector2f){0, 0};
    ne->id = i;
    ne->life = (game->kill + 1) * 30;
    return ne;
}

monster_t *create_monster_red(game_t *game, int i)
{
    monster_t *ne = malloc(sizeof(monster_t));
    ne->monster = init_element("resource/Monsters/red_right.png",
                    get_start(game), (sfVector2f){70, 71}, (sfVector2f){1, 1});
    ne->monster->pos.y += 13;
    ne->monster->max_sprite = 14;
    ne->direction = (sfVector2f){0, 0};
    ne->id = i;
    ne->life = (game->kill + 1) * 35;
    return ne;
}

monster_t *create_monster_green(game_t *game, int i)
{
    monster_t *ne = malloc(sizeof(monster_t));
    ne->monster = init_element("resource/Monsters/green_right.png",
                    get_start(game), (sfVector2f){35, 81}, (sfVector2f){1, 1});
    ne->monster->pos.y += 10;
    ne->monster->pos.x += 10;
    ne->monster->max_sprite = 14;
    ne->direction = (sfVector2f){0, 0};
    ne->id = i;
    ne->life = (game->kill + 1) * 20;
    return ne;
}

monster_t *create_monster(game_t *game, int i)
{
    char random[1];
    int fd = open("/dev/urandom", O_RDONLY);
    read(fd, random, 1);
    switch((int)random[0] % 4) {
        case 0: return create_monster_green(game, i);
        case 1: return create_monster_red(game, i);
        case 2: return create_monster_purple(game, i);
        case 3: return create_monster_blue(game, i);
        default: return create_monster_green(game, i);
    }
}
