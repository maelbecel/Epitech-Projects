/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

void printusage(void)
{
    my_putstr("USAGE :\n\nClick on Boo's and Koppa's before they across the screen to increase the score.\n");
}

int get_menu_click(sfMouseButtonEvent event)
{
    sfMusic* clic = sfMusic_createFromFile("sounds/clic.ogg");
    sfMusic_play(clic);

    if (event.x >= 525 && event.x <= 1005) {
        if (event.y >= 515 && event.y <= 605) {
            return 2;
        }
        else if (event.y >= 645 && event.y <= 735) {
            return 1;
        }
    }
    return 0;
}

int analyse_menu_events(sfRenderWindow *window, sfEvent event)
{
    int r = 0;
    switch (event.type){
        case sfEvtClosed :{
            exit(0);
            break;
        }
        case sfEvtMouseButtonPressed : {
            sfVector2i vector = sfMouse_getPositionRenderWindow(window);
            sfMouseButtonEvent event;
            event.x = vector.x;
            event.y = vector.y;
            r = get_menu_click(event);
            break;
        }
    }
    return r;
}

int menu(sfRenderWindow *window)
{
    sfEvent event;
    sfTexture *texture = sfTexture_createFromFile("pictures/main_menu.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfMusic* music = sfMusic_createFromFile("sounds/main_menu_music.ogg");
    int r = 0;

    sfMusic_setVolume(music, getsoundlevel());
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)){
            sfSprite_setTexture(sprite, texture, sfTrue);
            r = analyse_menu_events(window, event);
        }
        if (r != 0){
            sfMusic_destroy(music);
            return r;
        }
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}

int main(int ac, char **argv)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1500, 1000, 32};
    sfCursor *cursor = sfCursor_createFromSystem(sfCursorCross);
    int menu_choice;

    if (ac >= 2){
        if (argv[1][0] == '-' && argv[1][1] == 'h'){
            printusage();
            return 0;
        }
        return 84;
    }
    window = sfRenderWindow_create(mode, "Super Mario Hunter", sfClose, NULL);
    sfRenderWindow_setMouseCursor(window, cursor);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (1) {
        menu_choice = menu(window);
        sfRenderWindow_clear(window, sfBlack);
        if (menu_choice == 1)
            settings(window);
        else
            play(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}