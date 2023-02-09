/*
** EPITECH PROJECT, 2022
** env
** File description:
** env
*/

#include "my.h"
#include "printf.h"
#include "shell.h"

void my_puterror(char *string)
{
    write(2, string, my_strlen(string));
}

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
        if (my_strcmp(getname(env[i]),parsed[1]) == 0) {
            decal = 1;
            env[i] = NULL;
        } else if (decal == 1) {
            env[i - 1] = malloc(my_strlen(env[i] + 1));
            env[i - 1] = env[i];
            env[i] = NULL;
        }
    }
}

int char_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}

int char_num(char c)
{
    if ((c >= '0' && c <= '9'))
        return 1;
    return 0;
}

int is_alpha_num(char *string)
{
    for (int i = 0; i < my_strlen(string); i++) {
        if (!(char_alpha(string[i]) || char_num(string[i]) || string[i] == '_'))
            return 0;
    }
    return 1;
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
        my_puterror("setenv: Variable name must contain alphanumeric characters.\n");
        return;
    } if (parsed[2] == NULL)
        parsed[2] = "\0";
    for (; env[i] != NULL; i++) {
        if (my_strcmp(getname(env[i]),parsed[1]) == 0){
            env[i] = create_var(getname(env[i]), parsed[2]);
            return;
        }
    }
    env[i++] = create_var(parsed[1], parsed[2]);
    env[i] = NULL;
}

void changedir(char **parsed, char **env)
{
    size_t size = 10000;
    char *buf = malloc(size);
    char *var = malloc(size);
    char *oldpwd = malloc(size);
    char *old = getvalue(env, "PWD");

    if (parsed[2] != NULL){
        my_puterror("cd: Too many arguments.\n");
        return;
    } else if (parsed[1] == NULL || my_strcmp(parsed[1],"--") == 0 || my_strcmp(parsed[1],"~") == 0)
        chdir(getvalue(env, "HOME"));
    else if (my_strcmp(parsed[1],"-") == 0)
        chdir(getvalue(env, "OLDPWD"));
    else if (my_strcmp(parsed[1],".") == 0)
        chdir(getvalue(env, "PWD"));
    else if (opendir(parsed[1]) == 0 && errno == EACCES) {
        my_puterror(parsed[1]);
        my_puterror(": Permission denied.\n");
        return;
    } else if (opendir(parsed[1]) == 0 && !access(parsed[1],F_OK)) {
        my_puterror(parsed[1]);
        my_puterror(": Not a directory.\n");
        return;
    } else if (opendir(parsed[1]) == 0 && access(parsed[1],F_OK)) {
        my_puterror(parsed[1]);
        my_puterror(": No such file or directory.\n");
        return;
    } else
        chdir(parsed[1]);
    var = my_strcat(var,"PWD=");
    oldpwd = my_strcat(oldpwd,"OLDPWD=");
    var = my_strcat(var,getcwd(buf,size));
    oldpwd = my_strcat(oldpwd,old);
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strcmp(getname(env[i]),"PWD") == 0)
            env[i] = var;
        else if (my_strcmp(getname(env[i]),"OLDPWD") == 0)
            env[i] = oldpwd;
    }
}

void print_arg ( char ** arg )
{
    while (* arg ) {
        my_putstr(* arg );
        my_putchar('\n');
        arg++;
    }
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
