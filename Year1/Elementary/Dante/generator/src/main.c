/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-lucas.iglesia
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "dante.h"

void print_generate_map(generator_t *generator)
{
    for (int i = 0; i < generator->y; i++) {
        if (i + 1 == generator->y)
            my_printf("%s", generator->map[i]);
        else
            my_printf("%s\n", generator->map[i]);
    }
}

int main(int ac, char **av)
{
    int x = my_getnbr(av[1]);
    int y = my_getnbr(av[2]);
    if (ac == 4 && !my_strcmp(av[3], "perfect")) {
        generator_t *generator = init_generator(x, y);
        generate_map(generator);
        print_generate_map(generator);
    } else if (ac == 3)
        create_imperfect(x, y);
    return 0;
}