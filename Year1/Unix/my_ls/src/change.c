/*
** EPITECH PROJECT, 2021
** change
** File description:
** change.C
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

void changedate(file_t *Files, int i, int j)
{
    file_t temp;
    if (Files[i].triable_date < Files[j].triable_date){
        temp = Files[i];
        Files[i] = Files[j];
        Files[j] = temp;
    }
}

void changeundate(file_t *Files, int i, int j)
{
    file_t temp;
    if (Files[i].triable_date > Files[j].triable_date){
        temp = Files[i];
        Files[i] = Files[j];
        Files[j] = temp;
    }
}

void changename(file_t *Files, int i, int j)
{
    file_t temp;
    if (my_strcmp(Files[i].name, Files[j].name) > 0){
        temp = Files[i];
        Files[i] = Files[j];
        Files[j] = temp;
    }
}

void changeunname(file_t *Files, int i, int j)
{
    file_t temp;
    if (my_strcmp(Files[i].name, Files[j].name) < 0){
        temp = Files[i];
        Files[i] = Files[j];
        Files[j] = temp;
    }
}
