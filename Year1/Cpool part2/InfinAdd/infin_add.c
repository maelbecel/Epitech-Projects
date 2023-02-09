/*
** EPITECH PROJECT, 2021
** infin_add.c
** File description:
** xxx
*/

#include <stdlib.h>

void my_putstr(char *c);
int my_strlen(char *c);
void my_putchar(char c);
int my_str_isnum(char *c);
int my_puterror(char const *str );
int error (char * s1);
char * moins (char * s1);
void printres(char *res, int r, char mode);
int lenmax (char * s1, char * s2);

int add (char x, char y, int r)
{
    return ((x - 48)+(y - 48)+r);
}

int sous (char x, char y, int r)
{

    return ((x - 48)-((y - 48)+r));
}

int infin_del (char * s1, char * s2)
{
    int len_s1 = my_strlen(s1)-1;
    int len_s2 = my_strlen(s2)-1;
    char res[lenmax(s1,s2)];
    int i = lenmax(s1,s2)-1;
    int r = 0;
    int x;
    int t;

    res[i] = '\0';
    i--;
    while (len_s1 >= 0 || len_s2 >= 0) {
        if (len_s1 < 0)
            x = sous('0', s2[len_s2], r);
        else if (len_s2 < 0)
            x = sous(s1[len_s1], '0', r);
        else
            x = sous(s1[len_s1], s2[len_s2], r);
        if (x < 0) {
            r = 1;
            res[i] = (10 + x) + 48;
        } else {
            r = 0;
            res[i] = x + 48;
        }
        i--;
        len_s2--;
        len_s1--;
    }
    printres(res,r,'-');
}

int infin_add (char * s1, char * s2)
{
    int r = 0;
    int len_s1 = my_strlen(s1)-1;
    int len_s2 = my_strlen(s2)-1;
    char res[lenmax(s1,s2)];
    int i = lenmax(s1,s2)-1;
    int t;

    res[i] = '\0';
    i--;
    while (len_s1 >= 0 || len_s2 >= 0) {
        if (len_s1 < 0)
            t = add('0', s2[len_s2], r);
        else if (len_s2 < 0)
            t = add(s1[len_s1], '0', r);
        else
            t = add(s1[len_s1], s2[len_s2], r);
        res[i] = (t % 10) + 48;
        r = t / 10;
        i--;
        len_s2--;
        len_s1--;
    }
    printres(res,r,'+');
}

int main (int argc, char ** argv)
{

    if (error(argv[1]) == 1 || error(argv[2]) == 1){
        my_puterror("Only numbers are required\n");
        return 0;
    }
    if (argv[1][0] == '-' && argv[2][0] != '-'
        && my_str_isnum(argv[2]) == 1){
        infin_del(argv[2],moins(argv[1]));
    }
    if (argv[2][0] == '-' && argv[1][0] != '-'
        && my_str_isnum(argv[1]) == 1){
        infin_del(argv[1],moins(argv[2]));
    }
    if (argv[1][0] == '-' && argv[2][0] == '-') {
        my_putchar('-');
        infin_add(moins(argv[1]),moins(argv[2]));
    }
    if (argv[1][0] != '-' && argv[2][0] != '-'){
        infin_add(argv[1], argv[2]);
    }
    my_putchar('\n');
    return 0;
}