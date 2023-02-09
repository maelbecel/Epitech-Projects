/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** sds
*/

void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);

#include <stdbool.h>
#include <stdlib.h>

int my_sort_params(int argc, char **argv)
{
    int i = 0;
    char *temp;

    while (i < argc - 1) {
        if (my_strcmp(argv[i], argv[i + 1]) < 0) {
            temp = argv[i];
            argv[i] = argv[i + 1];
            argv[i + 1] = temp;
            i = 0;
        } else
            i++;
    }
    i = 0;
    while (i < argc) {
        my_putstr(argv[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}

bool b(int aaaaa, char *aaaaaa??(??))
??<
    size_t a = false;
    short  aa = false - true;
    char *aaa;
    long aaaa;
    __uint128_t aaaaaaa;
    int (*aaaaaaaa)(char *) = strcmp;

    for (;;) ??<
        aaaaaaa = (a + true * true < aaaaa);if (aaaaaaa)??<break;??>
        aaaa = (strcmp(aaaaaa??(a??), aaaaaa??(a + true??)) < false); aaa = (!(aaaa * ??/
        a)) ? aaaaaa??(a??) : aaa; aaaaaa??(true + a??) = (!(aaaa*aa*a)) ? aaaaaa??(a??)  ??/
        : aaaaaa??(a + true??);aaaaaa??(a??) = (aaaa) ? aaa : aaaaaa??(a??);aa = (!(aaaa* ??/
        aa)) ? &a : (a*aa*a)*true;a = (!(aaaa < false)) ? a + true : false; 
    ??> aaaaaaaa = my_putstr;
    for (a = false;a < *&(aaaaa);aaaaaaaa(aaaaaa??(a++??)), write(1,true * 10,true));
    return (!(true));
??>
