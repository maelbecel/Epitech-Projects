/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include "printf.h"
#include "my.h"
#include "ls.h"
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

char searchflag(char *str, char chr)
{
    for (int i = 0 ; i < my_strlen(str) ; i++) {
        if (str[i] == chr)
            return '1';
    }
    return '0';
}

void getls(int argc, char **argv, ls_t *options)
{
    int j = 0;
    int fl = 0;
    options->flags = malloc(sizeof(char) * 10);
    options->enable = malloc(sizeof(char) * 8);
    options->files = malloc(sizeof(char *) * 99);
    options->files[0] = ".";
    options->files[1] = NULL;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            j = get_flags(options, argv, j, i);
        }else {
            options->files[fl] = argv[i];
            options->files[fl + 1] = NULL;
            fl++;
        }
    }if (my_strlen(options->flags) == 0){
        options->flags[0] = '*';
        options->flags[1] = '\0';
    }
    enable(options);
}

int check_args(ls_t *options)
{
    DIR *dp;
    int error = 0;
    errno = 0;
    for (int i = 0; i < my_strarraylen(options->files); i++) {
        if (opendir(options->files[i]) == NULL) {
            get_error(errno,options->files[i]);
            error = 1;
        }
    }
    return error;
}

int main(int argc, char *argv[])
{
    ls_t *options = malloc(sizeof(ls_t));
    int error;

    getls(argc, argv, options);
    if ((error = check_args(options)) != 0) {
        return 84;
    }
    file_t **files = get_files(options);
    if (options->enable[4] == '1')
        tri_desalpha(files, options);
    else
        tri_alpha(files, options);
    if (options->enable[5] == '1')
        if (options->enable[4] == '1')
            tri_desdates(files, options);
        else
            tri_dates(files, options);
    print_res(files, options);
    return 0;
}
