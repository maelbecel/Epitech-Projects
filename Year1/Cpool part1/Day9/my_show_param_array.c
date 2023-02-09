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

struct info_param * my_params_to_array (int ac , char ** av );

int my_show_param_array ( struct info_param const * par )
{
    for (int i = 0; par[i] != NULL ;i++){
        my_putnum(par[i].length);
        my_putchar('\n');
        my_putcstr(par[i].copy);
        my_putchar('\n');
        my_putstr(par[i].str);
        my_putchar('\n');
    }
    return 0;
}
