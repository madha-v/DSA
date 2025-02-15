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

struct node* rotate(struct node* head, int k) {
    if (head == NULL || k == 0) {
        return head;
    }
    struct node * curr=head;
    int l=0;
    while(curr->next!=NULL)
    {
        curr=curr->next;
        l++;
    }
    curr->next=head;
    k=k%l;
    struct node * newtail=head;
    for(int i=1; i<l-k;i++)
    {
        newtail=newtail->next;

    }
    struct node * newhead=newtail->next;
    newtail->next=NULL;

    return newhead;


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
    int ch, val, k;

    do {
        printf("1-- Insert, 2-- Display, 3-- Rotate, 4-- Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                head = insert(head, val);
                break;

            case 2:
                display(head);
                break;

            case 3:
                printf("Enter the number of positions to rotate: ");
                scanf("%d", &k);
                head = rotate(head, k);
                printf("Linked list rotated by %d positions.\n", k);
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
