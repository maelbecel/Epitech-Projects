/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

type_button_t *init_button_type(char *text, char *texture, sfVector2i size)
{
    type_button_t *type = malloc(sizeof(type_button_t));
    type->texture = sfTexture_createFromFile(texture, NULL);
    type->sprite = sfSprite_create();
    type->scale = (sfVector2f) {1, 1};
    type->rect = (sfIntRect){0, 0, size.x, size.y};
    type->text = sfText_create();
    type->font = sfFont_createFromFile(BASIC_FONT);
    type->text_size = BASIC_TEXT_SIZE;
    type->text_pos = (sfVector2f){(size.x - my_strlen(text) *
            (BASIC_TEXT_SIZE / 4 )), (size.y - BASIC_TEXT_SIZE +
            (BASIC_TEXT_SIZE) / 4)};
    type->sound = NULL;
    sfText_setString(type->text, text);
    sfSprite_setTexture(type->sprite, type->texture, sfTrue);
    return type;
}

button_t *init_button(char *text, char *texture,
                    sfVector2f pos, sfVector2i size)
{
    button_t *button = malloc(sizeof(button_t));
    button->base = init_button_type(text, texture, size);
    button->hoover = init_button_type(text, texture, size);
    button->clicked = init_button_type(text, texture, size);
    button->pos.x = pos.x;
    button->pos.y = pos.y;
    button->action_clicked = clicked;
    button->action_hoover = hoover;
    return button;
}

element_t *init_element(char *texture, sfVector2f pos,
                        sfVector2f size, sfVector2f scale)
{
    element_t *type = malloc(sizeof(element_t));
    type->texture = sfTexture_createFromFile(texture, NULL);
    type->sprite = sfSprite_create();
    type->scale = scale;
    type->rect = (sfIntRect){0, 0, size.x, size.y};
    type->pos = pos;
    sfSprite_setTexture(type->sprite, type->texture, sfFalse);
    sfSprite_setTextureRect(type->sprite, type->rect);
    sfSprite_setScale(type->sprite, type->scale);
    return type;
}

button_t *init_tiles(int i, int j, game_t *game)
{
    switch (game->map[i][j]) {
        case '1': return init_button("", "resource/Tiles/Grass1.png",
                    (sfVector2f){j * 120, i * 120}, (sfVector2i){120, 120});
        case '2': return init_button("", "resource/Tiles/Grass2.png",
                    (sfVector2f){j * 120, i * 120}, (sfVector2i){120, 120});
        case '3': return init_button("", "resource/Tiles/Grass3.png",
                    (sfVector2f){j * 120, i * 120}, (sfVector2i){120, 120});
        case '4': return init_button("", "resource/Tiles/Grass4.png",
                    (sfVector2f){j * 120, i * 120}, (sfVector2i){120, 120});
        case 'T': return init_button("", "resource/Tiles/Grass_Tower.png",
                    (sfVector2f){j * 120, i * 120}, (sfVector2i){120, 120});
        case 'A': return init_button("", "resource/Tiles/Path1.png",
                    (sfVector2f){j * 120, i * 120}, (sfVector2i){120, 120});
        case 'B': return init_button("", "resource/Tiles/Path2.png",
                    (sfVector2f){j * 120, i * 120}, (sfVector2i){120, 120});
    }
    return NULL;
}
