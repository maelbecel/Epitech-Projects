/*
** EPITECH PROJECT, 2021
** control
** File description:
** control
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

int get_control_click(sfMouseButtonEvent event)
{
    sfMusic* clic = sfMusic_createFromFile("sounds/clic.ogg");
    sfMusic_play(clic);

    if (event.x >= 650 && event.x <= 920) {
        if (event.y >= 690 && event.y <= 820) {
            return 1;
        }
    }
    return 0;
}

int analyse_control_events(sfRenderWindow *window, sfEvent event)
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
            r = get_control_click(event);
            break;
        }
    }
    return r;
}

void controls(sfRenderWindow *window)
{
    sfEvent event;
    sfTexture *texture = sfTexture_createFromFile("pictures/control.png", NULL);
    sfSprite *sprite = sfSprite_create();
    int r = 0;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)){
            sfSprite_setTexture(sprite, texture, sfTrue);
            r = analyse_control_events(window, event);
            if (r == 1)
                return 0;
        }
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}