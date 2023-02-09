/*
** EPITECH PROJECT, 2021
** hisseo.c
** File description:
** xxx
*/

#include <stddef.h>
#include <my.h>
#include <stdlib.h>

char* delpar(char *str)
{
    int keep = 0;
    int j = 0;
    char *res = malloc(my_strlen(str)+1);
    int bracket = 0;

    while (str[j] == '('){
        j++;
    }
    for (int i = 0; str[j] != '\0'; i++){
        if (str[j] == ')')
            break;
        res[i] = str[j];
        printf("str = %s\n",res);
        j++;
    }
    return res;

}

char *getsign(char sign)
{
    switch (sign){
        case '+' : return "+";
        case '-' : return "-";
    }
}

char *tri(char **oplist)
{
    char *prio = "";
    char *rest = "";
    char *op;
    int last = 999999;
    char *resultat;

    for (int i = 0; oplist[i] != NULL ; i++){
        if (oplist[i][my_strlen(oplist[i])-1] == '*' ||
            oplist[i][my_strlen(oplist[i])-1] == '/' ||
            oplist[i][my_strlen(oplist[i])-1] == '%'){
            last = i;
            prio = concatv2(prio, oplist[i]);
        }
    }
    if (last != 999999)
        prio = concatv2(prio, oplist[last + 1]);
    for (int i = 0; oplist[i] != NULL ; i++){
        if (oplist[i][my_strlen(oplist[i])-1] != '*' &&
            oplist[i][my_strlen(oplist[i])-1] != '/' &&
            oplist[i][my_strlen(oplist[i])-1] != '%' &&
            i != last + 1){
            rest = concatv2(rest, oplist[i]);
        }
    }
    if (rest[my_strlen(rest) - 1] < '0'){
        op = getsign(rest[my_strlen(rest) -1]);
        rest[my_strlen(rest) - 1] = '\0';
        resultat = concat(prio, op, rest);
        return concat(prio, op, rest);
    } else {
        return concatv2(prio, rest);
    }
}

char **listop(char *op)
{
    char **res = malloc(sizeof(int)*1000);
    int i = 0;
    int j = 0;
    int k = 0;

    while (k <= my_strlen(op)){
        res[i] = malloc(sizeof(int)*1000);
        while ((op[k] <= '9' && op[k] >= '0') || (op[k] == '-' && j == 0)){
            res[i][j] = op[k];
            j++;
            k++;
        }
        res[i][j] = op[k];
        k++;
        j = 0;
        i++;
    }
    res[i] = NULL;
    return res;
}