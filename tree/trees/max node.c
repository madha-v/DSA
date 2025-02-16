#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};


struct tree* create(int data) {
    struct tree* newnode = (struct tree*)malloc(sizeof(struct tree));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}


struct tree* insert(struct tree* root, int key) {
    if (root == NULL) {
        return create(key);
    }
    if (root->data == key) {
        return root;
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}


void inorder(struct tree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int max(struct tree*root)
{
    if(root==NULL)
    {
        return -1;
    }
    int leftmax=max(root->left);
    int rightmax=max(root->right);
    int max=root->data;
    if(leftmax>max)
    {
        max=leftmax;

    }
    if(rightmax>max)
    {
        max=rightmax;
    }
    return max;
   
}



int main() {
    struct tree* root = create(100);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 15);
    root = insert(root, 35);
    root = insert(root, 50);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    int Max = max(root);
    printf("Maximum element in the tree is: %d\n", Max);

    return 0;
}
