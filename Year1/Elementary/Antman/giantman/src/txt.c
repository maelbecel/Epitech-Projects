/*
** EPITECH PROJECT, 2022
** txt
** File description:
** txt
*/

#include "my.h"
#include "giantman.h"
#include "printf.h"

words_t **getwords (char *buffer)
{
    words_t **res  = malloc(sizeof(words_t *) * my_strlen(buffer));
    char *temp = malloc(sizeof(char) * my_strlen(buffer));
    int i = 0;
    int x = 0;

    while (buffer[i] != '|')
        i++;
    i++;

    for (; i < my_strlen(buffer); i++) {
        for (int t = 0; buffer[i] != '|' && i < my_strlen(buffer); i++){
            temp[t++] = buffer[i];
            temp[t] = '\0';
        }
        res[x] = malloc(sizeof(words_t));
        res[x]->symbol = x;
        res[x++]->words = my_strdup(temp);
        res[x] = NULL;
        temp[0] = '\0';
    }
    return res;
}

int my_intlen(int x)
{
    int res = 1;

    for (; x >= 10; res++)
        x /= 10;
    return res;
}

void print_buf(char *buf, words_t **words)
{
    int w = 0;

    for (int i = 0; buf[i] != '|'; i++) {
        if (buf[i] == ' ' || buf[i] == '\n')
            my_printf("%c", buf[i]);
        else {
            w = my_getnbr(buf + i);
            my_printf("%s", words[w]->words);
            i += my_intlen(w) - 1;
        }
    }
}

int txt(char *argv)
{
    int fd = open(argv, O_RDONLY);
    int size = getsize(argv);
    char *buf = malloc(sizeof(char) * size);
    words_t **words;

    if (fd == -1)
        return 84;
    if (read(fd, buf, size) == -1)
        return 84;
    buf[size] = '\0';

    words = getwords(buf);
    print_buf(buf, words);
    return 0;
}
