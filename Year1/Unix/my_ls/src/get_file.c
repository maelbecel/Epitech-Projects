/*
** EPITECH PROJECT, 2021
** get file
** File description:
** get file
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

file_t get_line(struct dirent *dirp, char *directory)
{
    file_t file;
    struct stat stats;
    char *filename = concat(directory, "/", dirp->d_name);
    lstat(filename, &stats);
    file.rights = get_rights(stats.st_mode);
    file.nlinks = stats.st_nlink;
    file.blocks = stats.st_blocks;
    file.user = get_user(stats.st_uid);
    file.group = get_group(stats.st_gid);
    file.size = stats.st_size;
    file.date = get_date(&stats.st_mtime);
    file.triable_date = stats.st_mtime;
    file.name = dirp->d_name;
    return file;
}

file_t *get_file_line(int f, ls_t *options)
{
    DIR *dp;
    struct dirent *dirp;
    file_t *fileline = malloc(sizeof(file_t) * 100);
    int i = 0;

    dp = opendir(options->files[f]);
    options->nbfiles[f] = malloc(sizeof(int) * 100);
    for (; (dirp = readdir(dp)) != 0; i++) {
        fileline[i] = get_line(dirp,options->files[f]);
    }
    options->nbfiles[f] = i;
    return fileline;
}

file_t **get_files(ls_t *options)
{
    file_t **files = malloc(sizeof(file_t *) * my_strarraylen(options->files));
    int i = 0;
    options->nbfiles = malloc(sizeof(int *) * 99);
    for (; i < my_strarraylen(options->files); i++) {
        files[i] = get_file_line(i, options);
    }
    return files;
}

int get_blocks(file_t *File, int size, ls_t *options)
{
    int res = 0;
    for (int i = 0;  i < size; i++){
        if (!(options->enable[6] == '0' && File[i].name[0] == '.'))
            res += File[i].blocks;
    }
    return res / 2;
}

int get_flags(ls_t *options, char **argv, int n, int i)
{
    int j = n;
    for (int x = 1; x < my_strlen(argv[i]); x++) {
        options->flags[j] = argv[i][x];
        options->flags[j + 1] = '\0';
        j++;
    }
    return j;
}
