/*
** EPITECH PROJECT, 2021
** input
** File description:
** input.c
*/

#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include <signal.h>
#include <string.h>
#include "navy.h"
#include <stdio.h>
#include "printf.h"

char *get_input(void)
{
    char *input = NULL;
    ssize_t size = 0;
    size_t len = 0;
    while (1){
        my_printf("\nattack : ");
        size = getline(&input, &len, stdin);
        if ((size != 3 && size != 0) || (input[0] > 'H' ||
            input[0] < 'A') || (input[1] > '8' || input[1] < '1'))
            my_printf("wrong position");
        else if (size == 3)
            break;
    }
    input[size -1] = '\0';
    return input;
}
