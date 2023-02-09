/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#include "my.h"
#include "antman.h"
#include "printf.h"

int getsize(char *pathfile)
{
    struct stat buf;

    stat(pathfile,&buf);
    return buf.st_size;
}

int check_file(char *file, unsigned int mode)
{
    int size = my_strlen(file);
    switch (mode) {
        case 1 : {
            if (my_strcmp(file + (size - 4), ".txt") == 0)
                return 1;
            break;
        } case 2 : {
            if (my_strcmp(file + (size - 5), ".html") == 0)
                return 1;
            break;
        } case 3 : {
            if (my_strcmp(file + (size - 4), ".ppm") == 0)
                return 1;
            break;
        }
    }
    return 0;
}

int main(int ac, char **argv)
{
    if (ac != 3)
        return 84;
    if (my_strcmp(argv[2], "1") == 0 && check_file(argv[1], 1) == 1)
        return txt(argv[1]);
    if (my_strcmp(argv[2], "2") == 0 && check_file(argv[1], 2) == 1)
        return html(argv[1]);
    if (my_strcmp(argv[2], "3") == 0 && check_file(argv[1], 3) == 1)
        return img(argv[1]);
    return 0;
}