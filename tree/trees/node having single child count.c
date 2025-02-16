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
int count(struct tree* root) {
    if (root == NULL) {
        return 0;
    }
    int left = count(root->left);
    int right = count(root->right);
    
    if ((root->left == NULL && root->right != NULL) || 
        (root->right == NULL && root->left != NULL)) {
        return 1 + left + right; // Add 1 for the current node
    }
    
    return left + right;
}


int main() {
    struct tree* root = create(100);
    root = insert(root, 40);
    root = insert(root, 30);
    // root = insert(root, 50);
    // root = insert(root, 35);
    // root = insert(root, 20);
    // root = insert(root, 21);
    // root = insert(root, 34); 
    root = insert(root, 60);
    root = insert(root, 80);
    //root = insert(root, 81);
    
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    int Count = count(root);
    printf("Number of  nodes having single child  in the tree is: %d\n", Count);

    return 0;
}
