/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-lucas.iglesia
** File description:
** generator
*/

#include "my.h"
#include "printf.h"
#include "dante.h"

static bool is_even(int nb)
{
    if (nb % 2 == 0)
        return true;
    else
        return false;
}

static void write_cell(generator_t *generator, int i, int j)
{
    if (is_even(rand())) {
        generator->map[i][j] = '*';
        if (i > 0)
            generator->map[i - 1][j] = '*';
    } else {
        generator->map[i][j] = '*';
        if (j > 0)
            generator->map[i][j - 1] = '*';
    }
}

void generate_map(generator_t *generator)
{
    time_t t;

    srand(time(&t));
    for (int i = 0; generator->map[i] != NULL; i += 2) {
        for (int j = 0; generator->map[i][j] != '\0'; j += 2) {
            write_cell(generator, i, j);
        }
    }
    if (is_even(generator->x) && is_even(generator->y))
        generator->map[generator->y - 1][generator->x - 2] = '*';
    generator->map[generator->y - 1][generator->x - 1] = '*';
}