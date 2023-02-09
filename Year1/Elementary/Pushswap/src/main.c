/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** pushswap.c
*/

#include "pushswap.h"
#include "my.h"
#include "printf.h"
#include <stdlib.h>

void print_nodes(node_t *node)
{
    while (node) {
        my_printf("%d ", node->data);
        node = node->suiv;
    }
    my_putchar('\n');
}

void set_linked_list(char **av, chainedlist_t *list)
{
    for (int i = 1; av[i] != NULL; i++)
        add_nodes(list, my_getnbr(av[i]));
    delfirst(list);
}

int get_smaller_place(chainedlist_t *list)
{
    node_t *node = list->first;
    int end = TRUE;
    int smaller = node->data;
    int smaller_place = 1;

    for (int i = 1; i <= list->size; i++) {
        if (node->data < smaller){
            smaller = node->data;
            smaller_place = i;
        }
        if (list->size > 1 && node->suiv != NULL &&
            node->data > node->suiv->data)
            end = FALSE;
        node = node->suiv;
    }
    if (end)
        return 0;
    else
        return smaller_place;
}

void tri_insert(chainedlist_t *list_a, chainedlist_t *list_b)
{
    int smallest;
    if (!get_smaller_place(list_a))
        return;
    while ((smallest = get_smaller_place(list_a)) != 0){
        if (smallest <= list_a->size/2){
            ra(list_a, smallest-1);
        }else{
            rra(list_a, list_a->size-(smallest-1));
        }
        pb(list_a, list_b, 1);
    }
    pa(list_a, list_b, list_b->size-1);
    paend(list_a, list_b, 1);
}

int main(int ac, char **av)
{
    chainedlist_t *list_a = init_list();
    chainedlist_t *list_b = init_list();
    set_linked_list(av, list_a);
    tri_insert(list_a, list_b);
    write(1,"\n",1);
    return 0;
}