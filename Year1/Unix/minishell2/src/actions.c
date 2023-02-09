/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "shell.h"

char *read_input(void)
{
    size_t size = 1024;
    char *buf = malloc(sizeof(char) * size);
    if (getline(&buf, &size, stdin) == -1)
        return NULL;
    buf[my_strlen(buf) - 1] = '\0';
    return buf;
}

char **parse(char *input, char *separator)
{
    char *token = strtok(input, separator);
    char **argv = malloc(sizeof(char *) * my_strlen(input));
    int i = 0;

    while (token != NULL){
        argv[i] = malloc(sizeof(char) * (my_strlen(token) + 1));
        my_strncpy(argv[i], token, my_strlen(token));
        i++;
        token = strtok(NULL, separator);
    }
    argv[i] = NULL;
    return argv;
}

char *get_path(char **env, char **parsed, char **all_path)
{
    char *bin = malloc(my_strlen(getvalue(env, "PATH")) *
                        my_strlen(parsed[0]));
    int i = 1;

    bin[0] = '\0';
    bin = my_strcat(my_strcat(my_strcat(bin, all_path[0]), "/"), parsed[0]);
    for (; all_path[i] != NULL && access(bin, F_OK) == -1; i++) {
        bin[0] = '\0';
        bin = my_strcat(my_strcat(my_strcat(bin, all_path[i]), "/"),
        parsed[0]);
    }
    if (all_path[i] == NULL && access(bin, F_OK) == -1) {
        my_printf("%s: Command not found.\n", parsed[0]);
        return NULL;
    }
    return bin;
}

void basic(char **parsed, char **env)
{
    int pid;
    char **all_path = parse(getvalue(env, "PATH"), ":");
    char *bin;

    if (my_strarraylen(all_path) == 0) {
        my_printf("%s: Command not found.\n", parsed[0]);
        return;
    }
    bin = get_path(env, parsed, all_path);
    if (bin == NULL)
        return;
    pid = fork();
    if (pid == 0) {
        execve(bin, parsed, env);
        exit(0);
    }
}

void action(char **parsed, char **env)
{

    if (my_strcmp(parsed[0], "cd") == 0)
        changedir(parsed, env);
    if (my_strcmp(parsed[0], "env") == 0)
        print_arg(env);
    if (my_strcmp(parsed[0], "setenv") == 0)
        set_env(parsed, env);
    if (my_strcmp(parsed[0], "unsetenv") == 0)
        unset_env(parsed, env);
    if (my_strcmp(parsed[0], "exit") == 0)
        bad_exit(parsed);
    if (my_strcmp(parsed[0], "exit") != 0 &&
        my_strcmp(parsed[0], "unsetenv") != 0 &&
        my_strcmp(parsed[0], "setenv") != 0 &&
        my_strcmp(parsed[0], "env") != 0 &&
        my_strcmp(parsed[0], "cd") != 0)
        basic(parsed, env);
}