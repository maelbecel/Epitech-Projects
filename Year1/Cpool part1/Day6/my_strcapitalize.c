/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** xxx
*/

char *my_strcapitalize(char *str)
{
    int i = 1;

    if (str[0] >= 'a' && str[0] <= 'z'){
        str[0] -= 32;
    }

    while (str[i] != '\0') {
        if ((str[i-1] == ' ' || str[i-1] == '-' || str[i-1] == '+' ) &&
        (str[i] >= 'a' && str[i] <= 'z')){
            str[i] -= 32;
        } else if (((str[i-1] >= 'A' && str[i-1] <= 'Z') ||
            ( str[i-1] >= '0' && str[i -1] <= '9') ||
            (str[i-1] >= 'a' && str[i-1] <= 'z')) &&
            ((str[i] >= 'A' && str[i] <= 'Z'))){
            str[i] += 32;
        }
        i++;
    }
    return str;
}
