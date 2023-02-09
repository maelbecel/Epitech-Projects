/*
** EPITECH PROJECT, 2021
** cat
** File description:
** 
*/

#include <fcntl.h>
#include <errno.h>

void my_putchar(char c);
int my_putstr(char *c);

int my_putstr2(char const *str, int size)
{
    int i = 0;
    while (i <= size) {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

int error(char *name, int error)
{
    my_putstr("cat: ");
    my_putstr(name);
    if (error == 2)
        my_putstr(": No such file or directory\n");
    if (error == 21)
        my_putstr(": Is a directory\n");
    return (84);
}

int printfiles(int ac, char **argv)
{
    int fd;
    char buff[30000];
    int len;

    for (int i = 1; i < ac; i++) {
        fd = open(argv[i], O_RDONLY);
        if (errno != 0)
            return (error(argv[i], errno));
        len = read(fd, buff, 30000);
        buff[len+1] = '\0';
        if (errno != 0)
            return (error(argv[i], errno));
        my_putstr2(buff, len);
    }
    close(fd);
    return (0);
}

int main(int ac, char **argv)
{
    int fd;
    char buff[30000];
    
    if (ac == 1) {    
        while ((fd = read(0, buff, 30000)) > 0)
            my_putstr(buff);
    } else if (ac == 0) {
        return (error("None", 2));
    }
    else
        return (printfiles(ac, argv));
    return (0);
}
