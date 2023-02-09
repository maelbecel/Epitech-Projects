/*
** EPITECH PROJECT, 2022
** sokoban.c
** File description:
** sokoban
*/

#ifndef SOKOBAN
    #define SOKOBAN

    #define HELP_FLAG "-h"

    #define ERROR_X "More 'X' than 'O' in the map.\n"
    #define ERROR_O "More 'O' than 'X' in the map.\n"
    #define ERROR_MNY_P "Too many 'P' in the map.\n"
    #define ERROR_FEW_P "Too few 'P' in the map.\n"
    #define ERROR_FEW_ARG "Too few arguments.\n"
    #define ERROR_MNY_ARG "Too many arguments.\n"
    #define ERROR_MAP_OP "Map should not be open.\n"
    #define ERROR_MAP_SIZE "Map to big, please enlarge the terminal.\n"
    #define ERROR_MAP "Enable to open the map.\n"

    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <ncurses.h>
    #include <string.h>
    #include <curses.h>
    #include <SFML/Audio.h>

    typedef struct infomap_s {
        int fd;
        char **map;
        char **basic_map;
        char *buffer;
        int row;
        int col;
        int size;
        int posx;
        int posy;
        int nbo;
    } infomap_t;

    // Files from actions.c
    void my_exit(char *message, int ex);
    void reload(infomap_t *infomap);
    void handle_event(infomap_t *infomap, int key);
    int actions(infomap_t *infomap);

    // Files from createmap.c
    void initmap(infomap_t *infomap);
    void parsemap(infomap_t *infomap);
    void getbasicmap(infomap_t *infomap);

    // Files from display.c
    int is_not_locked(infomap_t *infomap, int i, int j);
    void check_map(infomap_t *infomap);
    void select_color(infomap_t *infomap, int i, int j);
    void wait_size(infomap_t *infomap);
    void display_colormap(infomap_t *infomap);

    // Files from info.c
    void get_row(infomap_t *infomap);
    void get_col(infomap_t *infomap);
    void get_o(infomap_t *infomap);
    void getinfo(infomap_t *infomap);

    // Files from move.c
    void go_up(infomap_t *infomap);
    void go_down(infomap_t *infomap);
    void go_left(infomap_t *infomap);
    void go_right(infomap_t *infomap);

    // Files from sokoban.c
    int my_sokoban(char *path);
    void readfile(infomap_t *infomap, char *path);
    void handle_error(infomap_t *infomap);
    void free_all(infomap_t *infomap);

#endif
