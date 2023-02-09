/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

void array_1d_to_2d (const int *array, size_t height, size_t width, int ***res)
{
    *res = malloc(sizeof(int *) * height);
    for (size_t i = 0; i < height; i++) {
        (*res)[i] = malloc(sizeof(int) * width);
        for (size_t j = 0; j < width; j++) {
            (*res)[i][j] = array[i * width + j];
        }
    }
}

void array_2d_free (int **array, size_t height,
                    __attribute__((unused)) size_t width)
{
    for (size_t i = 0; i < height; i++) {
        free(array[i]);
    }
    free(array);
}
