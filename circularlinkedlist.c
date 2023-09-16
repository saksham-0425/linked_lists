#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node*deletion(struct node*head){
    struct node*p=head;
    struct node*q=head->next;
    struct node*r=head->next;
    
    printf("enter the position of the node you want to delete : ");
    int x;
    scanf("%d",&x);

    int count=1;
    while(r!=head){
        count++;
        r=r->next;
    }

    if(x==1){
        p=p->next;
        while (q->next != head)
        {
            q = q->next;
        }
        head=p;
        q->next=head;
        return head;
    }
    else if(x==count){
        while(q->next!=head){
            q=q->next;
            p=p->next;
        }
        p->next=head;
        free(q);
        return head;
    }
    else{
        for(int i=0;i<x-1;i++){
        p=p->next;
        q=q->next;
        }
        p->next=q->next;
        free(q);
        return head;
    }
    
}

struct node *insert(struct node *head)
{
    struct node *q;
    struct node *ptr = head->next;
    struct node *r = head;

    int count = 2;
    while (ptr != head)
    {
        count++;
        ptr = ptr->next;
    }

    printf("enter the position at which you want to insert : ");
    int x;
    scanf("%d", &x);

    q = (struct node *)malloc(sizeof(struct node));
    printf("enter the data of the new node : ");
    scanf("%d", &q->data);
    if (x == 1)
    {
        q->next = head;

        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        head = q;
        ptr->next = head;
        return head;
    }
    else if (x == count)
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = q;
        q->next = head;
        return head;
    }
    else
    {
        for (int i = 1; i < x - 1; i++)
        {
            r = r->next;
        }
        q->next = r->next;
        r->next = q;
        return head;
    }
}

void display(struct node *head)
{
    struct node *ptr = head;
    printf("%d ", ptr->data);
    ptr = ptr->next;
    while (ptr != head)
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
    struct node *x = head;

    for (int i = 0; i < (n - 1); i++)
    {
        q = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &q->data);
        q->next = head;
        p->next = q;
        p = q;
    }

    printf("The linked list elements are: \n");
    display(x);

    head = insert(head);
    display(head);

    head=deletion(head);
    display(head);
}