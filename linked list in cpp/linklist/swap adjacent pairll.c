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


struct node* reverse(struct node *head) 
{
    if (head == NULL) {
        printf("Empty list or single node, cannot reverse\n");
        return head; 
    }

    struct node* curr = head;
    struct node* prev = NULL; 
    struct node* next = NULL; 

    head = head->next; 

    while (curr != NULL && curr->next != NULL) {
        next = curr->next->next; 
        curr->next->next = curr; 

        if (prev != NULL) {
            prev->next = curr->next; 
        }

        curr->next = next; 
        prev = curr; 
        curr = next; 
    }

    return head;
}

void append(struct node **head, int val) {
    struct node* newnode = create(val);

    if (*head == NULL) {
        *head = newnode;  
        return;
    }

    struct node* temp = *head;
    while (temp->next != NULL) {  
        temp = temp->next;
    }
    temp->next = newnode; 
}


void display(struct node* head) {
    if (head == NULL) {
        printf("The list is empty\n");
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
    int n, val;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the nodes of the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }

    printf("Original List: ");
    display(head);

    head = reverse(head); 

    printf("Reversed List in Pairs: ");
    display(head);

    return 0;
}
