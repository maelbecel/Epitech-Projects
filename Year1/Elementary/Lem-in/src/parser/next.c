/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-lemin-lucas.iglesia
** File description:
** next
*/

#include "my.h"
#include "printf.h"
#include "lemin.h"

void verif_next(UNUSED room_t *room, UNUSED room_t *link)
{
    int i = 0;

    for (; room->next[i] != NULL; i++);
    room->next[i] = link;
}
