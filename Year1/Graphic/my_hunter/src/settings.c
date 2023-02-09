/*
** EPITECH PROJECT, 2021
** settings.c
** File description:
** settings
*/
#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stddef.h>

int get_settings_click(sfMouseButtonEvent event)
{
    sfMusic* clic = sfMusic_createFromFile("sounds/clic.ogg");
    sfMusic_play(clic);

    if (event.x >= 470 && event.x <= 1050) {
        if (event.y >= 265 && event.y <= 390) {
            return 2;
        }
        else if (event.y >= 425 && event.y <= 550) {
            return 1;
        }
        else if (event.y >= 585 && event.y <= 710) {
            return 3;
        }
    }
    return 0;
}

int analyse_settings_events(sfRenderWindow *window, sfEvent event)
{
    int r = 0;
    switch (event.type){
        case sfEvtClosed :{
            sfRenderWindow_destroy(window);
            exit(0);
            break;
        }
        case sfEvtMouseButtonPressed : {
            sfVector2i vector = sfMouse_getPositionRenderWindow(window);
            sfMouseButtonEvent event;
            event.x = vector.x;
            event.y = vector.y;
            r = get_settings_click(event);
            break;
        }
    }
    return r;
}

int settings(sfRenderWindow *window)
{
    sfEvent event;
    sfTexture *texture = sfTexture_createFromFile("pictures/settings_menu.png", NULL);
    sfSprite *sprite = sfSprite_create();
    int r = 0;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)){
            sfSprite_setTexture(sprite, texture, sfTrue);
            r = analyse_settings_events(window, event);
            if (r != 0){
                if (r == 1)
                    controls(window);
                else if (r == 2)
                    sounds(window);
                else
                    return 0;
            }
        }
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}