// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node *next;

// };

// struct node* create(int val){
//     struct node *newnode=(struct node *)malloc(sizeof(struct node));
//     newnode->data=val;
//     newnode->next=NULL;
//     return ;
// }

// void insert(struct node **head , int val , int pos){
//     struct node * newnode=create(val);

//     if(pos==1)
//     {
//         newnode->next=*head;
//         *head=newnode;
//         return ;
//     }

//     struct node *temp=*head;

//     for(int i=1 ; i<pos-1 && temp!=NULL ; i++)
//     {
//         temp=temp->next;
//     }

//     if(temp!=NULL)
//     {
//         newnode->next=temp->next;
//         temp->next=newnode;
//     }
//     else{
//         printf("invalid choice ");

//         free(newnode);
//     }

// }

// void delete(struct node ** head , int val , int pos2){

//     if(*head==NULL)
//     {
//         printf("list is empty ");
//         return ;
//     }
      
//       struct node * temp=*head;
//     if (pos2==1)
//     {
//         *head=temp->next;
//         free(temp);
//         return ;
//     }

//     if(temp ==NULL || temp->next==NULL){
//         printf("invalid choice ");
//         return ;
//     }

//     struct node * nodetodelete=temp->next;
//     temp->next=nodetodelete->next;
//     free(nodetodelete);


// }
// void print(struct node *head)
// {
//  struct node* temp=head;
//  while(temp!=NULL)
//  {
//     printf("%d -> " , temp->data);
//     temp=temp->next;
//  }
//  return ;
    
// }
// int main()
// {
//     struct node *head=NULL;
//     int val , pos ,pos2 , ch;
//     do{
//         printf("enter the values ");
//         scanf("%d", &val);

//         printf("enter the position");
//         scanf("%d", &pos);

//         insert(&head , val , pos);

//         print(head);

//         printf("do you want to delete the node ? for yes press 1 nhi toh  0");
//         scanf("%d" , &ch);

//         if(ch==1)
//         {
//             printf("enter the position of the node which you want to dlete ");
//             scanf("%d" , &pos2);
//               delete(&head , val , pos2 );
//               print(head);
//         }

      

//         printf("do you want to continue   press 1 for yes and 2 for no");
//         scanf("%d" , &ch);
//     }
//     while (ch==1);
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

struct node* insert(struct node* head, int val) {
    struct node* newnode = create(val);
    if (head == NULL) {
        return newnode;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

struct node *deleteAtPosition(struct node * head , int pos)
{
    if(head==NULL)
    {
        printf("linked list is empty");
    }
    struct node * temp=head;
    if(pos==1)
    {
        head=temp->next;
        free(head);
    }
    if(temp==NULL || temp->next==NULL)
    {
        printf("out of the bound");
        return head;
    }
    for(int i=1 ; i<pos-1 && temp!=NULL ; i++)
    {
        temp=temp->next;
    }

    struct node *next=temp->next->next;
    free(temp->next);
    temp->next=next;

    return head;


}

void display(struct node* head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int val, ch, pos;

    do {
        printf("1-- Insert, 2-- Display, 3-- Delete at Position, 4-- Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                head = insert(head, val);
                break;

            case 2:
                display(head);
                break;

            case 3:
             printf("enter the position to delete the node ");
             scanf("%d" , &pos);
             head=deleteAtPosition(head , pos);
             break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    } while (ch <= 4);

    return 0;
}
