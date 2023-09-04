#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *ptr){
    printf("elements are as follows :");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    struct node *head;
    struct node *p;
    struct node *q;

    p=(struct node*)malloc(sizeof(struct node));
    head = p;
    for (int i = 0; i < 10; i++)
    {
        q = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&q->data);
        q->next=NULL;
        p->next=q;
        p=p->next;
        
        
    }
    p->next=NULL;
    display(head->next);
}
