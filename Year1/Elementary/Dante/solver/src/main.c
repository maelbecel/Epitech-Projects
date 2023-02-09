/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "dante.h"

solver_t *init_solver(char *path)
{
    char **map = path_to_map(path);
    solver_t *maze = malloc(sizeof(solver_t));

    if (map == NULL)
        return NULL;
    maze->width = my_strlen(map[0]);
    maze->height = my_strarraylen(map);
    maze->maze = malloc(sizeof(bool *) * maze->height + 1);
    for (size_t i = 0; (int)i < maze->height; i++) {
        maze->maze[i] = malloc(sizeof(bool) * maze->width + 1);
        for (size_t j = 0; (int)j < maze->width; j++)
            maze->maze[i][j] = (map[i][j] == '*') ? false : true;
    }
    return maze;
}

char **path_to_map(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return NULL;
    struct stat file;
    stat(path, &file);
    char *map = malloc(sizeof(char) * file.st_size + 1);
    if (map == NULL)
        return NULL;
    read(fd, map, file.st_size);
    map[file.st_size] = '\0';
    char **array = my_str_to_word_array(map, '\n');
    return array;
}

bool overflow(void)
{
    struct rlimit limit = {};
    if (getrlimit(RLIMIT_STACK, &limit) == -1)
        return false;
    limit.rlim_cur = (size_t) 1024 * 1024 * (16 * 1000);
    if (setrlimit(RLIMIT_STACK, &limit) == -1)
        return false;
    return true;
}

int main (int ac, char **argv)
{
    solver_t *maze;
    overflow();
    if (ac != 2)
        return 84;
    if (!(maze = init_solver(argv[1])))
        return 84;
    if (!solve_maze(maze))
        my_printf("no solution found\n");
    else {
        maze->path[maze->height - 1][maze->width -1] = true;
        print_map(path_to_map(argv[1]), maze->path, maze->height,
                    maze->width);
    }
    return 0;
}
