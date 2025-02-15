#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct node {
    int data;
    struct node *next;
};


struct node *create(int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}


struct node *insert(struct node *head, int val) {
    struct node *newnode = create(val);
    if (head == NULL) {
        return newnode;
    }
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}


int isPrime(int num) {
    if (num < 2) {
        return 0; 
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; 
        }
    }
    return 1; 
}


struct node *prime(struct node *head) {
    int primeCount = 0, nonPrimeCount = 0;
    struct node *t = head;
    while (t != NULL) {
        if (isPrime(t->data)) {
            primeCount++;
        } else {
            nonPrimeCount++;
        }
        t = t->next; 
    }
    printf("Total prime nodes: %d\n", primeCount);
    printf("Total non-prime nodes: %d\n", nonPrimeCount);
    return head;
}


void display(struct node *head) {
    if (head == NULL) {
        printf("The linked list is empty\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    int ch, val;

    do {
        printf("1 -- Insert\n2 -- Display\n3 -- Count Prime and Non-Prime\n4 -- Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
         
        switch(ch) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &val);
                head = insert(head, val);
                break;
            case 2:
                display(head);
                break;
            case 3:
                head = prime(head);
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
