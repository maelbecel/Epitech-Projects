/*
** EPITECH PROJECT, 2022
** B-CPE-110-REN-1-1-antman-mael1.becel
** File description:
** img
*/

#include "my.h"
#include "giantman.h"
#include "printf.h"

static int my_strlen_u(unsigned char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    return i;
}

void print_decompressed(unsigned char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        if (i < 3) {
            my_printf("%s\n", array[i]);
            free(array[i]);
        }
        else if (array[i][0] == '#' && my_strlen_u(array[i]) > 1) {
            my_printf("%s\n", array[i]);
            free(array[i]);
        }
        else {
            my_put_nbr(array[i][0]);
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
    unsigned char **array = compressed_to_array(buf, size);
    print_decompressed(array);
    free(buf);
    free(array);
    return 0;
}
