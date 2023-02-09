/*
** EPITECH PROJECT, 2021
** my_hunter.h
** File description:
** my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef my_runner
#define my_runner

typedef enum position{
    NONE = 0,
    UP  = 1,
    DOWN = 2,
    JUMP = 3
}position_t;

typedef enum type {
    FIRST_PLAN = 1,
    SECOND_PLAN = 2,
    THIRD_PLAN = 3,
    FOURTH_PLAN = 4,
    MAIN_CHARACTERE = 5,
    BLOC = 6,
    SPIKE = 7,
    BIRD = 8,
    EMPTY = 9
}type_t;

typedef struct clocking {
    sfClock *clock;
    sfTime time;
    float seconds;
}clocking_t;

typedef struct gameinfo {
    int nb_elements;
    int infini;
    int map_place;
    char **map;
    sfVector2f *position_main;
    int score;
    int level;
    float level_speed;
}gameinfo_t;

typedef struct game_obj{
    type_t type;
    position_t place;
    int speed;
    void (*move);
    sfTexture *spritesheet;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
}game_object;

clocking_t **createclocks(void);
clocking_t *init_clock(void);
game_object **create_gameobject(void);
game_object *create_object(const char * path_to_spritesheet, sfVector2f pos,
                            sfIntRect rect, int speed, type_t TYPE);
int check_clocks(game_object **game, game_object **objects,
                clocking_t **clocks, gameinfo_t *info);
int move_main(game_object **game, clocking_t *clock, game_object **obj);
int move_object(game_object **object, gameinfo_t *info,
                clocking_t **clocks, game_object **game);
int check_collision(game_object **object, gameinfo_t *info,
                    clocking_t *clock, game_object **game);
void setjump(clocking_t **clocks, sfEvent event, game_object *game,
                sfMusic *music);
void update_clocks(clocking_t **clocks);
void move_plan(game_object *plan, int size);
void move_all(game_object **game);
int create_element_from_map(game_object **objects, gameinfo_t *info);
void create_element(game_object **objects, gameinfo_t *info);

#endif
