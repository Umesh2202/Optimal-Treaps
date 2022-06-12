//! PRIORITY IS DEFAULT 1

#include "treap.h"

treap *init_treap(treap *t)
{
    t = NULL;
    return t;
}

void heapify(treap *t);

int check_imbalance(treap *t);

treap *perform_rot(treap *t);

treap *insert_treap(treap *t, char key[], treap *p, int priority)
{

    if (t == NULL)
    {
        treap *temp = (treap *)malloc(sizeof(treap));
        (temp)->priority = priority;
        (temp)->right = NULL;
        (temp)->left = NULL;
        (temp)->parent = p;
        strcpy(temp->data, key);
        return temp;
    }

    p = t;

    if (strcmp(key, (t)->data) < 0)
    {
        (t)->left = insert_treap((t)->left, key, p, priority);
    }
    else if (strcmp(key, (t)->data) > 0)
    {
        (t)->right = insert_treap((t)->right, key, p, priority);
    }
    else
    {
        (t)->priority += priority;
    }

    int bf = check_imbalance(t);
    // printf("\n\n%d\n\n", bf);

    // treap *temp = t;
    if (bf == 1)
    {
        return perform_rot(t);
    }
    // temp = t;
    // heapify(temp);

    return t;
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

void delete (treap *t)
{
    if (t->left == NULL && t->right == NULL) //*Zero child
    {
        if (t->parent->left == t)
            t->parent->left = NULL;
        else
            t->parent->right = NULL;
        free(t);
    }

    else if (t->left != NULL && t->right == NULL) //*One child,left child
    {
        treap *temp = t->left;

        if (t->parent->left == t)
            t->parent->left = temp;
        else
            t->parent->right = temp;

        temp->parent = t->parent;
        free(t);
    }
    else if (t->left == NULL && t->right != NULL) //*One child,right child
    {
        treap *temp = t->right;

        if (t->parent->left == t)
            t->parent->left = temp;
        else
            t->parent->right = temp;

        temp->parent = t->parent;
        free(t);
    }

    else if (t->left != NULL && t->right != NULL) //*Two child
    {
        treap *temp;

        if (t->parent->left == t)
        {
            temp = t->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
        }
        else if (t->parent->right == t)
        {
            temp = t->left;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
        }

        swap(&(t->priority), &(temp->priority));
        swap_str(t->data, temp->data);
        delete (temp);
    }
}

void rebalance(treap *t)
{
    if (t == NULL || (t->left == NULL && t->right == NULL))
    {
        return;
    }

    if (t->left != NULL && t->right == NULL)
    {

        if (strcmp(t->left->data, t->data) > 0) //*Left string is greater than root string
        {
            treap *temp = t->left;
            char arr1[100];
            strcpy(arr1, temp->data);
            int pr = temp->priority;
            delete (temp);

            treap *p = t;
            insert_treap(t, arr1, p, pr);
            rebalance(t);
        }
    }

    else if (t->left == NULL && t->right != NULL) //*Right string is greater than root string
    {
        if (strcmp(t->right->data, t->data) < 0)
        {
            treap *temp = t->right;
            char arr1[100];
            strcpy(arr1, temp->data);
            int pr = temp->priority;
            delete (temp);

            treap *p = t;
            insert_treap(t, arr1, p, pr);
            rebalance(t);
        }
    }

    else if (t->left != NULL && t->right != NULL) //*Both child of root node
    {

        if (strcmp(t->left->data, t->data) > 0) //*Left string is greater than root string
        {
            treap *temp = t->left;
            char arr1[100];
            strcpy(arr1, temp->data);
            int pr = temp->priority;
            delete (temp);

            treap *p = t;
            insert_treap(t, arr1, p, pr);
            rebalance(t);
        }

        else if (strcmp(t->right->data, t->data) < 0) //*Right string is greater than root string
        {
            treap *temp = t->right;
            char arr1[100];
            strcpy(arr1, temp->data);
            int pr = temp->priority;
            delete (temp);

            treap *p = t;
            insert_treap(t, arr1, p, pr);
            rebalance(t);
        }
    }
    rebalance(t->left);
    rebalance(t->right);
    heapify(t);
}

void show_recommendation(treap *t)
{
    inorder(t);
    if (t != NULL)
    {
        printf("\t\t\t\t\t\t\t\t\tOur top orders !!!-----------\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t| %s", t->data);
        if (t->left != NULL)
            printf("\n\n\t\t\t\t\t\t\t\t\t| %s", t->left->data);
        if (t->right != NULL)
            printf("\n\n\t\t\t\t\t\t\t\t\t| %s", t->right->data);
        printf("\n\n");
    }
}

int height(treap *t)
{
    if (t == NULL)
    {
        return -1;
    }
    int a = height(t->left);
    int b = height(t->right);
    if (a >= b)
    {
        return a + 1;
    }
    else
        return b + 1;
}

int check_imbalance(treap *t)
{
    if (abs(height(t->left) - height(t->right)) == 2)
        return 1;
    return 0;
}

treap *Rotate_LL(treap *t)
{
    printf("LL ");
    treap *tl = t->left;
    treap *tlr = tl->right;

    t->left = tlr;

    tl->right = t;

    if (tlr != NULL)
    {
        tlr->parent = t;
    }

    t->parent = tl;

    tl->parent = t->parent;

    return tl;
}

treap *Rotate_RR(treap *t)
{
    printf("RR");
    treap *tr = t->right;
    treap *trl = tr->left;

    t->right = trl;

    tr->left = t;

    if (trl != NULL)
    {
        trl->parent = t;
    }

    t->parent = tr;

    tr->parent = t->parent;

    return tr;
}

treap *Rotate_LR(treap *t)
{
    printf("LR");
    treap *tl = t->left;
    treap *tlr = tl->right;

    t->left = tlr;
    tlr->parent = t;

    tlr->left = tl;
    tl->parent = tlr;

    tlr = Rotate_LL(t);

    return tlr;
}

treap *Rotate_RL(treap *t)
{
    printf("RL");
    treap *tr = t->right;
    treap *trl = tr->left;

    t->right = trl;
    trl->parent = t;

    trl->right = tr;
    tr->parent = trl;

    trl = Rotate_RR(t);

    return trl;
}

treap *perform_rot(treap *t)
{
    treap *l = t->left;
    treap *r = t->right;
    if (height(t->left) - height(t->right) == 2 && (height(l->left) - height(l->right)) == 1)
    {
        printf("1");
        return Rotate_LL(t);
    }
    else if (height(t->left) - height(t->right) == -2 && (height(l->left) - height(l->right)) == -1)
    {
        printf("2");
        return Rotate_RR(t);
    }
    else if (height(t->left) - height(t->right) == 2 && (height(l->left) - height(l->right)) == -1)
    {
        printf("3");
        return Rotate_LR(t);
    }
    else if (height(t->left) - height(t->right) == -2 && (height(l->left) - height(l->right)) == 1)
    {
        printf("4");
        return Rotate_RL(t);
    }
    return t;
}
