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

void splitList(struct node* head, struct node** firstHalf, struct node** secondHalf) {
    if (head == NULL) {
        *firstHalf = NULL;
        *secondHalf = NULL;
        return;
    }

    struct node* slow = head;
    struct node* fast = head->next;

    // Move `slow` one step and `fast` two steps
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Slow is now at the middle, split the list
    *firstHalf = head;              // First half starts from head
    *secondHalf = slow->next;       // Second half starts from the next of slow
    slow->next = NULL;              // Break the list into two halves
}

int main() {
    struct node* head = NULL;
    struct node* firstHalf = NULL;
    struct node* secondHalf = NULL;
    int val, ch;

    do {
        printf("1-- Insert, 2-- Display, 3-- Split, 4-- Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                head = insert(head, val);
                break;

            case 2:
                printf("Linked List: ");
                display(head);
                break;

            case 3:
                splitList(head, &firstHalf, &secondHalf);
                printf("First Half: ");
                display(firstHalf);
                printf("Second Half: ");
                display(secondHalf);
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
