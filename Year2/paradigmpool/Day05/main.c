/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "string.h"

int main ( void )
{
    string_t s ;

    const char *array[] = {
        "Segmentation",
        "jej",
        "(core",
        "dumped)",
        NULL
    };

    printf("Init string...\n");
    string_init(&s, "Hey hey heyyy");
    printf("Split string...\n");
    char **spliter = s.split_c(&s, ' ');
    s.join_c(&s,'\n', spliter);
    printf("%s", s.str);
    s.clear(&s);
    for (int i = 0; spliter[i]; i++)
        free(spliter[i]);
    free(spliter);
    string_destroy (& s ) ;
    string_init(&s, "string");
    string_t *str = s.substr(&s, 0, -3);
    printf(" %s\n", str->str);
    return (0) ;
}
