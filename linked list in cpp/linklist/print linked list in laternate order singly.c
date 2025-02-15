// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node *next;
// };

// struct node* create(int val) {
//     struct node* newnode = (struct node*)malloc(sizeof(struct node));
//     newnode->data = val;
//     newnode->next = NULL;
//     return newnode;
// }

// struct node* insert(struct node* head, int val) {
//     struct node* newnode = create(val);
//     if (head == NULL) {
//         return newnode;
//     }
//     struct node* t = head;
//     while (t->next != NULL) {
//         t = t->next;
//     }
//     t->next = newnode;
//     return head;
// }

// struct node*  displayAlternate(struct node* head) {
//     if (head == NULL) {
//         printf("The linked list is empty\n");
//         return;
//     }
//     struct node * t=head;
//     int c=0;
//     while(t!=NULL)
//     {
        
//         if(c%2==0)
//         {
        
//            head->next=t->next;
//            free(t);
//         }
//         t=t->next;

 
//         c++;
//     }
//     return head;
    
// }

// void display(struct node* head) {
//     if (head == NULL) {
//         printf("The linked list is empty\n");
//         return;
//     }
//     struct node* t = head;
//     while (t != NULL) {
//         printf("%d ", t->data);
//         t = t->next;
//     }
//     printf("\n");
// }

// int main() {
//     struct node* head = NULL;
//     int ch, val;

//     do {
//         printf("1-- Insert, 2-- Display, 3-- Display Alternate, 4-- Exit: ");
//         scanf("%d", &ch);
//         switch (ch) {
//             case 1:
//                 printf("Enter the value to be inserted: ");
//                 scanf("%d", &val);
//                 head = insert(head, val);
//                 break;

//             case 2:
//                 display(head);
//                 break;

//             case 3:
//                 printf("Linked list in alternate order: ");
//                 head=displayAlternate(head);
//                 display(head);
//                 break;

//             case 4:
//                 exit(0);
//                 break;

//             default:
//                 printf("Invalid choice\n");
//                 break;
//         }
//     } while (ch <= 4);

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
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

struct node* insert(struct node* head, int val) {
    struct node* newnode = create(val);
    if (head == NULL) {
        return newnode;
    }
    struct node* t = head;
    while (t->next != NULL) {
        t = t->next;
    }
    t->next = newnode;
    return head;
}

struct node* displayAlternate(struct node* head)
{
    if(head == NULL)
    
    
    
    
    
    {
        printf("The linked list is empty\n");
        return head;
    }

    struct node* current = head;
    struct node* temp;

    while (current != NULL && current->next != NULL) {
        temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    }

    return head;
}

void display(struct node* head) {
    if (head == NULL) {
        printf("The linked list is empty\n");
        return;
    }
    struct node* t = head;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int ch, val;

    do {
        printf("1-- Insert, 2-- Display, 3-- Delete Alternate Nodes and Display, 4-- Exit: ");
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
                printf("Deleting alternate nodes...\n");
                head = displayAlternate(head);
                display(head);
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

