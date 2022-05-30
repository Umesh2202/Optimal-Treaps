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
} node;

typedef node *treap;

void init_treap(treap *t)
{
    *t = NULL;
}

treap insert_treap(treap t, char key[], treap p)
{

    if (t == NULL)
    {
        treap temp = (treap)malloc(sizeof(treap));
        (temp)->priority = 1;
        (temp)->right = NULL;
        (temp)->left = NULL;
        (temp)->parent = NULL;
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
}

void inorder(treap t)
{
    if (t)
    {
        inorder(t->left);
        printf("String: %s | Priority: %d", t->data, t->priority);
        inorder(t->right);
    }
}

int main()
{
    treap t;
    treap p = t;
    char arr[100];
    int choice;
    init_treap(&t);

    while (1)
    {
        printf("\n1. Insert in heap\n");
        printf("2. Inorder\n");
        // printf("Insert in heap");
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the string to insert: ");
            scanf("%s", arr);
            if (t == NULL)
            {
                t = insert_treap(t, arr, p);
            }
            else
            {
                insert_treap(t, arr, p);
            }
            break;
        }
        case 2:
            printf("\n");
            inorder(t);
            printf("\n");
            break;
        }
    }
    // t = insert_treap(t, arr, p);
    // inorder(t);
    // printf("%s", t->data);
}