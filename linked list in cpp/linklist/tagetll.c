#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* createnode(int val)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=val;
    newnode->next=NULL;
    return newnode;
}

void findtarget(struct node* head , int target)
{
    int flag=0;
    struct node * start=head;
    while(start!=NULL)
    {
        if(start->data==target)
        {
            flag=1;
            break;
           
        }
        start=start->next;
    }
    if(flag==1)
    {
        printf("the value is found");
    }
    else{
        printf("the value is not found ");
    }
    return ;
}

void apendnode(struct node**head , int val)
{
    struct node* newnode=createnode(val);

    if((*head)==NULL)
    {
        *head=newnode;
    }
    else{
    struct node * temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    }
}

int main()
{
    struct node* head=NULL;
    int n, target , val;
    printf("enter the number of nodes you want to enter ::- ");
    scanf("%d", &n);
    printf("enter the values of nodes");
    for(int i=0;i<n;i++)
    {
        scanf("%d->",&val );
        apendnode(&head , val);
        
    }
    printf("enter the target value which you wnat to match ::");
    scanf("%d" , &target);

    // int target=30;
    // head=createnode(10);
    // head->next=createnode(20);
    // head->next->next=createnode(30);
    // head->next->next->next=createnode(40);


    findtarget(head , target);
    return 0;


}
