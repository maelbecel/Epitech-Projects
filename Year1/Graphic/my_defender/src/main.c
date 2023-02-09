/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

static int defender(sfRenderWindow *window, sfEvent *event, game_t *game)
{
    scene_t *scenes = init_scenes(game);
    event->type = sfEvtMouseButtonReleased;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfWhite);
        display(window, scenes, event, game);
        sfRenderWindow_display(window);
        game->time = sfClock_getElapsedTime(game->clock);
        if ((float)game->time.microseconds / MICRO >= TIME_BTWN_ENEMY &&
            scenes->page == 1) {
            sfClock_restart(game->clock);
            game->monster = add_monster(game->monster, game);
            towers_attack(game);
        }
        while (sfRenderWindow_pollEvent(window, event))
            if (analyse_event(window, event, game, scenes) == 0)
                return 0;
        if (game->life <= 0)
            scenes->page = 4;
    }
    return 0;
}

static void init_game(char *path, game_t *game, sfRenderWindow *window)
{
    game->window = window;
    game->map = readfile(path);
    game->menu_tower = init_menu();
    game->sound_hoover = sfMusic_createFromFile(HOOVER_SOUND);
    game->sound_clicked = sfMusic_createFromFile(CLICK_SOUND);
    game->sound_buy = sfMusic_createFromFile(BUY_SOUND);
    game->main_music = sfMusic_createFromFile(MUSIC);
    game->head = malloc(sizeof(tower_t));
    game->head->id = 0;
    game->clock = sfClock_create();
    game->time = sfClock_getElapsedTime(game->clock);
    game->monster = malloc(sizeof(monster_t *));
    game->monster[0] = NULL;
    game->die = sfMusic_createFromFile(DIE_SOUND);
    game->type = NO_TOWER;
    game->speed = 3;
}

int main(int ac, char **argv)
{
    if (ac != 2)
        return (84);
    game_t *game = malloc(sizeof(game_t));
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    sfEvent event;
    window = sfRenderWindow_create(mode, "My Defender", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    init_game(argv[1], game, window);
    if (game->map == NULL)
        return 84;
    sfMusic_play(game->main_music);
    if (defender(game->window, &event, game) == 0)
        sfRenderWindow_destroy(window);
    sfMusic_stop(game->sound_hoover);
    sfMusic_stop(game->sound_clicked);
    sfMusic_stop(game->sound_buy);
    sfMusic_stop(game->main_music);
    sfMusic_destroy(game->sound_hoover);
    sfMusic_destroy(game->sound_clicked);
    sfMusic_destroy(game->sound_buy);
    sfMusic_destroy(game->main_music);
}