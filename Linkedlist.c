#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *ptr)
{
    printf("Elements are as follows: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert(struct node *r, struct node *head){
    r = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &r->data);
    r->next = head->next; 
    head->next = r; 
}

void reverse(struct node **head) {
    struct node *prv = NULL;
    struct node *cu = *head;
    struct node *nx = NULL;

    while (cu != NULL) {
        nx = cu->next;
        cu->next = prv;
        prv = cu;
        cu = nx;
    }

    *head = prv; 
}

int main()
{
    struct node *head;
    struct node *p;
    struct node *q;
    struct node *r;
    

    p = (struct node *)malloc(sizeof(struct node));
    head = p;

    int n;
    printf("Enter the nodes you want to create: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        q = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &q->data);
        q->next = NULL;
        p->next = q;
        p = p->next;
    }

     
    display(head);
    insert(r,head);
    display(head->next);
    reverse(&head);
    display(head);
    return 0;
}


    
    
