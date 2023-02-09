/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "runner.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

void destroy_objects (game_object **obj, game_object **elements,
                        gameinfo_t *info)
{
    for (int i = 0; i < 5; i++) {
        sfSprite_destroy(obj[i]->sprite);
        sfTexture_destroy(obj[i]->spritesheet);
    }
    for (int i = 0; i < info->nb_elements; i++) {
        sfSprite_destroy(elements[i]->sprite);
        sfTexture_destroy(elements[i]->spritesheet);
    }
    free(info);
    free(obj);
    free(elements);
}

void drawscore(gameinfo_t *info, sfRenderWindow *window)
{
    char *scr = concat("score:", " ", inttochar(info->score));
    sfFont *font = sfFont_createFromFile("font/police.ttf");
    sfText *score = sfText_create();
    sfText_setColor(score,sfCyan);
    sfText_setString(score, scr);
    sfText_setFont(score, font);
    sfText_setCharacterSize(score, 50);
    sfText_setPosition(score, (sfVector2f){300, 750});
    sfRenderWindow_drawText(window, score, NULL);
    sfText_destroy(score);
    sfFont_destroy(font);
}

int analyse_events(clocking_t **clocks, sfEvent event,
                    game_object *game, sfMusic *music)
{
    switch (event.type) {
        case sfEvtClosed : {
            return 84;
        } case sfEvtKeyPressed : {
            setjump(clocks, event, game, music);
            break;
        } default: break;
    }
    return 0;
}

void display_all(game_object **game, game_object **elements,
                sfRenderWindow *window, gameinfo_t *info)
{
    int i = 0;
    int j = 0;
    while (i < 5) {
        while (i == 3 && j < info->nb_elements) {
            sfSprite_setPosition(elements[j]->sprite, elements[j]->pos);
            sfRenderWindow_drawSprite(window, elements[j]->sprite, NULL);
            j++;
        }
        sfSprite_setPosition(game[i]->sprite, game[i]->pos);
        sfRenderWindow_drawSprite(window, game[i]->sprite, NULL);
        i++;
    }
}

void usage(void)
{
    my_printf("Runner using csfml\n\n");
    my_printf("USAGE\n  ./my_runner map.picto\n\n\n");
    my_printf("OPTIONS\n  -i            launch the game in infinity mode.\n");
    my_printf("  -h            print the usage.\n");
    my_printf("  -d [size]     create an empty map of length x.\n\n");
    my_printf("USER INTERACTIONS\n  SPACE_KEY       jump.\n");
}

int createmap(gameinfo_t *info, char *filename)
{
    int fd = open(filename, O_RDONLY);
    int size = 30000;
    char *buf = malloc(sizeof(char) * size);
    int sizeline;
    int elements = 0;
    int j = 0;

    sizeline = (read(fd, buf, size) / 3) + 1;
    info->map = malloc(sizeof(char **) * 3);
    info->map[0] = malloc(sizeof(char *) * (size / 3));
    info->map[1] = malloc(sizeof(char *) * (size / 3));
    info->map[2] = malloc(sizeof(char *) * (size / 3));
    for (int i = 0; i < 3; i++) {
        for (; j < sizeline; j++) {
            info->map[i][j] = buf[elements];
            elements++;
        }
        info->map[i][j] = '\0';
        j = 0;
    }
    free(buf);
    return 1;
}

char *getmap(int size)
{
    char *map = malloc(sizeof(char) * (size + 12) * 3);
    int x = 0;

    for (int i = 0; i < size+12; i++, x++)
        map[x] = ' ';
    map[x++] = '\n';
    for (int j = 0; j < size+12; j++, x++)
        map[x] = ' ';
    map[x-1] = '5';
    map[x++] = '\n';
    for (int j = 0; j < size+12; j++, x++)
        map[x] = '4';
    map[x++] = '\0';
    return map;
}

int download(int size)
{
    char *filename = concat("map",inttochar(size),".picto");
    char *map;
    int fd;

    if (open(filename,O_RDONLY) != -1) {
        free(filename);
        return 84;
    } else {
        map = getmap(size);
        fd = open(filename,O_WRONLY | O_APPEND | O_CREAT, 0755);
        write(fd, map, my_strlen(map));
        close(fd);
        free(filename);
        free(map);
        return 1;
    }
}

