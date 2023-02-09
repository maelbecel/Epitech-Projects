/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "defender.h"

void clicked(scene_t *scenes, ...)
{
    va_list arg;
    va_start(arg, scenes);
    int i = va_arg(arg, int);
    sfSprite_setTexture(scenes[scenes->page].buttons[i]->clicked->sprite,
            sfTexture_createFromFile("resource/UI/TitleStatsReverse.png",NULL),
                                        sfTrue);
    va_end(arg);
    return;
}

void hoover(scene_t *scenes, ...)
{
    va_list arg;
    va_start(arg, scenes);
    int i = va_arg(arg, int);
    sfSprite_setTexture(scenes[scenes->page].buttons[i]->hoover->sprite,
            sfTexture_createFromFile("resource/UI/TitleStatsHoover.png",NULL),
                                        sfTrue);
    va_end(arg);
    return;
}

void my_exit(int code)
{
    register int syscall_no asm("rax") = 60;
    register int arg1       asm("rdi") = code;
    asm("syscall");
    (void) syscall_no;
    (void) arg1;
}

void quit(scene_t *scenes, ...)
{
    va_list arg;
    va_start(arg, scenes);
    (void)(scenes);
    UNUSED int i = va_arg(arg, int);
    sfRenderWindow *window = va_arg(arg, sfRenderWindow *);
    sfRenderWindow_close(window);
    va_end(arg);
}

void do_none(scene_t *scenes, ...)
{
    (void)(scenes);
}