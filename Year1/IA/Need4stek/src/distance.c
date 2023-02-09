/*
** EPITECH PROJECT, 2022
** B-AIA-200-REN-2-1-n4s-lucas.iglesia
** File description:
** distance
*/

#include "my.h"
#include "printf.h"
#include "ia.h"

int get_distance_right(void)
{
    size_t size = 1024;
    char *buffer = malloc(size);
    char **elements;
    int x;
    dprintf(1, "GET_INFO_LIDAR\n");
    x = getline(&buffer, &size, stdin);
    buffer[x] = '\0';
    elements = my_str_to_word_array(buffer, ':');
    return (my_getnbr(elements[25]) + my_getnbr(elements[26]) +
            my_getnbr(elements[27]) + my_getnbr(elements[28]) +
            my_getnbr(elements[29])) / 5;
}

int get_distance_far_right(void)
{
    size_t size = 1024;
    char *buffer = malloc(size);
    char **elements;
    int x;
    dprintf(1, "GET_INFO_LIDAR\n");
    x = getline(&buffer, &size, stdin);
    buffer[x] = '\0';
    elements = my_str_to_word_array(buffer, ':');
    return (my_getnbr(elements[30]) + my_getnbr(elements[31]) +
            my_getnbr(elements[32]) + my_getnbr(elements[33]) +
            my_getnbr(elements[34])) / 5;
}

int get_distance_left(void)
{
    size_t size = 1024;
    char *buffer = malloc(size);
    char **elements;
    int x;
    dprintf(1, "GET_INFO_LIDAR\n");
    x = getline(&buffer, &size, stdin);
    buffer[x] = '\0';
    elements = my_str_to_word_array(buffer, ':');
    return (my_getnbr(elements[8]) + my_getnbr(elements[9]) +
            my_getnbr(elements[11]) + my_getnbr(elements[10]) +
            my_getnbr(elements[12])) / 5;
}

int get_distance_far_left(void)
{
    size_t size = 1024;
    char *buffer = malloc(size);
    char **elements;
    int x;
    dprintf(1, "GET_INFO_LIDAR\n");
    x = getline(&buffer, &size, stdin);
    buffer[x] = '\0';
    elements = my_str_to_word_array(buffer, ':');
    return (my_getnbr(elements[3]) + my_getnbr(elements[4]) +
            my_getnbr(elements[5]) + my_getnbr(elements[6]) +
            my_getnbr(elements[7])) / 5;
}

int get_distance(void)
{
    size_t size = 1024;
    char *buffer = malloc(size);
    char **elements;
    int x;
    dprintf(1, "GET_INFO_LIDAR\n");
    x = getline(&buffer, &size, stdin);
    buffer[x] = '\0';
    elements = my_str_to_word_array(buffer, ':');
    return (my_getnbr(elements[17]) + my_getnbr(elements[18]) +
            my_getnbr(elements[19]) + my_getnbr(elements[20]) +
            my_getnbr(elements[21])) / 5;
}