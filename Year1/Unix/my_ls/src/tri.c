/*
** EPITECH PROJECT, 2021
** tri
** File description:
** tri.c
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

void tri_desalphabetique(file_t *Files, ls_t *options, int size)
{
    file_t temp;
    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            changeunname(Files, i, j);
        }
    }
}

void tri_alphabetique(file_t *Files, ls_t *options, int size)
{
    file_t temp;
    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            changename(Files, i, j);
        }
    }
}

void tri_alpha(file_t **Files, ls_t *options)
{
    int lenth = my_strarraylen(options->files);
    for (int x = 0; x < lenth ; x++)
        tri_alphabetique(Files[x], options, options->nbfiles[x]);
}

void tri_desalpha(file_t **Files, ls_t *options)
{
    int lenth = my_strarraylen(options->files);
    for (int x = 0; x < lenth ; x++)
        tri_desalphabetique(Files[x], options, options->nbfiles[x]);
}

void enable(ls_t *options)
{
    options->enable[0] = searchflag(options->flags, '*');
    options->enable[1] = searchflag(options->flags, 'l');
    options->enable[2] = searchflag(options->flags, 'R');
    options->enable[3] = searchflag(options->flags, 'd');
    options->enable[4] = searchflag(options->flags, 'r');
    options->enable[5] = searchflag(options->flags, 't');
    options->enable[6] = searchflag(options->flags, 'a');
    options->enable[7] = '\0';
}
