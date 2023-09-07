#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *insert(struct node *head)
{
    struct node *r;
    r = (struct node *)malloc(sizeof(struct node));
    printf("enter the data to be inserted in the linked list : ");
    scanf("%d", &r->data);
    r->next = head;

    printf("The elements after insertion are: \n");
    return r;
}

struct node *reverse(struct node *head)
{
    struct node *prv = NULL;
    struct node *cu = head;
    struct node *nx = NULL;

    while (cu != NULL)
    {
        nx = cu->next;
        cu->next = prv;
        prv = cu;
        cu = nx;
    }

    head = prv;
    return head;
}

struct node *deleteatindex(struct node *ptr)
{
    printf("enter the position of the node you want to delete : ");
    int pos;
    scanf("%d", &pos);

    struct node *x = ptr;
    struct node *y = ptr->next;

    if (pos == 1)
    {
        ptr = ptr->next;
        free(x);
    }
    else if (pos == 2)
    {
        ptr->next = y->next;
        free(y);
    }
    else
    {
        for (int i = 2; i < pos; i++)
        {
            x = x->next;
            y = y->next;
        }
        x->next = y->next;
        free(y);
    }
    return ptr;
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
    struct node *x = head;

    for (int i = 0; i < (n - 1); i++)
    {
        q = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &q->data);
        q->next = NULL;
        p->next = q;
        p = q;
    }

    printf("The linked list elements are: \n");
    display(x);

    head = insert(x);
    display(head);

    printf("The linked list elements after reversal are: \n");
    head = reverse(head);
    display(head);

    head = deleteatindex(head);
    display(head);
    // return 0;
}
