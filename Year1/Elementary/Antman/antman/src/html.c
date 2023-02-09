/*
** EPITECH PROJECT, 2022
** B-CPE-110-REN-1-1-antman-mael1.becel
** File description:
** html
*/

#include "my.h"
#include "antman.h"
#include "printf.h"

int html(char *str)
{
    int fd = open(str, O_RDONLY);
    if (fd == -1)
        return 84;
    int size = getsize(str);
    if (size == -1)
        return 84;
    char *buf = malloc(sizeof(char) * (size + 1));
    if (!buf)
        return 84;
    buf[size] = '\0';

    if (read(fd, buf, size) != size)
        return 84;
    write(1, buf, my_strlen(buf));
    close(fd);
    free(buf);
    return 0;
}