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

struct node* count(struct node* head) {
    int c1 = 0, c2 = 0;
    struct node* t = head;
    while (t != NULL) {
        if (t->data % 2 == 0) {
            c1++;
        } else {
            c2++;
        }
        t = t->next;
    }
    printf("Even data count: %d\n", c1);
    printf("Odd data count: %d\n", c2);

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
        printf("1-- Insert, 2-- Count, 3-- Display, 4-- Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                head = insert(head, val);
                break;

            case 2:
                head = count(head);
                break;

            case 3:
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
