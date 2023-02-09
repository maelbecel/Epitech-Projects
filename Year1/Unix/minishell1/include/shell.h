/*
** EPITECH PROJECT, 2022
** shell.c
** File description:
** shell
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stddef.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>


#ifndef SHELL
    #define SHELL

    void basic(char **parsed, char **env);
    void set_env(char **parsed, char **env);
    void unset_env(char **parsed, char **env);
    void changedir(char **parsed, char **env);
    void print_arg ( char ** arg );
    void action(char **parsed, char **env);
    void bad_exit (char **arg);
    int my_exit (char **arg);
    char *getvalue(char **env, char *var);
    char *create_var(char *name, char *value);
    char *getname(char *string);
    char *read_input(void);
    char **parse(char *input, char *separator);

#endif
