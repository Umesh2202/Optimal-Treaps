#include "restaurant.h"

int main()
{
    struct node *head_a = NULL;
    head_a = createadmin(head_a, "Z", 100.00);
    head_a = createadmin(head_a, "X", 150.00);
    head_a = createadmin(head_a, "W", 200.00);
    head_a = createadmin(head_a, "E", 50.00);
    head_a = createadmin(head_a, "A", 120.00);
    printf("\033[0;33m");
    printf("\n\t\t\t\t\t\t***************************************************************************\n");
    printf("\n\t\t\t\t\t\t\t\t\t   WELCOME TO OUR RESTAURANT \n\n");
    printf("\t\t\t\t\t\t****************************************************************************\n");
    printf("\033[0m");
    int choice;
    while (1)
    {
        mainmenu();
        printf("\033[0;33m");
        scanf("%d", &choice);
        printf("\033[0m");
        if (choice == 3)
        {
            printf("\033[0;33m");
            printf("\n\t\t\t\t\t\t***************************************************************************\n");
            printf("\n\t\t\t\t\t\t\t\t\t   THANK YOU FOR VISITING \n\n");
            printf("\t\t\t\t\t\t****************************************************************************\n");
            printf("\033[0m");
        }
        switch (choice)
        {
        case 1:
            pass(head_a);
            break;
        case 2:
            customer(head_a);
            break;
        case 3:
            exit(1);
        default:
            printf("Incorrect Choice!\nPlease choose a valid option.\n");
        }
    }
}