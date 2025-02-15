#include<stdio.h>
#include<stdlib.h>

typedef struct dl {
    int data;
    struct dl *prev;
    struct dl *next;
} dl;

void descin(dl** f, dl** r) {
    dl* p = (dl*)malloc(sizeof(dl));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the data for the node: ");
    scanf("%d", &p->data);  
    p->prev = p->next = NULL;

    
    if (*f == NULL && *r == NULL) {
        *f = *r = p;
    }
    
    else if (p->data > (*f)->data) {
        p->next = *f;
        (*f)->prev = p;
        *f = p;
    }
    
    else if (p->data < (*r)->data) {
        (*r)->next = p;
        p->prev = *r;
        *r = p;
    }
    else {
        dl* q = *f;
        while (q != NULL && q->data > p->data) {
            q = q->next;
        }
        p->next = q;
        p->prev = q->prev;
        if (q->prev != NULL) {
            q->prev->next = p;
        }
        q->prev = p;
    }
}

void display(dl* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    dl* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    dl* f = NULL, *r = NULL;
    int ch;

    do {
        printf("\n1 -- Insert in descending order\n2 -- Display\n3 -- Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                descin(&f, &r);
                break;
            case 2:
                display(f);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 3);

    return 0;
}
