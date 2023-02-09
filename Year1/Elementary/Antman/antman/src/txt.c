/*
** EPITECH PROJECT, 2022
** txt
** File description:
** txt
*/

#include "my.h"
#include "antman.h"
#include "printf.h"

int txt(char *str)
{
    int fd = open(str, O_RDONLY);
    if (fd == -1)
        return 84;
    int size = getsize(str);
    char *buf = malloc(sizeof(char) * size);
    words_t **words = NULL;
    char *intbuffer;

    read(fd, buf, size);
    words = getwords(buf);
    intbuffer = buftoi(buf,words);
    my_printf("%s",intbuffer);
    for ( int i = 0; words[i] != NULL; i++) {
        my_printf("|%s",words[i]->words, words[i]->symbol);
    }
    my_printf("|\n");
    return 0;
}

char *buftoi(char *buf, words_t **words)
{
    char *temp = malloc(sizeof(char) * my_strlen(buf));
    char *t = malloc(sizeof(char) * 2);
    char *res = "";
    int num;

    for (int i = 0; i < my_strlen(buf); i++) {
        for (int j = 0; buf[i] != '\n' && buf[i] != ' '; i++) {
            temp[j++] = buf[i];
            temp[j] = '\0';
        }
        num = check_word(words,temp);
        if (num != -1)
            res = concat(res,inttochar(words[num]->symbol),"\0");
        if ((buf[i] == '\n' || buf[i] == ' ') && i < my_strlen(buf) - 1) {
            t[0] = buf[i];
            t[1] = '\0';
            res = concat(res,t,"\0");
        }
    }
    return res;
}

words_t ** getwords(char *buf)
{
    words_t **words = malloc(sizeof(words_t *) * get_nbwords(buf));
    char *temp = malloc(sizeof(char) * my_strlen(buf));
    int j = 0;
    int x = 0;

    temp[0] = '\0';
    words[0] = NULL;
    for (int i = 0; i < my_strlen(buf); i++) {
        if (buf[i] != ' ' && buf[i] != '\n' && buf[i] <= 127) {
            temp[j++] = buf[i];
            temp[j] = '\0';
        } else if ((buf[i] == ' ' || buf[i] == '\n') && temp[0] != '\0' && check_word(words, temp) == -1) {
            words[x] = malloc(sizeof(words_t));
            words[x]->words = my_strdup(temp);
            words[x]->symbol = x;
            j = 0;
            temp[0] = '\0';
            x++;
            words[x] = NULL;
        } else if ((buf[i] == ' ' || buf[i] == '\n') && temp[0] != '\0' && check_word(words, temp) != -1) {
            j = 0;
            temp[0] = '\0';
        }
    }
    if ((buf[my_strlen(buf) - 1] != ' ' && buf[my_strlen(buf) - 1] != '\n') && check_word(words, temp) == -1){
        words[x] = malloc(sizeof(words_t));
        words[x]->words = my_strdup(temp);
        words[x]->symbol = x;
        words[x + 1] = NULL;
    } else
        words[x] = NULL;
    return words;
}

int get_nbwords(char *buf)
{
    int nbwords = 0;
    for (int i = 0; i < my_strlen(buf) - 1; i++) {
        if (buf[i] != ' ' && buf[i + 1] == ' ')
            nbwords++;
    }
    return nbwords + 1;
}

int check_word(words_t **list, char *word)
{
    if (list[0] == NULL)
        return -1;
    for (int i = 0; list[i] != NULL; i++) {
        if (my_strcmp(list[i]->words, word) == 0)
            return i;
    }
    return -1;
}