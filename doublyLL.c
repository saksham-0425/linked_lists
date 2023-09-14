#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node*prv;
    int data;
    struct node *next;
};

void display(struct node*head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int print(struct node*head){
    struct node*p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p=p->prv->prv->prv->prv;
    return p->data;
}

struct node *insert(struct node *head)
{
    int x;
    printf("enter the index at which you want to insert : ");
    scanf("%d", &x);
    if (x == 0)
    {
        struct node *r = (struct node *)malloc(sizeof(struct node));
        printf("enter data : ");
        scanf("%d", &r->data);
        r->prv = NULL;
        r->next = head;
        head = r;
        return head;
    }
    struct node *p = head;
    for (int i = 0; i < x - 1; i++)
    {
        p = p->next;
    }
    struct node *q = (struct node *)malloc(sizeof(struct node));
    printf("enter the data");
    scanf("%d", &q->data);
    q->prv = p;
    q->next = p->next;
    p->next = q;
    p = p->next->next;
    p->prv = q;

    return head;
}

struct node* deletion(struct node* head,int n){
    struct node*p=head;
    struct node*q=head->next;
     
    printf("enter the index at which you want to delete : ");
    int x;
    scanf("%d",&x);

    if(x==0){
        q->prv=NULL;
        head=q;
        free(p);
        return head;
    }

    if(x==n){
        while(q->next!=NULL){
            p=p->next;
            q=q->next;
        }
        p->next=NULL;
        free(q);
        return head;
    }

    for(int i=0;i<x-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    q=q->next;
    q->prv=p;

    return head;
}


int main(){

    struct node*head=NULL;
    struct node*q;

    printf("Enter the number of nodes you want to create : ");
    int n;
    scanf("%d",&n);

    struct node*p=(struct node*)malloc(sizeof(struct node));
    p->prv=NULL;
    printf("enter data : \n");
    scanf("%d",&p->data);
    
    head=p;
    struct node*x=head;

    for(int i=0;i<n-1;i++){
        q=(struct node*)malloc(sizeof(struct node));
        q->prv=p;
        scanf("%d",&q->data);
        q->next=NULL;
        p->next=q;
        p=q;
    }
    printf("The linked list elements are: \n");
    display(x);

    // int z=print(head);
    // printf("%d",z);

    head=insert(head);
    display(head);

    head=deletion(head);
    display(head);
    return 0;
}
