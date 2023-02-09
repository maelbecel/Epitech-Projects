/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void do_aff(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    int reg = 0;

    va_end(arg);
    move_prog(prog);
    reg = get_param(vm, prog->coord, 2) % 256;
    my_printf("%c\n", prog->reg[reg - 1]);
    move_prog(prog), move_prog(prog);
}
