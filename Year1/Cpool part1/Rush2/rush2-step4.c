/*
** EPITECH PROJECT, 2021
** rush2.c
** File description:
** rush2
*/

void my_putchar(char c);
void my_put_nbr(int n);
void my_putstr(char *text);
float distance(float a, float b);
char * find_language (float *num, int n);
char *tri(int english, int french, int german, int spanish);
int change_letter(char letter);
void *get_lang(char *text);

void my_put_float (int nb)
{
    my_put_nbr(nb / 100);
    my_putchar('.');
    my_put_nbr((nb / 10) % 10);
    my_put_nbr(nb % 10);
}

int letter_in_array (char *text)
{
    int let = 0;
    for (int i = 0; text[i] != '\0'; i++){
        if ((text[i] >= 'A' && text[i] <= 'Z') ||
            (text[i] >= 'a' && text[i] <= 'z')){
            let++;
        }
    }
    return let;
}

int occ_text(char *text, char letter)
{
    int occ = 0;
    int i = 0;
    char letter2;

    if (letter >= 'A' && letter <= 'Z')
        letter2 = letter + 32;
    else if  (letter >= 'a' && letter <= 'z')
        letter2 = letter - 32;

    while (text[i] != '\0') {
        if (text[i] == letter  || text[i] == letter2){
            occ++;
        }
        i++;
    }
    return occ;
}

void print_res (char **argv, int i, int occ)
{
    int len;

    len = letter_in_array(argv[1]);
    my_putchar(argv[i][0]);
    my_putchar(':');
    my_put_nbr(occ);
    my_putchar(' ');
    my_putchar('(');
    my_put_float(10000 * occ / len);
    my_putchar('%');
    my_putchar(')');
    my_putchar('\n');

}

int main (int argc, char ** argv)
{
    int occ;
    float percent;
    int entier;
    float decimal;
    char *error = "=>Can't be able to find language, text to short";

    for (int i = 2; i <= argc - 1; i++){
        occ = occ_text(argv[1], argv[i][0]);
        print_res(argv, i, occ);
    }
    if (letter_in_array(argv[1]) > 10)
        get_lang(argv[1]);
    else
        my_putstr(error);
    my_putchar('\n');
    return 0;
}
