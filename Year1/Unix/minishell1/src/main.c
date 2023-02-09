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
    if (getline(&buf,&size,stdin) == -1)
        return NULL;
    buf[my_strlen(buf) - 1] = '\0';
    return buf;
}

char** parse(char *input, char *separator)
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

void basic(char **parsed, char **env)
{
    int pid;
    char **all_path = parse(getvalue(env, "PATH"), ":");
    char *bin = malloc(my_strlen(getvalue(env, "PATH")) *
                        my_strlen(parsed[0]));
    int i = 1;

    bin = my_strcat(my_strcat(my_strcat(bin,all_path[0]),"/"),parsed[0]);
    for (; all_path[i] != NULL && access(bin,F_OK) == -1; i++) {
        bin[0] = '\0';
        bin = my_strcat(my_strcat(my_strcat(bin,all_path[i]),"/"),parsed[0]);
    }
    if (all_path[i] == NULL && access(bin,F_OK) == -1){
        my_printf("%s: Command not found.\n",parsed[0]);
        return;
    }
    pid = fork();
    if (pid == 0) {
        execve(bin, parsed, env);
        exit(0);
    }
}

char *getname(char *string)
{
    char *varname = malloc(my_strlen(string) + 1);
    for(int i = 0; string[i] != '='; i++) {
        varname[i] = string[i];
        varname[i + 1] = '\0';
    }
    return varname;
}

char *create_var(char *name, char *value)
{
    char *varenv = malloc(sizeof(char) *(my_strlen(name) + my_strlen(value) + 2));
    varenv = my_strcat(varenv,name);
    varenv = my_strcat(varenv,"=");
    varenv = my_strcat(varenv,value);
    return varenv;
}

char *getvalue(char **env, char *var)
{
    int i = 0;

    for (; env[i] != NULL; i++) {
        if (my_strcmp(getname(env[i]),var) == 0){
            return my_strdup(env[i] + my_strlen(var) + 1);
        }
    }
    return NULL;
}

void action(char **parsed, char **env)
{
    if (my_strcmp(parsed[0], "cd") == 0)
        changedir(parsed, env);
    else if (my_strcmp(parsed[0], "env") == 0)
        print_arg(env);
    else if (my_strcmp(parsed[0], "setenv") == 0)
        set_env(parsed, env);
    else if (my_strcmp(parsed[0], "unsetenv") == 0)
        unset_env(parsed, env);
    else if (my_strcmp(parsed[0], "exit") == 0)
        bad_exit(parsed);
    else
        basic(parsed, env);
    return;
}

char *getprompt(char **env)
{
    char *user = getvalue(env,"USER");
    char *logname = getvalue(env,"LOGNAME");
    char *pwd = getvalue(env,"PWD");
    char *home = getvalue(env,"HOME");
    char *res = malloc(my_strlen(pwd) + my_strlen(user) + my_strlen(logname) + 100);

    res = my_strcat(my_strcat(my_strcat(my_strcat(my_strcat(res, "["), user),
    "\033[32m@\033[31m"), logname), "\033[32m:\033[0m\033[1m");
    if (my_strncmp(home, pwd, my_strlen(home)) == 0) {
        res = my_strcat(res, "~");
        res = my_strcat(res, pwd + my_strlen(home));
    } else
        res = my_strcat(res, pwd);
    res = my_strcat(res, "\033[0m] $ ");
    free(user);
    free(logname);
    free(pwd);
    free(home);
    return res;
}

int main (int ac, char **argv, char **env)
{
    (void)(ac);
    (void)(argv);

    char *foo;
    char **parsed;
    char *prompt;
    while (1) {
        if (isatty(STDIN_FILENO)) {
            prompt = getprompt(env);
            my_printf("%s",prompt);
        }
        foo = read_input();
        if (!foo)
            break;
        parsed = parse(foo, " \t");
        if (parsed[0] == NULL)
            continue;
        else if (my_strcmp(parsed[0], "exit") == 0 && (parsed[1] == NULL || (my_str_isnum(parsed[1]) && parsed[2] == NULL)))
            return my_exit(parsed);
        else
            action(parsed, env);
        wait(0);
    }
    return 0;
}
