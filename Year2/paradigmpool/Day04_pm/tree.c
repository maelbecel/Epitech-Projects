/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "list.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Ex 05-1
bool tree_is_empty(tree_t tree)
{
    return (tree == NULL);
}

// Ex 05-2
void tree_node_dump(tree_node_t *tree_node, dump_func_t dump_func)
{
    if (tree_node == NULL)
        return;
    dump_func(tree_node->data);
}

// Ex 05-3
bool init_tree(tree_t *tree_ptr, void *data)
{
    tree_t new = malloc(sizeof(*new));
    if (new == NULL)
        return false;
    new->data = data;
    new->parent = NULL;
    new->children = NULL;
    *tree_ptr = new;
    return true;
}

// Ex 05-4
tree_node_t * tree_add_child(tree_node_t *tree_node, void *data)
{
    tree_t new = malloc(sizeof(*new));
    if (new == NULL)
        return NULL;
    new->data = data;
    new->parent = tree_node;
    new->children = NULL;
    list_add_elem_at_front(&tree_node->children, new);
    return new;
}

// Ex 05-5
bool tree_destroy(tree_t *tree_ptr)
{
    tree_t my_tree = *tree_ptr;
    if (my_tree == NULL)
        return false;
    while (my_tree->children != NULL)
        list_del_elem_at_front(&my_tree->children);
    free(my_tree);
    *tree_ptr = NULL;
    return true;
}
