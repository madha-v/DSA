#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};


struct node* create(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev=NULL;
    return newnode;
}

struct node* reverse(struct node *head) {
    if (head == NULL) {
        printf("Empty list, cannot reverse\n");
        return NULL;
    }
    struct node* curr = head;
    struct node* prev = NULL;
    struct node* next = NULL;
    
    while (curr != NULL) {
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
       

    }
    return prev;
}


void append(struct node **head, int val) {
    struct node* newnode = create(val);
    
    if (*head == NULL) {
        *head = newnode;  
        return;
    }
    
    struct node* temp = *head;
    while (temp->next != NULL) {  
        temp = temp->next;
    }
    temp->next = newnode; 
    newnode->prev=temp; 
}


void display(struct node* head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int n, val;

    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    
    printf("Enter the nodes of the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }

    printf("Original List: ");
    display(head);

    head = reverse(head);

    printf("Reversed List: ");
    display(head);

    return 0;
}

/*
struct node* reverse(int val)
{
  if(head==NULL)
  {
  return NULL;
  }
  struct node* curr=head;
  struct node* temp=NULL;

  while(curr!=temp)
  {
  temp=curr->prev;
  curr->prev=curr->next;
  curr->next=temp;

  curr=curr->prev;
  }
  return temp;
}
*/
