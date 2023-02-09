/*
** EPITECH PROJECT, 2022
** man
** File description:
** man
*/

#ifndef MAN
    #define MAN
    #include <stdio.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <stdlib.h>

    int getsize(char *pathfile);
    int img(char *str);
    char **my_str_to_word_array(char *str, char separator);
    int html(char *str);
    int txt(char *argv);
    unsigned char **compressed_to_array(char *str, int size);
    int skip_header(char *str, int i, unsigned char **array, int *j);

    typedef struct words_s {
        char *words;
        int symbol;
    } words_t;

#endif /* !man */
