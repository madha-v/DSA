#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};


struct node* create(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}


struct node* deleteNode(struct node *head, int pos) {
    if (head == NULL) {
        printf("The list is empty\n");
        return head;
    }

    struct node *temp = head;


    if (pos == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);  
        return head;
    }

    
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }


    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }


    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);  

    return head;
}


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
    int n, pos, val;

    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    
    printf("Enter the values of nodes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val); 
        append(&head, val);
    }

    
    printf("Nodes of the linked list: ");
    display(head);

    
    printf("Enter the position of the node to delete: ");
    scanf("%d", &pos);


    head = deleteNode(head, pos);


    printf("After deletion, the linked list will be: ");
    display(head);

    return 0;
}
