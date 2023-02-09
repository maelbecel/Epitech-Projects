/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** defender
*/

#ifndef DEFENDER_H_
    #define DEFENDER_H_

    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdarg.h>
    #include <math.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>

    #define UNUSED __attribute__((unused))

    #define HOOVER_SOUND "resource/song/tool.ogg"
    #define CLICK_SOUND "resource/song/click.ogg"
    #define BUY_SOUND "resource/song/buy.ogg"
    #define MUSIC "resource/song/song.ogg"
    #define DIE_SOUND "resource/song/tp.ogg"

    #define POLICE "resource/Fonts/Nickname.otf"

    #define SOUND_FILE "log/soundlevel.txt"
    #define SCORE_FILE "log/score.txt"
    #define BASIC_FONT "resource/Fonts/DK_Display_Patrol.otf"
    #define TILE_SIZE 120
    #define BASIC_TEXT_SIZE 70
    #define MAP_ROW 9
    #define MAP_COL 16
    #define TIME_BTWN_ENEMY 2.00
    #define MICRO 1000000
    #define PI 3.141592654


    typedef struct type_button_s type_button_t;
    typedef struct button_s button_t;
    typedef struct element_s element_t;
    typedef struct scene_s scene_t;
    typedef struct game_s game_t;
    typedef struct menu_s menu_t;
    typedef struct monster_s monster_t;
    typedef struct tower_s tower_t;
    typedef struct direction_s direction_t;

    struct direction_s
    {
        sfIntRect place;
        char direction;
    };

    enum menu {
        NO_TOWER,
        TOWER
    };

    struct tower_s {
        sfVector2f pos;
        int id;
        int range;
        int level;
        int damage;
        char *type;
        element_t *tower;
        tower_t *next;
        tower_t *prev;
    };

    struct menu_s {
        button_t **buttons;
        element_t **elements;
        bool is_tower;
        int x;
        int y;
    };

    struct monster_s {
        int id;
        int life;
        sfVector2f direction;
        element_t *monster;
    };

    struct game_s {
        sfRenderWindow *window;
        sfMusic *music;
        sfMusic *sound_buy;
        sfMusic *sound_clicked;
        sfMusic *sound_hoover;
        sfMusic *main_music;
        sfMusic *die;
        menu_t *menu_tower;
        scene_t *info;
        tower_t *head;
        monster_t **monster;
        direction_t **directions;
        sfClock *clock;
        sfTime time;
        int kill;
        int speed;
        int type;
        int score;
        int money;
        int life;
        int page;
        char **map;
    };

    struct element_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f scale;
        sfIntRect rect;
        sfVector2f pos;
        int max_sprite;
    };

    struct type_button_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f scale;
        sfIntRect rect;
        sfText *text;
        sfFont *font;
        sfMusic *sound;
        sfVector2f text_pos;
        int text_size;
    };

    struct button_s {
        type_button_t *base;
        type_button_t *hoover;
        type_button_t *clicked;
        bool menu_tower;
        sfVector2f pos;
        void (*action_hoover)(scene_t *scenes, ...);
        void (*action_clicked)(scene_t *scenes, ...);
        bool hidden;
        bool is_tower;
        int x;
        int y;
    };

    struct scene_s {
        button_t **buttons;
        element_t **elements;
        int page;
        bool menu_tower;
    };

    // builtin //
    void clicked(scene_t *scenes, ...);
    void hoover(scene_t *scenes, ...);
    void quit(scene_t *scenes, ...);
    void my_exit(int code);
    void do_none(scene_t *scenes, ...);

    // createmap //
    char **readfile(char *path);

    // display //
    void display_main_menu(sfRenderWindow *window, scene_t *scenes,
                            sfEvent *event, game_t *game);
    void display_game(sfRenderWindow *window, scene_t *scenes,
                        sfEvent *event, game_t *game);
    void display_help(sfRenderWindow *window, scene_t *scenes,
                        sfEvent *event, game_t *game);
    void display_pause_menu(sfRenderWindow *window, scene_t *scenes,
                            sfEvent *event, game_t *game);
    void display(sfRenderWindow *window, scene_t *scenes,
                sfEvent *event, game_t *game);

    // draw //
    void draw_button(sfRenderWindow *window, button_t *button);
    void draw_hoover(sfRenderWindow *window, button_t *button, game_t *game);
    void draw_clicked(sfRenderWindow *window, button_t *button, game_t *game);
    void draw_element(sfRenderWindow *window, element_t *element);

    // game_page //
    void prep_game(game_t *game, scene_t *scenes);
    void tower(scene_t *scenes, ...);
    void menu_tower(scene_t *scenes, ...);
    void go_game(scene_t *scenes, ...);
    button_t **game_buttons(game_t *game);
    element_t **game_elements(void);

    // getsound //
    int getsoundlevel(void);
    void setsoundlevel(int level);

    // handle_click //
    int is_hoover(sfRenderWindow *window, scene_t *scenes, int b, int s);
    int is_click(sfRenderWindow *window, scene_t *scenes,
                 game_t *game, int b, int s);

    // help_page //
    void help(scene_t *scenes, ...);
    element_t **help_elements(void);
    button_t **help_buttons(void);

    // init_scenes //
    scene_t *init_scenes(game_t *game);

    // init //
    type_button_t *init_button_type(char *text, char *texture,
                                    sfVector2i size);
    button_t *init_button(char *text, char *texture, sfVector2f pos,
                            sfVector2i size);
    element_t *init_element(char *texture, sfVector2f pos, sfVector2f size,
                            sfVector2f scale);
    button_t *init_tiles(int i, int j, game_t *game);

    // main_menu_page //
    void menu(scene_t *scenes, ...);
    element_t **main_menu_elements(void);
    button_t **main_menu_buttons(void);

    // pause_menu //
    void pause_menu(scene_t *scenes, ...);
    button_t **pause_buttons(void);

    // analyse_event.c //
    int analyse_event(sfRenderWindow *window, sfEvent *event,
                        game_t *game, scene_t *scenes);

    // menu.c //
    menu_t *init_menu(void);
    void draw_menu(sfRenderWindow *window, game_t *game, int type);

    // tower.c //
    void buy_tower_elec(scene_t *scenes, ...);
    void buy_tower_ice(scene_t *scenes, ...);
    void buy_tower_fire(scene_t *scenes, ...);
    void buy_tower_poison(scene_t *scenes, ...);

    // create_tower.c //
    void create_tower_elec(game_t *game, sfVector2f pos);
    void create_tower_fire(game_t *game, sfVector2f pos);
    void create_tower_ice(game_t *game, sfVector2f pos);
    void create_tower_poison(game_t *game, sfVector2f pos);

    // info.c //
    element_t **info_elements(void);
    button_t **info_buttons(void);

    // list.c //
    tower_t *create_first_tower(char *type, int range, int damage,
                                sfVector2f pos);
    tower_t *create_other_tower(char *type, tower_t *head, int range,
                                int damage, sfVector2f pos);
    void destroy_tower(scene_t *scenes, ...);
    void upgrade_tower(scene_t *scenes, ...);
    tower_t *check_tower(game_t *game);

    // draw_tower.c //
    void draw_tower(sfRenderWindow *window, game_t *game);

    // monster.c //
    void display_monster(monster_t **monster);
    int get_nb_monster(monster_t **monster);
    monster_t **add_monster(monster_t **monster, game_t *game);
    monster_t **delete_monster(monster_t **monster, int id);
    void monster_is_kill(monster_t **monster, int id);


    // get_info.c //
    sfVector2f get_start(game_t *game);
    sfVector2f get_last(game_t *game);

    // create_monster.c //
    monster_t *create_monster(game_t *game, int i);
    monster_t *create_monster_green(game_t *game, int i);
    monster_t *create_monster_blue(game_t *game, int i);
    monster_t *create_monster_red(game_t *game, int i);
    monster_t *create_monster_purple(game_t *game, int i);

    // anim.c //
    void anim_tower(sfRenderWindow *window, tower_t *head);
    void move_rect(sfIntRect *rect, int offset, int maxvalue);

    // check_dir.c //
    char check_left(char **map, int i, int j);
    char check_right(char **map, int i, int j);
    char check_up(char **map, int i, int j);
    char check_down(char **map, int i, int j);
    char check_all(char **map, int i, int j);

    // create_directions.c //
    direction_t *new_direction(char **map, int i, int j, char last);
    direction_t **create_directions(char **map);
    void check_monster(monster_t *monster,
                         direction_t **directions, int speed);
    void get_dir(monster_t *monster, char dir, int speed);

    // game_over.c //
    element_t **game_over_elements(void);
    button_t **game_over_buttons(void);

    // draw_text.c //
    void draw_monster(game_t *game, sfRenderWindow *window);
    void draw_text(char *text, int size, sfVector2f pos,
                                        sfRenderWindow *window);

    // getscore.c //
    int getscore(void);
    void setscore(int level);

    // draw_movement.c //
    void move_game_elements(scene_t *scenes, sfRenderWindow *window);

    // menu_tower.c //
    void menu_tower1(scene_t *scenes, ...);
    void draw_menu_tower(sfRenderWindow *window, game_t *game);
    button_t **buttons_menu_tower(void);
    element_t **elements_menu_tower(void);
    void change_buttons(scene_t *scenes, menu_t *menu);

    // tower_attack.c //
    void towers_attack(game_t *game);
    int get_distance(sfVector2f from, sfVector2f to);

    // display_attack.c //
    void display_attack(monster_t *monster, tower_t *tower,
                        sfRenderWindow *window);
    void draw_attack(game_t *game);

#endif /* !DEFENDER_H_ */
