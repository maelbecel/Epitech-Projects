/*
** EPITECH PROJECT, 2022
** env
** File description:
** env
*/

#include "my.h"
#include "printf.h"
#include "shell.h"

void update_env_path(char **env)
{
    size_t size = 10000;
    char *var = malloc(size);
    char *oldpwd = malloc(size);
    char *buf = malloc(size);
    char *old = getvalue(env, "PWD");
    int i = 0;

    if (getvalue(env, "OLDPWD") == NULL) {
        for (; env[i] != NULL; i++);
        env[i++] = create_var("OLDPWD", old);
        env[i] = NULL;
    }
    var = my_strcat(my_strcat(var, "PWD="), getcwd(buf, size));
    oldpwd = my_strcat(my_strcat(oldpwd, "OLDPWD="), old);
    for (int i = 0; env[i] != NULL; i++) {
        env[i] = (my_strcmp(getname(env[i]), "PWD") == 0) ? var : env[i];
        env[i] = (my_strcmp(getname(env[i]), "OLDPWD") == 0) ? oldpwd : env[i];
    }

}

static int catch_error(char **parsed)
{
    if (opendir(parsed[1]) == 0 && errno == EACCES) {
        my_puterror(parsed[1]);
        my_puterror(": Permission denied.\n");
        return 0;
    } if (opendir(parsed[1]) == 0 && !access(parsed[1], F_OK)) {
        my_puterror(parsed[1]);
        my_puterror(": Not a directory.\n");
        return 0;
    } if (opendir(parsed[1]) == 0 && access(parsed[1], F_OK)) {
        my_puterror(parsed[1]);
        my_puterror(": No such file or directory.\n");
        return 0;
    }
    return 1;
}

static int special_case(char **parsed, char **env)
{
    if (parsed[1] == NULL ||
        my_strcmp(parsed[1], "--") == 0 || my_strcmp(parsed[1], "~") == 0) {
        chdir(getvalue(env, "HOME"));
        return 0;
    } if (my_strcmp(parsed[1], "-") == 0 ) {
        if (getvalue(env, "OLDPWD") != NULL)
            chdir(getvalue(env, "OLDPWD"));
        else
            my_puterror(": No such file or directory.\n");
        return 0;
    } if (my_strcmp(parsed[1], ".") == 0) {
        chdir(getvalue(env, "PWD"));
        return 0;
    }
    return 1;
}

void changedir(char **parsed, char **env)
{
    if (parsed[2] != NULL){
        if (parsed[1][0] == '-')
            my_puterror("Usage: cd [-plvn][-|<dir>].\n");
        else
            my_puterror("cd: Too many arguments.\n");
        return;
    } if (!special_case(parsed, env)) {
        update_env_path(env);
        return;
    } if (!catch_error(parsed))
        return;
    chdir(parsed[1]);
    update_env_path(env);
}