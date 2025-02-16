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
void oddeven(struct node *root)
{
    if(root!=NULL)
    {
        oddeven(root->left);
        if(root->data%2==0)
        {
            printf("even data:: %d->",root->data);
        }
        else{
            printf("odd data ::%d->",root->data);
        }
        oddeven(root->right);
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
    printf("odd and even numbers of the tree in are: ");
    oddeven(root);
    printf("\n");
    return 0;
}
