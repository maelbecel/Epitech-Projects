/*
** EPITECH PROJECT, 2021
** error.c
** File description:
** error.c
*/

int emptymap(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '.')
            return 0;
    }
    return 84;
}

int unsizedmap(char *buffer)
{
    if (buffer[0] < '0' || buffer[0] > '9')
        return 84;
    return 0;
}

int error(char *buffer)
{
    if (buffer[0] == '0')
        return 84;
    if (emptymap(buffer) == 84)
        return 84;
    if (unsizedmap(buffer) == 84)
        return 84;
}
