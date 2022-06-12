#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//!!!!!!!!!!!!!!!!!!!!!! LINKED LIST !!!!!!!!!!!!!
struct node
{
    int data; //* sr no
    char foodname[100];
    int quantity;
    float price;
    struct node *next;
};

void mainmenu();

struct node *addmenu(struct node *head_a);

void displayadmin(struct node *head_a);

struct node *deletemenu(struct node *head_a);

struct node *place_order(struct node *head_a);

struct node *createadmin(struct node *head_a, char foodname[100], float price);

void displayorder();

void delete_item();

void displaybill();

void adminmenu();

void customermenu();

void changepassword();

void customer(struct node *head_a);

void pass(struct node *head_a);


