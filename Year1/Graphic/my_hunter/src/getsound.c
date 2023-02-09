/*
** EPITECH PROJECT, 2021
** getsound.c
** File description:
** getsound.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int getsoundlevel(void)
{
    int fd = open("log/soundlevel.txt", O_RDONLY);
    char buffer[3];
    read(fd, buffer, 3);
    close(fd);
    return my_getnbr(buffer);
}

void setsoundlevel(int level)
{
    int fd = open("log/soundlevel.txt", O_WRONLY);
    if (level > 99)
        write(fd, "99", 2);
    else if (level < 0)
        write(fd, "0", 1);
    else
        write(fd, inttochar(level), 2);
    close(fd);
}