/*
** EPITECH PROJECT, 2021
** tri_date.c
** File description:
** tri
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

void tri_datebetique(file_t *Files, ls_t *options, int size)
{
    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            changedate(Files,i,j);
        }
    }
}

void tri_desdatebetique(file_t *Files, ls_t *options, int size)
{
    file_t temp;
    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            changeundate(Files,i,j);
        }
    }
}

void tri_dates(file_t **Files, ls_t *options)
{
    int lenth = my_strarraylen(options->files);
    for (int x = 0; x < lenth ; x++)
        tri_datebetique(Files[x], options, options->nbfiles[x]);
}

void tri_desdates(file_t **Files, ls_t *options)
{
    int lenth = my_strarraylen(options->files);
    for (int x = 0; x < lenth ; x++)
        tri_desdatebetique(Files[x], options, options->nbfiles[x]);
}
