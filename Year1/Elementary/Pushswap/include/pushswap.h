/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** pushswap
*/

#ifndef PUSHSWAP
    #define PUSHSWAP
    #define FALSE 0
    #define TRUE !(FALSE)

    typedef struct node
    {
        int data;
        struct node *suiv;
        struct node *prec;
    } node_t;

    typedef struct list
    {
        int size;
        node_t *first;
        node_t *last;
    }chainedlist_t;

    chainedlist_t *init_list(void);
    void add_nodes(chainedlist_t *list, int data);
    void delfirst(chainedlist_t *list);
    void sa(chainedlist_t *list_a);
    void sb(chainedlist_t *list_b);
    void sc(chainedlist_t *list_a, chainedlist_t *list_b);
    void pa(chainedlist_t *list_a, chainedlist_t *list_b, int n);
    void pb(chainedlist_t *list_a, chainedlist_t *list_b, int n);
    void rb(chainedlist_t *list_b, int n);
    void ra(chainedlist_t *list_a, int n);
    void rr(chainedlist_t *list_a, chainedlist_t *list_b, int n);
    void rrb(chainedlist_t *list_b, int n);
    void rra(chainedlist_t *list_a, int n);
    void rrr(chainedlist_t *list_a, chainedlist_t *list_b, int n);

#endif /* !PUSHSWAP */
