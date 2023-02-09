/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** get_option
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"

int get_cycle(char **av, int i)
{
    int cycle = 0;
    if (my_str_isnum(av[i + 1])) {
        cycle = my_getnbr(av[i + 1]);
        if (cycle == 0)
            return CYCLE_TO_DIE;
        else
            return cycle;
    } else
        error("Invalid number of cycle\n");
    return CYCLE_TO_DIE;
}

bool get_dump(char **av, vm_t *vm)
{
    for (int i = 0; av[i]; i++) {
        if (my_strcmp(av[i], "-dump") == 0) {
            vm->nb_cycle = get_cycle(av, i);
            return false;
        }
    }
    return true;
}

static void init_cmp(int ac, vm_t *vm)
{
    for (int i = 0; i < ac - 1; i++) {
        vm->champ[i] = malloc(sizeof(champion_t));
        vm->champ[i]->load_address = -1;
        vm->champ[i]->prog_nb = -1;
        vm->champ[i]->live = false;
        vm->champ[i]->name = NULL;
    }
}

static int opt_get(char **av, vm_t *vm)
{
    int champ = 0;

    for (int i = 1; av[i]; i++) {
        if (my_strcmp(av[i], "-n") == 0 && av[i + 1]) {
            vm->champ[champ]->prog_nb = (my_str_isnum(av[i + 1])) ?
            my_getnbr(av[++i]) : error("Invalid number of champion\n");
            continue;
        } if (my_strcmp(av[i], "-a") == 0 && av[i + 1]) {
            vm->champ[champ]->load_address = (my_str_isnum(av[i + 1])) ?
                    my_getnbr(av[++i]) : error("Invalid adress of champion\n");
            continue;
        } if (av[i][0] != '-') {
            vm->champ[champ]->name = av[i];
            init_champ(vm->champ[champ++]);
            continue;
        } if (my_strcmp(av[i++], "-dump") != 0)
            error("Invalid flag\n");
    }
    return champ;
}

bool get_option(int ac, char **av, vm_t *vm)
{
    int chmp = 0;

    get_dump(av, vm);
    vm->champ = malloc(sizeof(champion_t *) * ac);
    init_cmp(ac, vm);
    chmp = opt_get(av, vm);
    vm->champ[chmp] = NULL;
    check_cmp(vm);
    return false;
}