/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool is_in_array(int *array, int x)
{
    for (size_t i = 0; array[i] != '\0'; i++) {
        if (array[i] == x)
            return (true);
    }
    return (false);
}

size_t uniq_int_array(int *array, size_t nmemb)
{
    int *new_array = malloc(sizeof(int) * (nmemb + 1));
    size_t j = 0;

    for (size_t i = 0; i < nmemb; i++) {
        if (!is_in_array(array, array[i]))
            new_array[j++] = array[i];
    }
    for (size_t i = 0; i < j; i++) {
        array[i] = new_array[i];
    }
    free(new_array);
    return (j);
}

bool is_in(void *element, size_t list[2], void *new_array,
            int (*compar)(const void * ,const void *))
{
    size_t size = list[0];
    size_t x = list[1];
    for (size_t j = 0; j < x; j++) {
        if (compar(element,
            (char *)new_array + j * size) == 0) {
            return true;
        }
    }
    return false;
}

size_t uniq_array(void * array, size_t nmemb, size_t size,
                    int (*compar)(const void * ,const void *))
{
    void *new_array = malloc(size * (nmemb + 1));
    size_t x = 1;

    memcpy((char *)new_array, (char *)array, size);
    for (size_t i = 0; i < nmemb; i++) {
        size_t list[2] = {size, x};
        if (!is_in((char *)array + i * size, list, new_array, compar)) {
            memcpy((char *)new_array + x * size,
                    (char *)array + i *size, size);
            x++;
        }
    }
    for (size_t i = 0; i < x; i++) {
        memcpy((char *)array + i * size, (char *)new_array + i * size, size);
    }
    free(new_array);
    return (x);
}
