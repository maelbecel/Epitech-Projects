/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void sort(int *array, size_t nmemb)
{
    int tmp = 0;

    for (size_t j = 0; j < nmemb - 1; j++) {
        if (array[j] > array[j + 1]) {
            tmp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = tmp;
        }
    }
}

void sort_int_array (int *array, size_t nmemb)
{
    for (size_t i = 0; i < nmemb; i++) {
        sort(array, nmemb);
    }
}

void sorter(void *array, size_t nmemb, int (*compar)(const void *,
            const void *), size_t size)
{
    for (size_t j = 0; j < nmemb - 1; j++) {
        if ((*compar)((char *)array + j * size,
            (char *)array + (j + 1) * size) > 0){
            void *tmp = malloc(size);
            memcpy(tmp, (char *)array + j * size, size);
            memcpy((char *)array + j * size,
                (char *)array + (j + 1) * size, size);
            memcpy((char *)array + (j + 1) * size, tmp, size);
            free(tmp);
        }
    }
}

void sort_array(void *array, size_t nmemb, size_t size,
                int (*compar)(const void *, const void *))
{
    for (size_t i = 0; i < nmemb; i++) {
        sorter(array, nmemb, compar, size);
    }
}
