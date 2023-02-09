/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-lemin-lucas.iglesia
** File description:
** lemin
*/

#ifndef LEMIN_H_
    #define LEMIN_H_

    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>

    #define UNUSED __attribute__((unused))

    typedef struct lemin_s lemin_t;
    typedef struct room_s room_t;

    struct lemin_s {
        char **input;
        int nbr_ant;
        room_t **room;
        room_t *start;
        room_t *end;
        int size;
    };

    struct room_s {
        int x;
        int y;
        char *name;
        bool start;
        bool end;
        bool have_ant;
        int nb_next;
        room_t **next;
        bool is_visited;
        int distance;
    };

    typedef struct ant_s {
        int nb;
        struct room_s *room;
    } ant_t;

    char **read_input(void);
    char **my_str_to_word_array(char *str, char separator);
    void print_array(char **input);
    lemin_t *init_lemin(void);
    bool is_room(char *input);
    room_t *init_room(char **input, int i);
    int find_x(char *str);
    int find_y(char *str);
    bool is_start(char **input, int nb);
    bool is_end(char **input, int nb);
    char *get_name(char *input);
    bool is_link(char *input);
    int get_nb_next(char **input, room_t *room);
    int print_info(lemin_t *lemin);
    int init_tunnel(char **input, room_t **room);
    room_t *find_start(room_t **room);
    room_t *find_end(room_t **room);
    room_t *find_room_pt2(char *input, room_t *room, int *nb, room_t **other);
    room_t *find_next(char *name, room_t **room);
    char *get_second_name(char *input);
    void verif_next(room_t *room, room_t *link);
    void init_distance(lemin_t *lemin);
    void display_movement(ant_t ant, char *room_name);
    void solver(lemin_t *lemin, ant_t *ants);
    void display_result(lemin_t *lemin, ant_t *ants,
                                                    int moved, bool first_ant);
    void reset_visited(lemin_t *lemin);

#endif /* !LEMIN_H_ */
