#include<stdio.h>
#include<stdlib.h>


typedef struct dlist {
    int data;
    struct dlist *prev;
    struct dlist *next;
} dl;


dl* insert(dl *r) {
    dl *p = (dl*)malloc(sizeof(dl));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return r;
    }


    printf("Enter the data: ");
    scanf("%d", &p->data);
    

    if (r == NULL) {
        p->prev = NULL;
        p->next = NULL;
        r = p;
    } else {
        r->next = p;
        p->prev = r;
        p->next = NULL;
        r = p;
    }

    return r; 
}


dl* delete(dl* f) {
    dl *p = NULL;


    if (f == NULL) {
        printf("List is empty.\n");
        return NULL;
    }


    p = f;
    printf("Deleted node with data: %d\n", f->data);


    f = f->next;
    if (f != NULL) {
        f->prev = NULL;
    }

    free(p);  
    return f;  
}


void display(dl* f) {
    dl* temp = f;


    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Current List: ");
    while (temp != NULL) {
        printf("%d ", temp->data); 
        temp = temp->next;       
    }
    printf("\n");
}

int main() {
    dl *f = NULL, *r = NULL;
    int ch;

    do {
        printf("\nEnter your choice: 1--Insert, 2--Delete, 3--Display, 4--Exit: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                r = insert(r);  
                if (f == NULL) {
                    f = r; 
                }
                break;

            case 2:
                f = delete(f); 
                if (f == NULL) {
                    r = NULL;
                }
                break;

            case 3:
                display(f); 
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (ch != 4);

    return 0;
}
