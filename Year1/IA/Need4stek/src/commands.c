/*
** EPITECH PROJECT, 2022
** B-AIA-200-REN-2-1-n4s-lucas.iglesia
** File description:
** commands
*/

#include "my.h"
#include "printf.h"
#include "ia.h"

void turn_wheels(float nb)
{
    size_t size = 1024;
    char *buffer = malloc(sizeof(char) * size);
    int x;
    dprintf(1, "WHEELS_DIR:%f\n", nb);
    x = getline(&buffer, &size, stdin);
    buffer[x] = '\0';
}

void forward(float nb)
{
    size_t size = 1024;
    char *buffer = malloc(sizeof(char) * size);
    int x;
    dprintf(1, "CAR_FORWARD:%f\n", nb);
    x = getline(&buffer, &size, stdin);
    buffer[x] = '\0';
}

void backward(float nb)
{
    size_t size = 1024;
    char *buffer = malloc(sizeof(char) * size);
    int x;
    dprintf(1, "CAR_BACKWARDS:%f\n", nb);
    x = getline(&buffer, &size, stdin);
    buffer[x] = '\0';
}