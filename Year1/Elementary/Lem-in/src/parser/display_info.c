/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-lemin-lucas.iglesia
** File description:
** display info
*/

#include "my.h"
#include "printf.h"
#include "lemin.h"

static void print_input(char **input)
{
    my_printf("#tunnels\n");
    for (int i = 0; input[i] != NULL; i++) {
        if (is_link(input[i]))
            my_printf("%s", input[i]);
        if (input[i + 1] == NULL && input[i][my_strlen(input[i]) - 1] != '\n')
            my_printf("\n");
    }
}

static void print_room(lemin_t *lemin)
{
    my_printf("#rooms\n");
    for (int i = 0; lemin->room[i] != NULL; i++) {
        if (lemin->room[i]->start)
            my_printf("##start\n");
        if (lemin->room[i]->end)
            my_printf("##end\n");
        my_printf("%s %i %i\n", lemin->room[i]->name, lemin->room[i]->x,
                    lemin->room[i]->y);
    }
}

int print_info(lemin_t *lemin)
{
    my_printf("#number_of_ants\n%i\n", lemin->nbr_ant);
    if (lemin->size == 0)
        return 84;
    print_room(lemin);
    if (lemin->start == NULL || lemin->end == NULL)
        return 84;
    if (lemin->input != NULL)
        print_input(lemin->input);
    return EXIT_SUCCESS;
}
