#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Function to create a new node
struct node* create(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a node at a specific position
struct node* insert(struct node *head, int pos, int val1) {
    struct node* newnode = create(val1);
    
    if (pos == 1) {
        newnode->next = head;
        if (head != NULL) {
            head->prev = newnode;
        }
        head = newnode;
        return head;
    }
    
    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    
    temp->next = newnode;
    return head;
}

// Function to append a node at the end of the list
void append(struct node **head, int val) {
    struct node *newnode = create(val);
    
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

// Function to display the linked list
void display(struct node *head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int n, pos, val, val1;

    // Input number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input values of nodes
    printf("Enter the values of nodes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);  // Removed the extra space from format specifier
        append(&head, val);
    }

    // Display the current linked list
    printf("Nodes of the linked list: ");
    display(head);

    // Insert a node at a specific position
    printf("Enter the position where you want to add the node: ");
    scanf("%d", &pos);

    printf("Enter the value you want to insert: ");
    scanf("%d", &val1);

    head = insert(head, pos, val1);

    // Display the linked list after insertion
    printf("After insertion, the linked list will be: ");
    display(head);

    return 0;
}
