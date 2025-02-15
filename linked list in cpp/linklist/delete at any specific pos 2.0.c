// #include<stdio.h>
// #include<stdlib.h>

// struct node {
//     int data;
//     struct node *next;
// };

// // Function to create a new node
// struct node * create(int val) {
//     struct node * newnode = (struct node*)malloc(sizeof(struct node));
//     newnode->data = val;
//     newnode->next = NULL;
//     return newnode;
// }


// struct node * insert(struct node * head, int val) {
//     struct node * newnode = create(val);
//     if (head == NULL) {
//         return newnode;
//     }
//     struct node * temp = head;
//     while (temp->next != NULL) {
//         temp = temp->next;
//     }
//     temp->next = newnode;
//     return head;
// }
// struct node * deleteAtPosition(struct node * head, int pos) {
//     if (head == NULL) {
//         printf("The list is empty\n");
//         return head;
//     }

//     struct node * temp = head;


//     if (pos == 1) {
//         head = head->next;
//         free(temp);
//         return head;
//     }

//     struct node * prev = NULL;
//     for (int i = 1; i < pos && temp != NULL; i++) {
//         prev = temp;
//         temp = temp->next;
//     }

    
//     if (temp == NULL) {
//         printf("Position is out of bounds\n");
//         return head;
//     }

    
//     prev->next = temp->next;
//     free(temp);
//     return head;
// }

// void display(struct node * head) {
//     if (head == NULL) {
//         printf("The linked list is empty\n");
//         return;
//     }
//     struct node * temp = head;
//     while (temp != NULL) {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

// int main() {
//     struct node * head = NULL;
//     int ch, val, val1, pos;

//     do {
//         printf("1 -- Insert, 2 -- Display, 3 -- Delete at Position, 4 -- Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &ch);
         
//         switch(ch) {
//             case 1:
//                 printf("Enter the data to insert: ");
//                 scanf("%d", &val);
//                 head = insert(head, val);
//                 break;

       

//             case 2:
//                 display(head);
//                 break;

//             case 3:
//                 printf("Enter the position to delete the node: ");
//                 scanf("%d", &pos);
//                 head = deleteAtPosition(head, pos);
//                 break;

//             case 4:
//                 exit(0);
//                 break;

//             default:
//                 printf("Invalid choice made by the user\n");
//                 break;
//         }
//     } while (ch != 4);

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *create(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a new node at the end of the list
struct node *insert(struct node *head, int data) {
    struct node *newnode = create(data);
    if (head == NULL) {
        // If the list is empty, return the new node as the head
        return newnode;
    }
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode; // Add the new node at the end
    return head;          // Return the unchanged head
}

void deletepos(struct node **head ,int pos)
{
    if(head==NULL)
    {
        printf("linked lsit is empty");
        return;
    }
    struct node *temp=*head;
    if(pos==1)
    {
        *head=temp->next;
        free(temp);
        return;
     }
     struct node *prev=NULL;
     for(int i=0;i<pos-1&&temp!=NULL;i++)
     {
         prev=temp;
         temp=temp->next;
     }
     if(temp!=NULL)
     {
         prev->next=temp->next;
         free(temp);
        
     }
}

void display(struct node *head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;

    // Creating the initial linked list
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);

    // Display the initial list
    display(head);
    
    int pos;
    printf("enter the data and psoition to delete in the linked list");
    scanf("%d",&pos);
    
    deletepos(&head , pos);
    display(head);

  
    return 0;
}
