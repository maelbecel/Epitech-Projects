/*
** EPITECH PROJECT, 2022
** getsound.c
** File description:
** getsound.c
*/

#include "my.h"
#include "printf.h"
#include "defender.h"


int getscore(void)
{
    FILE *fd = fopen(SCORE_FILE, "r");

    size_t size = 1024;
    char *buf = malloc(sizeof(char) * size );
    if (buf == NULL || getline(&buf, &size, fd) == -1)
        return -1;
    buf[my_strlen(buf)] = '\0';
    return my_getnbr(buf);;
}

void setscore(int level)
{
    int fd = open(SCORE_FILE, O_WRONLY);
    if (getscore() < level)
        write(fd, inttochar(level), my_strlen(inttochar(level)));
    close(fd);
}