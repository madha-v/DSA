#include <stdio.h>
#include <stdlib.h>

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
struct tree* insert(struct tree* root, int key) {
    if (root == NULL) {
        return create(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to perform inorder traversal
void inorder(struct tree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to count the number of nodes in a subtree
int count(struct tree* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

// Function to print all nodes in a subtree
void subtree(struct tree* root) {
    if (root == NULL) {
        return;
    }
    subtree(root->left);
    printf("%d ", root->data);
    subtree(root->right);
}

int main() {
    struct tree* root = create(10);
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 35);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 34);
    root = insert(root, 60);

    printf("Inorder Traversal of the Entire Tree: ");
    inorder(root);
    printf("\n");

    // Counting nodes in the left and right subtrees
    int leftCount = count(root->left);
    int rightCount = count(root->right);

    // Printing left subtree
    printf("Left Subtree Nodes: ");
    subtree(root->left);
    printf("\nNumber of nodes in the left subtree: %d\n", leftCount);

    // Printing right subtree
    printf("Right Subtree Nodes: ");
    subtree(root->right);
    printf("\nNumber of nodes in the right subtree: %d\n", rightCount);

    return 0;
}
