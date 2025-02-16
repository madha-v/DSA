#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<limits.h>

// Define the structure for the BST nodes
struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};

// Function to create a new node
struct tree* create(int data) {
    struct tree* newnode = (struct tree*)malloc(sizeof(struct tree));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Function to insert a node into the BST
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

// Function to validate if a binary tree is a BST
bool isValidBST(struct tree* root, int min, int max) {
    if (root == NULL) {
        return true; // An empty tree is a valid BST
    }

    // Check if the current node violates the BST properties
    if (root->data <= min || root->data >= max) {
        return false;
    }

    // Recursively validate the left and right subtrees
    return isValidBST(root->left, min, root->data) &&
           isValidBST(root->right, root->data, max);
}

int main() {
    struct tree* root = NULL;

    // Create a BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Validate if the tree is a BST
    if (isValidBST(root, INT_MIN, INT_MAX)) {
        printf("The tree is a valid BST.\n");
    } else {
        printf("The tree is NOT a valid BST.\n");
    }

    return 0;
}
