#include <stdio.h>
#include <stdlib.h>


typedef struct dl {
    int data;
    struct dl* prev;
    struct dl* next;
} dl;


dl* createNode(int data) {
    dl* newNode = (dl*)malloc(sizeof(dl));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void insertEnd(dl** head, dl** tail, int data) {
    dl* newNode = createNode(data);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}


void display(dl* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    dl* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void insertBetween(dl** head, dl** tail, int data) {
    if (*head == NULL || *tail == NULL || *head == *tail) {
        printf("Cannot insert between nodes in an empty or single-node list.\n");
        return;
    }
    
    dl* newNode = createNode(data);
    dl* secondNode = (*head)->next;
    
    (*head)->next = newNode;
    newNode->prev = *head;

    newNode->next = secondNode;
    secondNode->prev = newNode;
}


int main() {
    dl* head = NULL;
    dl* tail = NULL;
    int ch, data, data2;

    do {
        printf("\nMenu:\n");
        printf("1 -- Insert at end\n");
        printf("2 -- Display list\n");
        printf("3 -- Insert between first and second node\n");
        printf("4 -- Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertEnd(&head, &tail, data);
                break;
            
            case 2:
                display(head);
                break;
            
            case 3:
                if (head == NULL || tail == NULL || head == tail) {
                    printf("Insert at least two nodes before using this option.\n");
                } else {
                    printf("Enter the data to insert between first and second node: ");
                    scanf("%d", &data2);
                    insertBetween(&head, &tail, data2);
                }
                break;
            
            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(ch != 4);

    return 0;
}
