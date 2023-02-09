/*
** EPITECH PROJECT, 2022
** tetris.c
** File description:
** tetris
*/

#ifndef TETRIS
    #define TETRIS
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <ncurses.h>
    #include <curses.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <ncurses.h>
    #include <string.h>
    #include <curses.h>

    #define UNUSED __attribute__((unused))

    typedef struct game_s game_t;
    typedef struct keys_s keys_t;
    typedef struct info_s info_t;
    typedef struct element_s element_t;
    typedef struct tetris tetristoune_t;
    typedef struct pos pos_t;

    struct game_s {
        info_t *info;
        keys_t *key;
        element_t **map;
        tetristoune_t **tetrimino;
        int i;
        int nbcol;
        int nbrow;
        int level;
        bool debug;
        bool next;
        bool open;
        bool help;
    };

    struct keys_s {
        int left;
        int right;
        int turn;
        int drop;
        int quit;
        int pause;
    };

    struct info_s {
        int high_score;
        int score;
        int lines;
        int level;
        int timer;
    };

    struct element_s {
        char c;
        int color;
    };

    struct pos {
        int x;
        int y;
    };

    struct tetris {
        pos_t pos;
        int nbcol;
        int nbrow;
        int color;
        char **form;
    };

    game_t *init_game(void);
    info_t *init_info(void);
    element_t **init_map(game_t *game);
    keys_t *init_keys(void);
    void color(void);

    void display(game_t* game);
    void draw_box(int x, int y, int nbcol, int nbrow);
    void drawline(element_t *line, int len, int x, int y);

    void draw_T(int x, int y);
    void draw_E(int x, int y);
    void draw_R(int x, int y);
    void draw_I(int x, int y);
    void draw_S(int x, int y);

    void get_option(game_t *game, int ac, char **argv);

    tetristoune_t **load_tetrimino(game_t *game);

    void display_tet(game_t* game);

    char **my_str_to_word_array(char *str, char separator);

    void debug(game_t *game);

    int verif_tetrimino(void);
    char *getname(char *filename);
    char *conc(char *a, char *b);

#endif
