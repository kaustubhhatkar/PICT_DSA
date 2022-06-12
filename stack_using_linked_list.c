#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *Push(struct node *top, struct node *bottom);
struct node *Pop(struct node *top, struct node *bottom);

int main()
{
    struct node *top;
    struct node *bottom;
    top = NULL;

    bottom = (struct node *)malloc(sizeof(struct node));
    if (bottom == NULL)
    {
        printf("\n\nStack is FuLL (NO Space Available)");
        exit(0);
    }
    else
    {
        bottom->data = -1;
        bottom->next = NULL;
    }

    int choice;

    do
    {
        printf("\n\n\n\n\t Stack and its operations using Linked List:");
        printf("\n\n Enter the choice asssociated with the number:");
        printf("\n1) Push");
        printf("\n2) Pop");
        printf("\n3) Exit");
        printf("\n=>");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                top = Push(top, bottom);
                break;
            }
            case 2:
            {
                top = Pop(top, bottom);
                break;
            }
            case 3:
            {
                exit(0);
            }

            default:
            {
                printf("\n\nThe Value Entered is not associated in the above list please Enter again!");
                break;
            }
        }
    } 
    while (1);

    return 0;
}

struct node *Push(struct node *top, struct node *bottom)
{
    printf("\nx-----------------------------------------------------------------x");
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\n\nStack is FuLL (NO Space Available)");
        exit(0);
    }
    printf("\n\nEnter the Data to be pushed into the stack:");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (top == NULL)
    {
        top = temp;
        temp->next = bottom;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
    printf("\nElement %d Pushed in the stack successfully!", temp->data);
    printf("\nx-----------------------------------------------------------------x");
    return top;
}

struct node *Pop(struct node *top, struct node *bottom)
{
    printf("\nx-----------------------------------------------------------------x");
    struct node *temp;
    if (top->data != bottom->data)
    {
        temp = top;
        printf("\nThe data %d is Poped from the stack!", temp->data);
        top = top->next;
    }
    else
    {
        printf("\n\nThe stack is Empty!!!!");
    }
    printf("\nx-----------------------------------------------------------------x");
    return top;
}