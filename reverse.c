#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void reversalusingrecursion(struct node *head)
{
    struct node *p = head;
   
    if (p->next != NULL)
    {
        reversalusingrecursion(p->next);
    }
    printf("%d ", p->data);
}

void display(struct node *ptr)
{

   
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    
}

void main()
{
    struct node *head = NULL;
    struct node *p;
    struct node *q;

    int n;
    printf("Enter the nodes you want to create: ");
    scanf("%d", &n);

    p = (struct node *)malloc(sizeof(struct node));
    printf("enter data : \n");
    scanf("%d", &p->data);

    head = p;

    if (n == 1)
    {
        printf("%d", p->data);
    }
    else
    {
        for (int i = 0; i < (n - 1); i++)
        {
            q = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &q->data);
            q->next = NULL;
            p->next = q;
            p = q;
        }

        printf("The linked list elements are: \n");
        display(head);

        printf("The linked list elements after reversal are: \n");
        reversalusingrecursion(head);

        // return 0;
    }
}