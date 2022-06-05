//! PRIORITY IS DEFAULT 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int priority;
    char data[100];
    struct node *right;
    struct node *left;
    struct node *parent;
} treap;

treap *init_treap(treap *t)
{
    t = NULL;
    return t;
}

void heapify(treap *t);

treap *insert_treap(treap *t, char key[], treap *p)
{

    if (t == NULL)
    {
        treap *temp = (treap *)malloc(sizeof(treap));
        (temp)->priority = 1;
        (temp)->right = NULL;
        (temp)->left = NULL;
        (temp)->parent = p;
        strcpy(temp->data, key);
        return temp;
    }

    p = t;

    if (strcmp(key, (t)->data) < 0)
    {
        (t)->left = insert_treap((t)->left, key, p);
    }
    else if (strcmp(key, (t)->data) > 0)
    {
        (t)->right = insert_treap((t)->right, key, p);
    }
    else
    {
        (t)->priority++;
    }

    treap *temp = t;
    heapify(temp);

    return temp;
}

int max_num(int x, int y, int z)
{
    if (x > y && x > z)
    {
        return x;
    }
    if (y > x && y > z)
    {
        return y;
    }
    if (z > y && z > x)
    {
        return z;
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap_str(char *x, char *y)
{
    char temp[100];
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}

void heapify(treap *t)
{
    while (t->parent != NULL)
    {
        if (t->priority > t->parent->priority)
        {
            swap(&(t->parent->priority), &(t->priority));
            swap_str(t->data, t->parent->data);
        }
        t = t->parent;
    }
}

void inorder(treap *t)
{
    if (t)
    {
        inorder(t->left);
        printf("String: %s | Priority: %d\n", t->data, t->priority);
        inorder(t->right);
    }
}

void rebalance(treap *t)
{
    if (t->left == NULL && t->right == NULL)
        return;
    treap *t_l = t->left;
    treap *t_r = t->right;
    if (strcmp(t->data, t_r->data) > 0 && t_l == NULL) //* right less than root and left NULL
    {
        t->left = t_r;
        t->right = NULL;
        rebalance(t);
        rebalance(t->left);
    }
    else if (strcmp(t->data, t_l->data) < 0 && t_r == NULL) //* left more than root and right NULL
    {
        t->right = t_l;
        t->left = NULL;
        rebalance(t);
        rebalance(t->right);
    }
}

int main()
{
    treap *t;
    treap *p = NULL;
    char arr[100];
    int choice;
    t = init_treap(t);

    while (1)
    {
        printf("\n1. Insert in heap\n");
        printf("2. Inorder\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("\nEnter the string to insert: ");
            scanf("%s", arr);
            if (t == NULL)
            {
                t = insert_treap(t, arr, p);
            }
            else
            {
                treap *temp = t;
                insert_treap(temp, arr, p);
            }
            // rebalance(t);
            break;
        }
        case 2:
            printf("\n");
            inorder(t);
            printf("\n");
            break;
        }
    }
    // t = insert_treap(t, "c", p);
    // insert_treap(t, "a", p);
    // insert_treap(t, "b", p);
    // printf("%s", t->left->right->data);
    // inorder(t);
    // printf("%s", t->data);
}