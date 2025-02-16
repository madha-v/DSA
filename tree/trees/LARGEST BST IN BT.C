// C Program to find Size of Largest
// BST in a Binary Tree
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Returns true if the given tree is BST, else false
int isValidBst(struct Node* root, int minValue, int maxValue) {
    if (!root)
        return 1;
    if (root->data >= maxValue || root->data <= minValue)
        return 0;
    return isValidBst(root->left, minValue, root->data) && 
           isValidBst(root->right, root->data, maxValue);
}

// Returns size of a tree
int size(struct Node* root) {
    if (!root)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

// Finds the size of the largest BST
int largestBst(struct Node* root) {
  
    // If tree is empty
    if (!root)
        return 0;
    
    // If whole tree is BST
    if (isValidBst(root, INT_MIN, INT_MAX)) 
        return size(root);
  
    // If whole tree is not BST
    return (largestBst(root->left) > largestBst(root->right)) 
           ? largestBst(root->left) 
           : largestBst(root->right);
}

struct Node* createNode(int value) {
    struct Node* node = 
      (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

int main() {
  
      // Constructed binary tree looks like this:
    //         50
    //       /    \
    //     75      45
    //    /
    //  40
    struct Node *root = createNode(50);
    root->left = createNode(75);
    root->right = createNode(45);
    root->left->left = createNode(40);

    printf("%d\n", largestBst(root));
    return 0;
}