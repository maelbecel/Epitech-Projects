/*
** EPITECH PROJECT, 2021
** print
** File description:
** print.c
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

void print_d(ls_t *options)
{
    int lenth = my_strarraylen(options->files);

    for (int i = 0; i < lenth ; i++){
        my_printf("%s ",options->files[i]);
    }
    my_printf("\n");
}

void print_dl(file_t **Files, ls_t *options)
{
    int lenth = my_strarraylen(options->files);
    struct stat stats;
    DIR *dp;

    for (int i = 0; i < lenth ; i++){
        lstat(options->files[i], &stats);
        my_printf("%s  ",get_rights(stats.st_mode));
        my_printf("%d  ", stats.st_nlink);
        my_printf("%s  ", get_user(stats.st_uid));
        my_printf("%s  ", get_group(stats.st_gid));
        my_printf("%d  ", stats.st_size);
        my_printf("%s  ", get_date(&stats.st_mtime));
        my_printf("%s\n",options->files[i]);
    }
}

void print_l(file_t **Files, ls_t *options)
{
    int lenth = my_strarraylen(options->files);
    for (int i = 0; i < lenth ; i++){
        if (lenth > 1)
            my_printf("%s :\n", options->files[i]);
        my_printf("total  %d\n",
            get_blocks(Files[i],options->nbfiles[i], options));
        for (int j = 0; j < options->nbfiles[i]; j++){
            display_line(Files[i][j], options);
        }
        if (i < lenth -1)
            my_printf("\n");
    }
}

void print_none(file_t **Files, ls_t *options)
{
    int lenth = my_strarraylen(options->files);
    for (int i = 0; i < lenth ; i++){
        if (lenth > 1)
            my_printf("%s :\n", options->files[i]);
        for (int j = 0; j < options->nbfiles[i]; j++)
            display_name(Files[i][j], options);
        if (i < lenth -1)
            my_printf("\n\n");
        else
            my_printf("\n");
    }
}

void print_res(file_t **Files, ls_t *options)
{
    if (options->enable[3] == '1'){
        if (options->enable[1] == '1')
            print_dl(Files, options);
        else
            print_d(options);
    }else if (options->enable[1] == '1')
        print_l(Files, options);
    else
        print_none(Files, options);
}
