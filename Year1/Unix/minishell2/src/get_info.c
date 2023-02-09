/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "shell.h"

char *getvalue(char **env, char *var)
{
    int i = 0;

    for (; env[i] != NULL; i++) {
        if (my_strcmp(getname(env[i]), var) == 0) {
            return my_strdup(env[i] + my_strlen(var) + 1);
        }
    }
    return NULL;
}

char *getname(char *string)
{
    char *varname = malloc(my_strlen(string) + 1);
    for (int i = 0; string[i] != '='; i++) {
        varname[i] = string[i];
        varname[i + 1] = '\0';
    }
    return varname;
}

void show_prompt(char **env)
{
    if (isatty(STDIN_FILENO))
        my_printf("%s", getprompt(env));
}