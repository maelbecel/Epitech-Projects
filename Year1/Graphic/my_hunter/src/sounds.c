/*
** EPITECH PROJECT, 2021
** sounds.c
** File description:
** sounds
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stddef.h>

int get_sounds_click(sfMouseButtonEvent event)
{
    sfMusic* clic = sfMusic_createFromFile("sounds/clic.ogg");
    sfMusic_play(clic);

    if (event.y >= 435 && event.y <= 570) {
        if (event.x >= 365 && event.x <= 630) {
            setsoundlevel(getsoundlevel() + 5);
            return 2;
        }
        else if (event.x >= 755 && event.x <= 1025) {
            setsoundlevel(getsoundlevel() - 5);
            return 1;
        }
    }
    else if (event.y >= 625 && event.y <= 760
            && event.x >= 555 && event.x <= 825) {
        return 3;
    }

    return 0;
}

int analyse_sounds_events(sfRenderWindow *window, sfEvent event)
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
            r = get_sounds_click(event);
            break;
        }
    }
    return r;
}

void sounds(sfRenderWindow *window)
{
    sfEvent event;
    sfTexture *texture = sfTexture_createFromFile("pictures/sound_menu.png", NULL);
    sfSprite *sprite = sfSprite_create();
    int r = 0;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)){
            sfSprite_setTexture(sprite, texture, sfTrue);
            r = analyse_sounds_events(window, event);
            if (r == 3)
                return 0;
        }
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}