/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/


#ifndef STRING_H
    #define STRING_H

    #include <stddef.h>
    #include <string.h>

    typedef struct string_s string_t;

    struct string_s {
        char *str;
        void (*assign_s)(string_t *this , const string_t *str);
        void (*assign_c)(string_t *this, const char *s);
        void (*append_c)(string_t *this, const char *ap);
        void (*append_s)(string_t *this, const string_t *ap);
        char (*at)(const string_t *this, size_t pos);
        void (*clear)(string_t *this);
        int (*length)(const string_t *this);
        int (*compare_s)(const string_t *this, const string_t *str);
        int (*compare_c)(const string_t *this, const char *str);
        size_t (*copy)(const string_t *this, char *s, size_t n, size_t pos);
        const char *(*c_str)(const string_t *this);
        int (*empty)(const string_t *this);
        int (*find_s)(const string_t *this, const string_t *str, size_t pos);
        int (*find_c)(const string_t *this, const char *str, size_t pos);
        void (*insert_c)(string_t *this, size_t pos, const char *str);
        void (*insert_s)(string_t *this, size_t pos, const string_t *str);
        int (*to_int)(const string_t *this);
        string_t **(*split_s)(const string_t *this, char separator);
        char **(*split_c)(const string_t *this, char separator);
        void (*print)(const string_t *this);
        void (*join_c)(string_t *this, char delim, const char * const *array);
        void (*join_s)(string_t *this, char delim,
                        const string_t * const *array);
        string_t *(*substr)(const string_t *this, int offset, int length);
    };

    void string_init (string_t *this, const char *s);
    void string_destroy (string_t *this);
    void assign_s(string_t *this , const string_t *str);
    void assign_c(string_t *this, const char *s);
    void append_c(string_t *this, const char *ap);
    void append_s(string_t *this, const string_t *ap);
    char inside(const string_t *this, size_t pos);
    void clear(string_t *this);
    int length(const string_t *this);
    int compare_s(const string_t *this, const string_t *str);
    int compare_c(const string_t *this, const char *str);
    size_t copy(const string_t *this, char *s, size_t n, size_t pos);
    const char *c_str(const string_t *this);
    int empty(const string_t *this);
    int find_s(const string_t *this, const string_t *str, size_t pos);
    int find_c(const string_t *this, const char *str, size_t pos);
    void insert_c(string_t *this, size_t pos, const char *str);
    void insert_s(string_t *this, size_t pos, const string_t *str);
    int to_int(const string_t *this);
    string_t **split_s(const string_t *this, char separator);
    char **split_c(const string_t *this, char separator);
    void print(const string_t *this);
    void join_c(string_t *this, char delim, const char * const *array);
    void join_s(string_t *this, char delim, const string_t * const *array);
    string_t *substr(const string_t *this, int offset, int length);

#endif /* !STRING_H */
