#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
   struct node *next;
};

struct node* createnode(int val)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;

}

void insert(struct node**head , int val , int pos)
{
    struct node* newnode=createnode(val);

    if(pos==1)
    {
        newnode->next=*head;
        *head=newnode;
        return ;
    }

    struct node *temp=*head;

    for(int i=1 ; i<pos-1 && temp!=NULL ; i++)
    {
        temp=temp->next;
    }

    if(temp!=NULL)
    {
        newnode->next=temp->next;
        temp->next=newnode;
    }
    else{
        printf("invalid choice ");
        free(newnode);
    }
    
}

void print(struct node *head){
    struct node *temp=head;

    while(temp!=NULL)
    {
        printf("%d -> " , temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
int main()
{
    int val , pos , ch;
    struct node *head=NULL;
    do{
        printf("enter the values ");
        scanf("%d", &val);
        getchar();

        printf("enter  the position");
        scanf("%d", &pos);

        insert(&head , val , pos);

        print(head);


        printf("do you want to continue press 1 for yes and 2 for no ");
        scanf("%d", &ch);
    }
    while (ch==1);
    return 0;
}