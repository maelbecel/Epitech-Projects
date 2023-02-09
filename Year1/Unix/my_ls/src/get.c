/*
** EPITECH PROJECT, 2021
** get
** File description:
** get.c
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

char *get_month(char *month)
{
    switch (month[0] + month[1] + month[2]) {
        case 281: return "01";
        case 269: return "02";
        case 288: return "03";
        case 291: return "04";
        case 295: return "05";
        case 301: return "06";
        case 299: return "07";
        case 285: return "08";
        case 296: return "09";
        case 294: return "10";
        case 307: return "11";
        case 268: return "12";
    }
    return "84";
}

char *get_date(time_t *time)
{
    char *dte = my_strdup(ctime(time) + 4);
    dte[12] = '\0';
    return dte;
}

char *get_user(uid_t uid)
{
    struct passwd *pws;
    pws = getpwuid(uid);
    return pws->pw_name;
}

char *get_group(uid_t gid)
{
    struct group *grp;
    grp = getgrgid(gid);
    return grp->gr_name;
}

char * get_rights(mode_t mode)
{
    char *res = malloc(sizeof(char) * 12);
    res[0] = (S_ISDIR(mode)) ? 'd' : '-';
    res[1] = (mode & S_IRUSR) ? 'r' : '-';
    res[2] = (mode & S_IWUSR) ? 'w' : '-';
    res[3] = (mode & S_IXOTH) ? 'x' : '-';
    res[4] = (mode & S_IRGRP) ? 'r' : '-';
    res[5] = (mode & S_IWGRP) ? 'w' : '-';
    res[6] = (mode & S_IXUSR) ? 'x' : '-';
    res[7] = (mode & S_IROTH) ? 'r' : '-';
    res[8] = (mode & S_IWOTH) ? 'w' : '-';
    res[9] = (mode & S_IXGRP) ? 'x' : '-';
    res[10] = '\0';
    return res;
}
