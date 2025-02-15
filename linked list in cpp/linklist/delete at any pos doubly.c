#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};


struct node * create(int val) {
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}


struct node* insert(struct node * head, int val) {
    struct node* newnode = create(val);
    if (head == NULL) {
        return newnode;
    }
    struct node * t = head;
    while (t->next != NULL) {
        t = t->next;
    }
    t->next = newnode;
    newnode->prev = t; 
    return head;
}


struct node * delete(struct node* head, int pos) {
    if (head == NULL) {
        printf("The list is empty\n");
        return head;
    }

    struct node * temp = head;

    
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
        printf("Position is out of bounds\n");
        return head;
    }

    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
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
    int ch, val, pos;

    do {
        printf("1 -- Insert, 2 -- Delete at Position, 3 -- Display, 4 -- Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
         
        switch(ch) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &val);
                head = insert(head, val);
                break;

            case 2:
                printf("Enter the position of the node to delete: ");
                scanf("%d", &pos);
                head = delete(head, pos);
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
