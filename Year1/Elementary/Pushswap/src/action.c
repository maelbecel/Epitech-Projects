/*
** EPITECH PROJECT, 2021
** action.c
** File description:
** action
*/

#include "pushswap.h"
#include "my.h"
#include "printf.h"
#include <stdlib.h>

void delfirst(chainedlist_t *liste)
{
    if (liste->first != NULL){
        node_t *elm = liste->first;
        liste->first = liste->first->suiv;
        free(elm);
    }
}

void swapnode(node_t *node)
{
    int tmp;
    if (node->suiv && node){
        tmp = node->suiv->data;
        node->suiv->data = node->data;
        node->data = tmp;
        node = node->suiv;

    }
}

chainedlist_t *init_list(void)
{
    chainedlist_t *list = malloc(sizeof(chainedlist_t));
    node_t *elm = malloc(sizeof(node_t));

    elm->data = NULL;
    elm->suiv = NULL;
    elm->prec = NULL;
    list->size = 0;
    list->first = elm;
    list->last = elm;
    return list;
}

void add_nodes(chainedlist_t *list, int data)
{
    node_t *new = malloc(sizeof(node_t));
    new->data = data;
    new->prec = list->last;
    list->last->suiv = new;
    list->last = new;
    list->size++;
}
