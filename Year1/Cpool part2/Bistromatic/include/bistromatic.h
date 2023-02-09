/*
** EPITECH PROJECT, 2021
** bistro.h
** File description:
** bistro.h
*/

#define OP_OPEN_PARENT_IDX  0
#define OP_CLOSE_PARENT_IDX  1
#define OP_PLUS_IDX         2
#define OP_SUB_IDX          3
#define OP_NEG_IDX          3
#define OP_MULT_IDX         4
#define OP_DIV_IDX          5
#define OP_MOD_IDX          6

#define EXIT_USAGE    84
#define EXIT_BASE     84
#define EXIT_SIZE_NEG  84
#define EXIT_MALLOC   84
#define EXIT_READ     84
#define EXIT_OPS      84

#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG        "error"

char *removez(char *res, char *base, char *baseop);
int getid(char c, char *base);
char *infinadd(char *calcul, char *base, char *baseop);
char *infinsub(char *calcul, char *base, char *baseop);
char *detection(char *calcul, char *base);
int charinarray(char c, char *base);
void samebase(char *basea, char *baseb);
char *get_expr(int size);
void error_in_av(char *expr, char *base, char *baseop, int size);
int operator(char *expr, char *base, char *baseop);
