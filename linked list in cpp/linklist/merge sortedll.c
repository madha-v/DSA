#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *create(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a new node at the end
struct node *insert(struct node *head, int data) {
    struct node *newnode = create(data);
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

struct node * mergesorted(struct node *head1 , struct node *head2)
{
    struct node *mergehead=NULL;
    if(head1==NULL &&head2==NULL)
    {
        printf("both the linked list are empty");
    }
    if(head1->data<head2->data)
    {
        mergehead=head1;
        head1=head1->next;
    }
    else
    {
        mergehead=head2;
        head2=head2->next;
    }
    
    struct node *curr=mergehead;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            curr->next=head1;
            head1=head1->next;
        }
        else
        {
            curr->next=head2;
            head2=head2->next;
        }
        curr=curr->next;
    }
    
    if(head1!=NULL)
    {
        curr->next=head1;
    }
    if(head2!=NULL)
    {
        curr->next=head2;
    }
    return mergehead;
    
    
}


// Function to display the linked list
void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct node *head1 = NULL;
      struct node *head2 = NULL;
      struct node *mergehead=NULL;
      int n,n1;
    int ch, data;

    do {
        printf("1 -- Insert, 2 -- mergesorted, 3 -- Display, 4 -- Exit ::-> ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
            printf("enter the number of elemnets in list 1::->");
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                printf("enter the data to be inserted ::->");
                scanf("%d",&data);
                head1=insert(head1, data);
                 display(head1);
            }
            
                printf("enter the number of elemnets in list 2::->");
            scanf("%d",&n1);
            for(int i=0;i<n1;i++)
            {
                printf("enter the data to be inserted ::->");
                scanf("%d",&data);
                head2=insert(head2, data);
                display(head2);
            }
            break;
 

            case 2:
                mergehead=mergesorted(head1, head2);
                printf("After merging in sorted order nodes::-> ");
                display(mergehead);
                break;

            case 3:
                printf("Linked List: ");
                display(mergehead);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (ch != 4);

    return 0;
}
