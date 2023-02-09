/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

void my_putchar(char c);
int santiano(char *str);
int nbop(char *av);
int my_intstrlen(char *str);
int detection(char *av);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen( char const *str);
int eval_expr(char *str);
int calcul(int nb1, char signe, int nb2);
int my_str_isnum(char *str);
int unvalidinput(char *av);
int my_strncmp(char const *s1, char const *s2, int n);
char *inttochar(int num);
char* delpar(char *str);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char *concat(char *before, char *mid, char *after);
char *concatv2(char *s1, char *s2);
char *tri(char **oplist);
char *my_strstart(char *str, char const *to_find);
char **listop(char *op);
