/*
** EPITECH PROJECT, 2022
** B-CPE-110-REN-1-1-antman-mael1.becel
** File description:
** img
*/

#include "my.h"
#include "antman.h"
#include "printf.h"

int count_line(char *str, char separator)
{
    int nb = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator)
            nb++;
    }
    return nb;
}

int size_str(char *str, int i, char separator)
{
    int nb = 0;
    for (; str[i] != separator && str[i] != '\0'; i++) {
        nb++;
    }
    return nb;
}

char *fill_array(char *str, int i, char separator)
{
    int j = 0;
    int size = size_str(str, i, separator);
    char *arg = malloc(sizeof(char) * (size + 1));
    if (!arg)
        return NULL;
    for (; str[i] != separator && str[i] != '\0'; i++) {
        arg[j] = str[i];
        j++;
    }
    return arg;
}

void print_compress(char **array)
{
    unsigned char c = 0;
    for (int i = 0; array[i] != NULL; i++) {
        if (my_str_isnum(array[i]) == 1) {
            c = my_getnbr(array[i]);
            write(1, &c, 1);
            free(array[i]);
        }
        else {
            write(1, array[i], my_strlen(array[i]));
            write(1, "\n", 1);
            free(array[i]);
        }
    }
}

int img(char *str)
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
    close(fd);
    char **array = my_str_to_word_array(buf, '\n');
    print_compress(array);
    free(buf);
    free(array);
    return 0;
}
