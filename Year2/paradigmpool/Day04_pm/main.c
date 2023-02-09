#include "list.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"
#include "int_list.h"

unsigned int int_list_get_size(int_list_t list);
bool int_list_is_empty(int_list_t list);

void int_list_dump(int_list_t list);
bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem);
bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem);
bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem,
                                    unsigned int position);
int int_list_get_elem_at_front(int_list_t list);
int int_list_get_elem_at_back(int_list_t list);
int int_list_get_elem_at_position(int_list_t list, unsigned int position);
bool int_list_del_elem_at_front(int_list_t *front_ptr);
bool int_list_del_elem_at_back(int_list_t *front_ptr);
bool int_list_del_elem_at_position(int_list_t *front_ptr,
                                    unsigned int position);
void int_list_clear(int_list_t *front_ptr);


int main (void)
{
    int_list_t list = NULL;

    printf("Size is %d\n", int_list_get_size(list));
    printf("Is empty ? => %s\n", int_list_is_empty(list) ? "true" : "false");
    int_list_del_elem_at_back(&list);
    int_list_add_elem_at_front(NULL, 12);
    int_list_del_elem_at_position(&list, 34567);
    int_list_add_elem_at_position(&list, 8, 0);
    int_list_add_elem_at_position(&list, 8, 34);
    int_list_add_elem_at_position(&list, 9, 0);
    printf("Size is %d\n", int_list_get_size(list));
    printf("Is empty ? => %s\n", int_list_is_empty(list) ? "true" : "false");
    printf("List =\n");
    int_list_dump(list);
    int_list_clear(&list);
    int_list_clear(&list);
    return 0;
}