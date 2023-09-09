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

int kthfromlast(struct node *head){
    int k;
    printf("enter the position of the node (from last): ");
    scanf("%d",&k);
    struct node*fast=head;
    struct node*slow=head;

    for(int i=1;i<k;i++){
        fast=fast->next;
    }

    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    
    return slow->data;

}

int countnode(struct node *head)
{
    struct node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
    }

    if (fast->next == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
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

int getmiddle(struct node *head)
{
    struct node *fast = head;
    struct node *slow = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->data;
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
    if (n == 1)
    {
        printf("%d", p->data);
    }
    else
    {
        printf("The linked list elements are: \n");
        display(x);

        int a = getmiddle(head);
        printf("middle element is: %d\n", a);
        
        // printf("reversal of array : \n");
        // head = reverse(head);
        // display(head);

        int b = countnode(head);
        if (b == 1)
        {
            printf("even number of nodes");
        }
        else
        {
            printf("odd number of nodes\n");
        }

        int c=kthfromlast(head);
        printf("the kth element from last is : %d",c);
    }
}