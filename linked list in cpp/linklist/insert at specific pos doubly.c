#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node * prev;
};


struct node * create(int val) {
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev=NULL;
    return newnode;
}


struct node * insert(struct node * head, int val) {
    struct node * newnode = create(val);
    if (head == NULL) {
        return newnode;
    }
    struct node * temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev=NULL;
    return head;
}

struct node * insertbetween(struct node * head, int val1, int pos) {
    struct node * newnode = create(val1);
    

    if (pos == 1) {
        newnode->next = head;
        return newnode;
    }
    
    struct node * temp = head;
    

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
    newnode->prev=temp;
    
    return head;
}


void display(struct node * head) {
    if (head == NULL) {
        printf("The linked list is empty\n");
        return;
    }
    struct node * temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node * head = NULL;
    int ch, val, val1, pos;

    do {
        printf("1 -- Insert, 2 -- Insert Between, 3 -- Display, 4 -- Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
         
        switch(ch) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &val);
                head = insert(head, val);
                break;

            case 2:
                printf("Enter the data to insert between nodes: ");
                scanf("%d", &val1);
                printf("Enter the position to insert the data: ");
                scanf("%d", &pos);
                head = insertbetween(head, val1, pos);
                break;

            case 3:
                display(head);
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice made by the user\n");
                break;
        }
    } while (ch != 4);

    return 0;
}
