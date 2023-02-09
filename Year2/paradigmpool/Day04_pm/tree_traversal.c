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

// Ex 05-6
/* Iterates over tree and displays its content using container and dump_func. */
void tree_traversal(tree_t tree, container_t *container, dump_func_t dump_func)
{
    tree_node_t *node;

    if (tree == NULL)
        return;
    container->push_func(container->container, tree);
    while (1) {
        node = container->pop_func(container->container);
        dump_func(node->data);
        if (node->children != NULL)
            container->push_func(container->container, node->children);
        else
            break;
    }
}
