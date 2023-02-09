/*
** EPITECH PROJECT, 2022
** env
** File description:
** env
*/

#include "my.h"
#include "printf.h"
#include "shell.h"

void unset_env(char **parsed, char **env)
{
    int len = my_strarraylen(parsed);
    int i = 0;
    int decal = 0;

    if (len > 2 ){
        my_puterror("unsetenv: Too many arguments.\n");
        return;
    } else if (len < 2){
        my_puterror("unsetenv: Too few arguments.\n");
        return;
    }
    for (; env[i] != NULL; i++) {
        if (my_strcmp(getname(env[i]), parsed[1]) == 0) {
            decal = 1;
            env[i] = NULL;
        } else if (decal == 1) {
            env[i - 1] = malloc(my_strlen(env[i] + 1));
            env[i - 1] = env[i];
            env[i] = NULL;
        }
    }
}

void set_env(char **parsed, char **env)
{
    int len = my_strarraylen(parsed);
    int i = 0;

    if (len > 3 ){
        my_puterror("setenv: Too many arguments.\n");
        return;
    } else if (len == 1){
        print_arg(env);
        return;
    } else if (!char_alpha(parsed[1][0])) {
        my_puterror("setenv: Variable name must begin with a letter.\n");
        return;
    } else if (!is_alpha_num(parsed[1])) {
        my_puterror("setenv: Variable name must");
        my_puterror("contain alphanumeric characters.\n");
        return;
    } if (parsed[2] == NULL)
        parsed[2] = "\0";
    for (; env[i] != NULL; i++) {
        if (my_strcmp(getname(env[i]), parsed[1]) == 0){
            env[i] = create_var(getname(env[i]), parsed[2]);
            return;
        }
    }
    env[i++] = create_var(parsed[1], parsed[2]);
    env[i] = NULL;
}

int my_exit (char **arg)
{
    my_printf("exit\n");
    if (arg[1] != NULL && my_str_isnum(arg[1]))
        return my_getnbr(arg[1]);
    else
        return 0;
}

void bad_exit (char **arg)
{
    if (!my_str_isnum(arg[1]) || arg[2] != NULL)
        my_printf("exit: Expression Syntax.\n");
}
