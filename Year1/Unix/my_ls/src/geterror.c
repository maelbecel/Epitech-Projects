/*
** EPITECH PROJECT, 2021
** get error
** File description:
** get_error.C
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

void get_error(int error, char *file)
{
    switch (error){
        case ENOENT : {
            my_printf("ls: cannot access '%s'",file);
            my_printf(": No such file or directory\n");
            break;
        }case EACCES : {
            my_printf("ls: cannot open directory ");
            my_printf("'%s': Permission denied\n",file);
            break;
        }
    }
}

void display_line(file_t file, ls_t *options)
{
    if (!(options->enable[6] == '0' && file.name[0] == '.')){
        my_printf("%s  ", file.rights);
        my_printf("%d  ", file.nlinks);
        my_printf("%s  ", file.user);
        my_printf("%s  ", file.group);
        my_printf("%d  ", file.size);
        my_printf("%s  ", file.date);
        my_printf("%s\n", file.name);
    }
}

void display_name(file_t file, ls_t *options)
{
    if (!(options->enable[6] == '0' && file.name[0] == '.')){
        my_printf("%s  ", file.name);
    }
}
