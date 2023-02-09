/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "shell.h"

char *create_var(char *name, char *value)
{
    char *varenv = malloc(sizeof(char) *
                        (my_strlen(name) + my_strlen(value) + 2));
    varenv = my_strcat(varenv, name);
    varenv = my_strcat(varenv, "=");
    varenv = my_strcat(varenv, value);
    return varenv;
}

char *getprompt(char **env)
{
    char *user = getvalue(env, "USER");
    char *logname = getvalue(env, "LOGNAME");
    char *pwd = getvalue(env, "PWD");
    char *home = getvalue(env, "HOME");
    char *res = malloc(my_strlen(pwd) + my_strlen(user) +
                        my_strlen(logname) + 100);

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

void my_sleep(int nb)
{
    for (int i = 0; i < nb * 1000000; i++);
}

void catch_re(char *foo, char **env)
{
    char **parsed = my_str_to_word_array(foo, ';');

    for (int i = 0; parsed[i]; i++) {
        action(parse(my_strdup(parsed[i]), " \t"), env);
        my_sleep(2);
    }
    my_sleep(2);
}

int main (UNUSED int ac, UNUSED char **argv, char **env)
{
    char *foo;
    char **parsed;

    while (1) {
        show_prompt(env);
        if (!(foo = read_input()))
            break;
        parsed = parse(my_strdup(foo), " \t");
        if (parsed[0] == NULL)
            continue;
        else if (my_strcmp(parsed[0], "exit") == 0 && (parsed[1] == NULL ||
                (my_str_isnum(parsed[1]) && parsed[2] == NULL)))
            return my_exit(parsed);
        if (getvalue(env, "PATH") == NULL)
            my_printf("%s: Command not found.\n", parsed[0]);
        else
            catch_re(foo, env);
        wait(0);
    }
    return 0;
}
