#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Treap
{
    int priority;
    char data[100];
    struct Treap *right;
    struct Treap *left;
    struct Treap *parent;
} treap;

treap *init_treap(treap *t);

void show_recommendation(treap *t);

treap *insert_treap(treap *t, char key[], treap *p, int priority);

void rebalance(treap *t);

int height(treap *t);
