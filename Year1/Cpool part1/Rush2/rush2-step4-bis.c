/*
** EPITECH PROJECT, 2021
** rush2-1.c
** File description:
** task04 du rush2.c
*/

#include "include/abc.h"
void my_putchar(char c);
void my_put_nbr(int n);
void my_putstr(char *text);
int letter_in_array (char *text);

float distance (float a, float b)
{
    if (a < b)
        return b - a;
    return a - b;
}

char * find_language (float *num, int n)
{
    int dist;
    int i;

    while (num[i] != '\0'){
        if (distance(num[i], n) < dist){
            dist = distance(num[i], n);
        }
        i++;
    }
    if (distance(num[0], n) == dist)
        return "English";
    if (distance(num[1], n) == dist)
        return "French";
    if (distance(num[2], n) == dist)
        return "German";
    if (distance(num[3], n) == dist)
        return "Spanish";
}

char *tri(int english, int french, int german, int spanish)
{
    int temp = english;

    if (french > temp)
        temp = french;
    if (german > temp)
        temp = german;
    if (spanish > temp)
        temp = spanish;
    if (temp == spanish)
        return " Spanish";
    if (temp == german)
        return " German";
    if (temp == french)
        return " French";
    if (temp == english)
        return " English";
}

int change_letter(char letter)
{
    int let;

    if (letter >= 'A' && letter <= 'Z')
        let = letter - 65;
    else if  (letter >= 'a' && letter <= 'z')
        let = letter - 97;
    return let;
}

void *get_lang(char *text)
{
    int english = 0;
    int french = 0;
    int german = 0;
    int spanish = 0;
    char letter;
    int let;
    char *fleche = "=>";
    for (int i = 0; i < letter_in_array(text); i++){
        letter = text[i];
        if ((letter >= 'A' && letter <= 'Z') ||
            (letter >= 'a' && letter <= 'z')){
            let = change_letter(letter);
            english += alphabet[let][0];
            french += alphabet[let][1];
            german += alphabet[let][2];
            spanish += alphabet[let][3];
        }
    }
    my_putstr(fleche);
    my_putstr(tri(english, french, german, spanish));
}
