#include<stdio.h>
#include<stdlib.h>


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


struct node* insertbetween(struct node* head, int pos, int val1) {
    struct node* newnode = create(val1);
    if (pos == 1) {
        newnode->next = head;
        return newnode; 
    }
    
    struct node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position is out of bounds\n");
        free(newnode);
        return head;
    }
    
    newnode->next = temp->next;
    temp->next = newnode;
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
    int ch, val, val1, pos;

    do {
        printf("1-- Insert, 2-- Insert between, 3-- Display, 4-- Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                head = insert(head, val);
                break;

            case 2:
                printf("Enter the position to insert the node and value: ");
                scanf("%d %d", &pos, &val1);
                head = insertbetween(head, pos, val1);
                break;

            case 3:
                display(head);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 4);

    return 0;
}
