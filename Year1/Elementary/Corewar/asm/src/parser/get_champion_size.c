/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** return instructions array
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"

const char *cmd[] = {
    "lfork",
    "sti",
    "fork",
    "ldi",
    "lldi",
    "zjmp",
    NULL,
};

int get_params_size(ATTRIBUT attribut, bool index_params)
{
    if (attribut == A_REG)
        return 1;
    if ((attribut == A_DIR || attribut == A_IND) && index_params)
        return 2;
    if (attribut == A_DIR)
        return DIR_SIZE;
    if (attribut == A_IND)
        return IND_SIZE;
    return 0;
}

bool is_index_type(char *str)
{
    for (size_t pos = 0; cmd[pos] != NULL; pos++) {
        if (my_strcmp(str, cmd[pos]) == 0)
            return true;
    }
    return false;
}

static int convert_size_to_int(instruction_t *tmp)
{
    int size = 1;
    int index = 0;
    bool index_params;
    int result = 0;

    index = get_op(tmp->str);
    if (op_tab[index].nbr_args != 1 || op_tab[index].code == 16)
        size++;
    index_params = is_index_type(tmp->str);
    while (tmp != NULL) {
        if (tmp->attribut >= A_REG) {
            result = get_params_size(tmp->attribut, index_params);
            size += result;
        }
        tmp = tmp->next;
    }
    return size;
}

int get_instruction_size(instruction_t *instruction, bool is_short)
{
    instruction_t *tmp = instruction;

    if (tmp->next->type == T_LABEL) {
        tmp = tmp->next;
        if (!tmp->next)
            return 0;
        else
            tmp = tmp->next->next;
    }
    if (!is_short)
        return convert_size_to_int(tmp);
    else
        return convert_size_to_short(tmp);
}

void get_champion_size(header_t *header, instruction_t **instructions)
{
    for (size_t pos = 0; instructions[pos] != NULL; pos++)
        header->prog_size += get_instruction_size(instructions[pos], false);
    header->prog_size = htobe32(header->prog_size);
}
