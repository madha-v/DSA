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

struct tree* insert(struct tree* root, int data) {
    if (root == NULL) {
        return create(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void printalternate(struct tree*root , int * count)
{
    if(root==NULL )
    {
        return ;
    }
    printalternate(root->left, count);
    (*count)++;
    if((*count)%2!=0)
    {
        printf("%d->",root->data);
    }
    printalternate(root->right ,count);
}




void inorder(struct tree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d-> ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct tree* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Original BST (in-order): ");
    inorder(root);
    printf("\n");
    
    int count=0;
    
    printalternate(root , &count);



    return 0;
}
