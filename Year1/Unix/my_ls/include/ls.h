/*
** EPITECH PROJECT, 2021
** ls.h
** File description:
** ls
*/

#ifndef ls
    #define ls

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>

    typedef struct ls {
        char *flags;
        char **files;
        char *enable;
        int * nbfiles;
    }ls_t;

    typedef struct file {
        int nlinks;
        long unsigned int blocks;
        int size;
        char * rights;
        char * user;
        char * group;
        char * date;
        time_t triable_date;
        char * name;
    }file_t;

    int get_blocks(file_t *File, int size, ls_t *options);
    char * get_user(uid_t st_uid);
    char * get_group(gid_t st_gid);
    char * get_date(time_t *time);
    char * get_rights(mode_t mode);
    void tri_desalpha(file_t **files, ls_t *options);
    void tri_alpha(file_t **files, ls_t *options);
    void tri_desdates(file_t **files, ls_t *options);
    void tri_dates(file_t **files, ls_t *options);
    void print_res(file_t **files, ls_t *options);
    file_t *get_file_line(int f, ls_t *options);
    file_t **get_files(ls_t *options);
    file_t get_line(struct dirent *dirp, char *directory);
    int get_flags(ls_t *options, char **argv, int n, int i);
    void get_error(int error, char *file);
    void display_line(file_t file, ls_t *options);
    void display_name(file_t file, ls_t *option);
    void enable(ls_t *options);

#endif
