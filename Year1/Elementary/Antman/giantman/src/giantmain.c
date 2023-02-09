/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "printf.h"
#include "giantman.h"

int getsize (char *pathfile)
{
    struct stat buf;
    int tmp = 0;

    tmp = stat(pathfile,&buf);
    if (tmp == -1)
        return tmp;
    return buf.st_size - 2;
}

int main (int ac, char **argv)
{
    if (ac != 3)
        return 84;
    if (my_strcmp(argv[2], "1") == 0)
        return txt(argv[1]);
    if (my_strcmp(argv[2], "2") == 0)
        return html(argv[1]);
    if (my_strcmp(argv[2], "3") == 0)
        return img(argv[1]);
    return 0;
}
