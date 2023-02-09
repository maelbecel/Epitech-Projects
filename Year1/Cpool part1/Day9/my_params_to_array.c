/*
** EPITECH PROJECT, 2021
** my_params
** File description:
** xxx
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include "include/infoparam.h"

struct info_param * my_params_to_array (int ac , char ** av )
{
    struct info_param *res;

    while (i < ac) {
        res[i].length = my_strlen(av[i]);
        res[i].str = av[i];
        res[i].copy = my_strdup(av[i]);
        res[i].word_array = my_str_to_word_array(av[i]);
        i++;
    }
    return res;
}
