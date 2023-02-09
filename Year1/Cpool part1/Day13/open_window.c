/*
** EPITECH PROJECT, 2021
** open_window
** File description:
** xxx
*/

#include <SFML/Graphics.h>

int main(void)
{
    sfVideoMode mode = {600, 600, 32};
    sfEvent event;
    sfTexture* texture = sfTexture_createFromFile("image.jpg", NULL);
    sfSprite *sprite = sfSprite_create();
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "Window", sfDefaultStyle, NULL);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            sfSprite_setTexture(sprite, texture, sfTrue);
            if (event.type == sfEvtClosed || !(texture))
                sfRenderWindow_close(window);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);

    return (0);
}
