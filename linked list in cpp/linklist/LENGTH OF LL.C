#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;          
    struct Node* next; 
};


int findLength(struct Node* head)
{
    
    int length = 0;

    
    struct Node* curr = head;

    
    while (curr != NULL) {
        length++;
        curr = curr->next;
    }


    return length;
}


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    struct Node* head = NULL;
    head=createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    
    int length = findLength(head);
    printf("The length of the linked list is: %d\n", length);

    return 0;
}
