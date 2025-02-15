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

// struct node* reverse(struct node* head) {
//     struct node* prev = NULL;
//     struct node* current = head;
//     struct node* next = NULL;
    
//     while (current != NULL) {
//         next = current->next; 
//         current->next = prev; 
//         prev = current;       
//         current = next;      
//     }
//     return prev;
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
//         printf("1-- Insert, 2-- Display, 3-- Reverse, 4-- Exit: ");
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
//                 head = reverse(head);
//                 printf("Linked list reversed.\n");
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

// Define the structure for the linked list node
struct node {
    int data;        
    struct node *next; 
};

// Function to create a new node with the given value
struct node* create(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node)); 
    newnode->data = val; 
    newnode->next = NULL; 
    return newnode; 
}

// Function to insert a new node at the end of the list
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
    return head; // Return the updated head of the list
}

// Function to reverse the linked list
struct node* reverse(struct node* head) {
    struct node* prev = NULL; 
    struct node* current = head; 
    struct node* next = NULL; 
    
    while (current != NULL) {  // Traverse the list until current is NULL
        next = current->next;  // Store the next node
        current->next = prev;   // Reverse the direction of the current node
        prev = current;         // Move prev to the current node
        current = next;         // Move current to the next node
    }
    return prev; 
}

// Function to display the elements of the linked list
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
        // Display menu and get user choice
        printf("1-- Insert, 2-- Display, 3-- Reverse, 4-- Exit: ");
        scanf("%d", &ch); // Read the user's choice
        
        switch (ch) {
            case 1: // Insert a new node
                printf("Enter the value to be inserted: ");
                scanf("%d", &val); 
                head = insert(head, val); 
                break;

            case 2: // Display the linked list
                display(head); 
                break;

            case 3: // Reverse the linked list
                head = reverse(head); 
                printf("Linked list reversed.\n"); 
                break;

            case 4: // Exit the program
                exit(0); 

            default: // Handle invalid choices
                printf("Invalid choice\n");
                break;
        }
    } while (ch <= 4); // Loop back to the menu until the user chooses to exit

    return 0; 
}
