/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void update_pic(char *file, game_t *game)
{
    char *command = format("fswebcam -r 1920x1080 saves/pictures/%s.jpeg 2>&1 > /dev/null", file);
    system(command);
    free_elements(game->saves[file[4] - '1']);
    game->saves[file[4] - '1'] = init_element(format("saves/pictures/%s.jpeg", file), (sfVector2f) {100, 225 + (250 * file[4] - '1')},
            (sfVector2f) {1200, 675}, (sfVector2f) {0.1, 0.1});
    return;
}
