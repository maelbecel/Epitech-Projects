/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-lemin-lucas.iglesia
** File description:
** read_input
*/

#include "my.h"
#include "printf.h"
#include "lemin.h"

char *concat(char *before, char *mid, char *after)
{
    char *res = malloc(my_strlen(after) + my_strlen(mid) +
                                            my_strlen(before) + 1);
    int i = 0;

    if (res == NULL)
        return NULL;
    for (int j = 0; before[j] != '\0'; j++){
        res[i] = before[j];
        i++;
    }
    for (int j = 0; mid[j] != '\0'; j++){
        res[i] = mid[j];
        i++;
    }
    for (int j = 0; after[j] != '\0'; j++){
        res[i] = after[j];
        i++;
    }
    res[i] = '\0';
    return res;
}

char **read_input(void)
{
    char **anthill = NULL;
    char *str = NULL;
    char *input = NULL;
    size_t n = 0;
    size_t i = 0;

    while (getline(&str, &n, stdin) != -1) {
        if (i == 0) {
            input = malloc(sizeof(char) * my_strlen(str) + 1);
            input = (input == NULL) ? NULL : my_strcpy(input, str);
        } else
            input = concat(input, ";", str);
        i++;
        if (input == NULL)
            return NULL;
    }
    anthill = my_str_to_word_array(input, ';');
    free(str);
    free(input);
    return (anthill != NULL) ? anthill : NULL;
}
