/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "ia.h"

void print_elem(char **elem)
{
    if (elem[0] == NULL)
        dprintf(2, "test\n");
    for (int i = 0; elem[i] != NULL; i++)
        dprintf(2, "%s\n", elem[i]);
}

bool finish(void)
{
    size_t size = 1024;
    char *buffer = malloc(size);
    char **elements;
    int x;
    dprintf(1, "GET_INFO_LIDAR\n");
    x = getline(&buffer, &size, stdin);
    buffer[x] = '\0';
    elements = my_str_to_word_array(buffer, ':');
    if (my_strcmp(elements[35], "Track Cleared\n") == 0)
        return true;
    return false;
}

float get_angle_left(void)
{
    size_t size = 1024;
    char *buffer = malloc(size);
    char **elements;
    int x;
    dprintf(1, "GET_INFO_LIDAR\n");
    x = getline(&buffer, &size, stdin);
    buffer[x] = '\0';
    elements = my_str_to_word_array(buffer, ':');
    if (my_getnbr(elements[3]) < 400)
        return -0.60;
    if (my_getnbr(elements[10]) < 400)
        return -0.20;
    if (my_getnbr(elements[17]) < 400)
        return -0.10;
    return 0;
}

void wow(void)
{
    size_t size = 1024;
    char *buffer = malloc(size);
    char **elements;
    int x;
    dprintf(1, "GET_INFO_LIDAR\n");
    x = getline(&buffer, &size, stdin);
    buffer[x] = '\0';
    elements = my_str_to_word_array(buffer, ':');
    for(int i = 3; i < 35; i++)
        if (my_getnbr(elements[i]) <= 10) {
            dprintf(2, "Marche arriere\n");
            dprintf(1, "WHEELS_DIR:%i\n", 0);
            x = getline(&buffer, &size, stdin);
            dprintf(1, "CAR_FORWARD:0\n");
            x = getline(&buffer, &size, stdin);
            dprintf(1, "CAR_BACKWARDS:1\n");
            x = getline(&buffer, &size, stdin);
            usleep(100000);
            dprintf(1, "CAR_BACKWARDS:0\n");
            x = getline(&buffer, &size, stdin);
            dprintf(1, "CAR_FORWARD:0.3\n");
            x = getline(&buffer, &size, stdin);
        }
}

float get_angle_right(void)
{
    size_t size = 1024;
    char *buffer = malloc(size);
    char **elements;
    int x;
    dprintf(1, "GET_INFO_LIDAR\n");
    x = getline(&buffer, &size, stdin);
    buffer[x] = '\0';
    elements = my_str_to_word_array(buffer, ':');
    if (my_getnbr(elements[34]) < 400)
        return 0.60;
    if (my_getnbr(elements[27]) < 400)
        return 0.20;
    if (my_getnbr(elements[20]) < 400)
        return 0.10;
    return 0;
}

int main(UNUSED int ac, UNUSED char **av)
{
    size_t size = 1024;
    char *buffer = malloc(sizeof(char) * size);
    int x;
    UNUSED int left;
    UNUSED int right;
    // char **elements;
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    dprintf(1, "START_SIMULATION\n");
    x = getline(&buffer, &size, stdin);
    buffer[x] = '\0';
    while (!finish()) {
        speed();
        direction();
    }
    forward(0);
    dprintf(1, "CYCLE_WAIT:1\n");
    dprintf(1, "STOP_SIMULATION\n");
    return 0;
}
