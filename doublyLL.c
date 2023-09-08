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

    int z=print(head);
    printf("%d",z);

    return 0;
}