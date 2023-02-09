/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

void display_main_menu(sfRenderWindow *window, scene_t *scenes,
                        sfEvent *event, game_t *game)
{
    int b = 0;
    int e = 0;
    prep_game(game, scenes);

    while(scenes[0].elements[e])
        draw_element(window, scenes[0].elements[e++]);
    while(scenes[0].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(window, scenes, game, b, 0)) {
            sfMusic_stop(game->sound_clicked);
            sfMusic_play(game->sound_clicked);
            draw_clicked(window, scenes[0].buttons[b++], game);
        } else if (is_hoover(window, scenes, b, 0))
            draw_hoover(window, scenes[0].buttons[b++], game);
        else
            draw_button(window, scenes[0].buttons[b++]);
    }
}

void display_game(sfRenderWindow *window, scene_t *scenes,
                    sfEvent *event, game_t *game)
{
    (void) event;
    int b = 0;
    int e = 0;
    int x = 0;

    while(scenes[1].buttons[x])
        draw_button(window, scenes[1].buttons[x++]);
    move_game_elements(scenes, window);
    if (game->head->id != 0)
        draw_tower(window, game);
    game->info->elements[3]->scale.x = (float)game->life / 10.00;
    draw_monster(game, window);
    while(game->info->elements[e])
        draw_element(window, game->info->elements[e++]);
    draw_element(window, scenes[1].elements[1]);
    draw_element(window, scenes[1].elements[3]);
    while(scenes[1].buttons[b]) {
        if (scenes[1].buttons[b]->is_tower && scenes[1].menu_tower &&
            scenes[1].buttons[b]->pos.x == game->menu_tower->x &&
            scenes[1].buttons[b]->pos.y == game->menu_tower->y ) {
            game->type = TOWER;
            draw_menu(window, game, TOWER);
        } else if (scenes[1].menu_tower &&
            scenes[1].buttons[b]->pos.x == game->menu_tower->x &&
            scenes[1].buttons[b]->pos.y == game->menu_tower->y) {
            game->type = NO_TOWER;
            draw_menu(window, game, NO_TOWER);
        }
        b++;
    }
    draw_text(inttochar(game->money), 60, (sfVector2f){90, 22}, window);
    draw_text(inttochar(game->kill), 60, (sfVector2f){90, 109}, window);
}

void display_help(sfRenderWindow *window, scene_t *scenes,
                    sfEvent *event, game_t *game)
{
    int b = 0;
    int e = 0;

    while(scenes[2].elements[e])
        draw_element(window, scenes[2].elements[e++]);
    while(scenes[2].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(window, scenes, game, b, 2)) {
            sfMusic_stop(game->sound_clicked);
            sfMusic_play(game->sound_clicked);
            draw_clicked(window, scenes[2].buttons[b++], game);
        } else if (is_hoover(window, scenes, b, 2))
            draw_hoover(window, scenes[2].buttons[b++], game);
        else
            draw_button(window, scenes[2].buttons[b++]);
    }
}

void display_pause_menu(sfRenderWindow *window, scene_t *scenes,
                        sfEvent *event, game_t *game)
{
    int bt = 0;
    int b = 0;
    int e = 0;
    int m = 0;

    while(scenes[1].buttons[bt])
        draw_button(window, scenes[1].buttons[bt++]);
    draw_element(window, scenes[1].elements[0]);
    draw_element(window, scenes[1].elements[2]);
    while(game->monster[m])
        draw_element(window, game->monster[m++]->monster);
    draw_element(window, scenes[1].elements[1]);
    draw_element(window, scenes[1].elements[3]);
    if (game->head->id != 0)
        draw_tower(window, game);
    game->info->elements[3]->scale.x = (float)game->life / 10.00;
    while(game->info->elements[e])
        draw_element(window, game->info->elements[e++]);
    draw_text(inttochar(game->money), 60, (sfVector2f){90, 22}, window);
    draw_text(inttochar(game->kill), 60, (sfVector2f){90, 117}, window);
    while(scenes[3].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(window, scenes, game, b, 3)) {
            sfMusic_stop(game->sound_clicked);
            sfMusic_play(game->sound_clicked);
            draw_clicked(window, scenes[3].buttons[b++], game);
        } else if (is_hoover(window, scenes, b, 3))
            draw_hoover(window, scenes[3].buttons[b++], game);
        else
            draw_button(window, scenes[3].buttons[b++]);
    }
}

void display_game_over(sfRenderWindow *window, scene_t *scenes,
                        sfEvent *event, game_t *game)
{
    int b = 0;
    int e = 0;

    if (event->type == sfEvtMouseButtonPressed &&
        (is_click(window, scenes, game, 0, 4) ||
        is_click(window, scenes, game, 1, 4)))
        prep_game(game, scenes);
    while(scenes[4].elements[e])
        draw_element(window, scenes[4].elements[e++]);
    while(scenes[4].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(window, scenes, game, b, 4)) {
            sfMusic_stop(game->sound_clicked);
            sfMusic_play(game->sound_clicked);
            draw_clicked(window, scenes[4].buttons[b++], game);
        } else if (is_hoover(window, scenes, b, 4))
            draw_hoover(window, scenes[4].buttons[b++], game);
        else
            draw_button(window, scenes[4].buttons[b++]);
    }
    setscore(game->kill);
    draw_text("Score :", 120, (sfVector2f){600, 100}, window);
    draw_text(inttochar(game->kill), 120, (sfVector2f){610, 200}, window);
    draw_text("Best score :", 120, (sfVector2f){600, 400}, window);
    draw_text(inttochar(getscore()), 120, (sfVector2f){610, 500}, window);
}

void display(sfRenderWindow *window, scene_t *scenes,
                sfEvent *event, game_t *game)
{
    switch (scenes->page) {
    case 0: display_main_menu(window, scenes, event, game);
        break;
    case 1: display_game(window, scenes, event, game);
        break;
    case 2: display_help(window, scenes, event, game);
        break;
    case 3: display_pause_menu(window, scenes, event, game);
        break;
    case 4: display_game_over(window, scenes, event, game);
        break;
    }
}