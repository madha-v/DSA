#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *create(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int key) {
    if (root == NULL) {
        return create(key);
    }
    if (key > root->data) {
        root->right = insert(root->right, key);
    } else if (key < root->data) {
        root->left = insert(root->left, key);
    }
    return root;
}

int isprime(int num) {
    if (num <= 1) return 0; 
    if (num == 2) return 1; 
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; 
        }
    }
    return 1; 
}
void isprimecheck(struct node *root)
{
    if(root!=NULL)
    {
        isprimecheck(root->left);
        if(isprime(root->data))
        {
            printf("%d",root->data);
        }
         isprimecheck(root->right);
    }

}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 5);
    root = insert(root, 4);
    printf("In-order traversal of the tree is: ");
    inorder(root);
    printf("\n");
    printf("Prime numbers in the tree are: ");
    isprimecheck(root);
    printf("\n");
    return 0;
}
