/*
** EPITECH PROJECT, 2022
** dante.c
** File description:
** dante
*/

#ifndef DANTE
    #define DANTE

    #define UNUSED __attribute__((unused))

    #include <stdbool.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <time.h>
    #include <sys/resource.h>
    #include <limits.h>

    typedef struct solver_s solver_t;
    typedef struct generator_s generator_t;
    typedef struct cell_s cell_t;
    typedef struct pos_s pos_t;

    struct pos_s {
        int x;
        int y;
    };

    struct generator_s {
        int x;
        int y;
        char **map;
    };

    struct solver_s {
        bool **maze;
        bool **here;
        bool **path;
        int height;
        int width;
    };

    generator_t *init_generator(int x, int y);
    void create_imperfect(int x, int y);
    void generate_map(generator_t *generator);

    char **path_to_map(char *path);
    void print_map(char **map, bool **path, int height, int width);
    bool solve_maze(solver_t *maze);
    bool rec_solve(int x, int y, solver_t *maze);

#endif
