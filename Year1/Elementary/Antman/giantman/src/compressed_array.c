/*
** EPITECH PROJECT, 2022
** B-CPE-110-REN-1-1-antman-mael1.becel
** File description:
** compressed_array
*/

#include "my.h"
#include "giantman.h"
#include "printf.h"

static int my_str_enter(char *str, int i)
{
    int nb = 0;
    for (; str[i] != '\n'; i++) {
        nb++;
    }
    return nb;
}

int skip_header(char *str, int i, unsigned char **array, int *j)
{
    for (; *j < 3; *j += 1) {
        array[*j] = malloc(sizeof(char) * my_str_enter(str, i));
        if (!array[*j])
            return -1;
        for (int k = 0; str[i] != '\n'; i++) {
            array[*j][k] = str[i];
            k++;
        }
        i++;
    }
    if (str[i] == '#') {
        for (int k = 0; str[i] != '\n'; i++) {
            array[*j][k] = str[i];
            k++;
        }
        i++;
    }
    return i;
}

unsigned char **compressed_to_array(char *str, int size)
{
    int i = 0;
    int j = 0;
    unsigned char **array = malloc(sizeof(unsigned char *) * size);
    if (!array)
        return NULL;

    i = skip_header(str, i, array, &j);
    if (i == -1)
        return NULL;
    for (; i != size; i++) {
        array[j] = malloc(sizeof(unsigned char) * 2);
        if (!array[j])
            return NULL;
        array[j][0] = str[i];
        array[j][1] = '\0';
        j++;
    }
    array[j] = NULL;
    return array;
}
