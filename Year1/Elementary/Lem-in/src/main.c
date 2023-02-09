/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-lemin-lucas.iglesia
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "lemin.h"

static int verif_rooms(room_t *start, room_t *end)
{
    int exit_value = EXIT_FAILURE;

    start->is_visited = true;
    for (size_t i = 0; start->next[i] != NULL; i++) {
        if (start->next[i] != NULL && !start->next[i]->is_visited) {
            if (start->next[i] == end) {
                return EXIT_SUCCESS;
            }
            exit_value = verif_rooms(start->next[i], end);
        }
    }
    return exit_value;
}

static int find_path(lemin_t *lemin)
{
    ant_t *ants = malloc(sizeof(ant_t) * lemin->nbr_ant);

    if (ants == NULL)
        return (84);
    reset_visited(lemin);
    for (int i = 0; i < lemin->nbr_ant; i++) {
        ants[i].nb = i + 1;
        ants[i].room = lemin->start;
    }
    init_distance(lemin);
    my_putstr("#moves\n");
    solver(lemin, ants);
    return 0;
}

int main(UNUSED int ac, UNUSED char **av)
{
    lemin_t *lemin = init_lemin();

    if (lemin == NULL)
        return 84;
    if (print_info(lemin) == 84)
        return 84;
    if (lemin->start->next == NULL)
        return 84;
    if (verif_rooms(lemin->start, lemin->end) == EXIT_FAILURE)
        return 84;
    return find_path(lemin);
}