int getinfo(gameinfo_t *info, char **av, int ac)
{
    int res;

    info->nb_elements = 0;
    info->level = 1;
    info->level_speed = 0.001;
    if (ac == 2 && av[1][0] == '-') {
        if (av[1][1] == 'i') {
            srand(time(NULL));
            info->infini = 1;
            return 0;
        } else if (av[1][1] == 'h') {
            usage();
            return 1;
        } else if (av[1][1] == 'd') {
            my_printf("Flag '%s' need 1 argument but 0 is given\n",av[1]);
            my_printf("Type ./my_runner -h for help\n");
            return 84;
        } else {
            my_printf("Invalid flag '%s'\n",av[1]);
            my_printf("Type ./my_runner -h for help\n");
            return 84;
        }
    } else if (ac == 2) {
        res = createmap(info, av[1]);
        if (res == 84) {
            my_printf("Map should be a '.picto'\n");
            my_printf("Type ./my_runner -h for help\n");
            return 84;
        } else
            return 0;
    } else if (ac == 3 && av[1][0] == '-' && av[1][1] == 'd') {
        if (download(my_getnbr(av[2])) == 1) {
            my_printf("File name 'map%s.picto' has been create.\n",av[2]);
            return 1;
        } else {
            my_printf("Unable to create 'map%s.picto'",av[2]);
            my_printf(",already exist.\n");
            return 84;
        }
    } else {
        my_printf("Invalid number of arguments\n");
        my_printf("Type ./my_runner -h for help\n");
        return 84;
    }
}

int isclose (sfEventType event)
{
    if (event == sfEvtClosed)
        return 1;
    return 0;
}

void win(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile("pictures/win.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfEvent event;
    int close = 0;
    sfMusic *music = sfMusic_createFromFile("sounds/win.ogg");
    sfMusic_play(music);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
    while (close == 0) {
        while (sfRenderWindow_pollEvent(window, &event))
            close = isclose(event.type);
    }
    sfMusic_destroy(music);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void lose(sfRenderWindow *window, char *res)
{
    sfTexture *texture = sfTexture_createFromFile("pictures/end.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfEvent event;
    int close = 0;
    char *scr = concat("score:", " ", res);
    sfFont *font = sfFont_createFromFile("font/police.ttf");
    sfText *score = sfText_create();
    sfMusic *music = sfMusic_createFromFile("sounds/lose.ogg");
    sfMusic_play(music);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfText_setColor(score,sfCyan);
    sfText_setString(score, scr);
    sfText_setFont(score, font);
    sfText_setCharacterSize(score, 100);
    sfText_setPosition(score, (sfVector2f){385, 485});
    sfRenderWindow_drawText(window, score, NULL);
    sfRenderWindow_display(window);
    while (close == 0) {
        while (sfRenderWindow_pollEvent(window, &event))
            close = isclose(event.type);
    }
    sfMusic_destroy(music);
    sfText_destroy(score);
    sfFont_destroy(font);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

int main(int ac, char **av)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1600, 900, 32};
    sfEvent event;
    gameinfo_t *info = malloc(sizeof(gameinfo_t));
    game_object **game = create_gameobject();
    game_object **elements = malloc(sizeof(game_object *) * 1000);
    clocking_t **clocks = createclocks();
    sfMusic *music = sfMusic_createFromFile("sounds/jump.ogg");
    sfMusic *main = sfMusic_createFromFile("sounds/main-song.ogg");
    int r = getinfo(info, av, ac);
    int cl = 0;

    sfMusic_play(main);
    switch (r){
        case 0:break;
        case 1: {
            free(clocks);
            sfMusic_destroy(main);
            destroy_objects(game, elements, info);
            sfMusic_destroy(music);
            return 0;
        } case 84: {
            free(clocks);
            sfMusic_destroy(main);
            destroy_objects(game, elements, info);
            sfMusic_destroy(music);
            return 84;
        }
    }
    window = sfRenderWindow_create(mode, "My runner", sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        cl = check_clocks(game, elements, clocks, info);
        if (cl == 1 || cl == 5)
            break;
        while (sfRenderWindow_pollEvent(window, &event))
            r = analyse_events(clocks, event, game[4], music);
        if (r == 84)
            break;
        if (check_collision(elements, info, clocks[2], game))
            break;
        display_all(game, elements, window, info);
        drawscore(info, window);
        sfRenderWindow_display(window);
    }
    free(clocks);
    sfMusic_destroy(main);
    if (info->infini == 0 && info->map[1][info->map_place] == '5')
        win(window);
    else
        lose(window, inttochar(info->score));
    destroy_objects(game, elements, info);
    sfMusic_destroy(music);
    sfRenderWindow_destroy(window);
    return 0;
}
