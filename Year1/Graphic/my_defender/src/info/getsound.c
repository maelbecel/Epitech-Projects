/*
** EPITECH PROJECT, 2022
** getsound.c
** File description:
** getsound.c
*/

#include "my.h"
#include "printf.h"
#include "defender.h"


int getsoundlevel(void)
{
    int fd = open(SOUND_FILE, O_RDONLY);
    char buffer[3];
    read(fd, buffer, 3);
    close(fd);
    return my_getnbr(buffer);
}

void setsoundlevel(int level)
{
    int fd = open(SOUND_FILE, O_WRONLY);
    if (level > 99)
        write(fd, "99", 2);
    else if (level < 0)
        write(fd, "0", 1);
    else
        write(fd, inttochar(level), 2);
    close(fd);
}