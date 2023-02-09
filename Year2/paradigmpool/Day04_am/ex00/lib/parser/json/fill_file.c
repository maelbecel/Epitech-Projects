/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "parser.h"

void fill_file(char *file, char *buffer)
{
    int fd = open(file, O_WRONLY);
    buffer[my_strlen(buffer)] = '\0';
    write(fd, buffer, my_strlen(buffer));
    close(fd);
}
