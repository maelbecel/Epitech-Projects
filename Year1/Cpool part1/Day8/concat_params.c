/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** xxx
*/

#include <stdlib.h>

int my_strlen (int i);

char * concat_params ( int argc , char ** argv )
{
    int n = 0;
    char *dest;
    int mem;
    
    for (int i = 0 ; argv[i] != NULL ; i++) {
        mem += my_strlen(argv[i]);
    }

    dest = malloc(mem);

    for (int i = 1; i < argc; i += 2) {
        dest[i-1] = argv[n];
        dest[i] = '\n';
        n += 1;
    }
    return dest;
}