/*
** EPITECH PROJECT, 2022
** man
** File description:
** man
*/

#ifndef man
    #define man
    #include <stdio.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct words_s {
        char *words;
        int symbol;
    } words_t;

    int getsize(char *pathfile);
    int img(char *str);
    int html(char *str);
    char **my_str_to_word_array(char *str, char separator);

    int txt(char *str);
    char *buftoi(char *buf, words_t **words);
    words_t ** getwords(char *buf);
    int get_nbwords(char *buf);
    int check_word(words_t **list, char *word);

#endif /* !man */
