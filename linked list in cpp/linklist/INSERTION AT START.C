#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node* create(int val){

    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode ;
    
}

void insert(struct node ** head , int val){
    struct node * newnode=create(val);

    newnode->next=*head;
    *head=newnode;

    

}

void print(struct node * head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d -> " , temp->data);
        temp=temp->next;
    }
}

int main()
{
    struct node * head=NULL;
    int val , ch;
    do{
        printf("enter the values ");
        scanf("%d" , &val);

        insert(&head , val);
        print(head);

        printf("do you want to continuee press 1 for yes  or 0 for no");

        scanf("%d" , &ch);


    }
    while(ch==1);
    return 0;
}