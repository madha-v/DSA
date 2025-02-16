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

// Function to insert a node in the BST
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

// Function to find the minimum value node in a subtree
struct tree* findMin(struct tree* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete leaf nodes
struct tree* deleteLeafNodes(struct tree* root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }
    root->left = deleteLeafNodes(root->left);
    root->right = deleteLeafNodes(root->right);
    return root;
}

// Function to delete nodes with a single child
struct tree* deleteSingleChildNodes(struct tree* root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left == NULL && root->right != NULL) {
        struct tree* temp = root->right;
        free(root);
        return temp;
    }
    if (root->right == NULL && root->left != NULL) {
        struct tree* temp = root->left;
        free(root);
        return temp;
    }
    root->left = deleteSingleChildNodes(root->left);
    root->right = deleteSingleChildNodes(root->right);
    return root;
}

// Function to delete nodes with two children
struct tree* deleteTwoChildNodes(struct tree* root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left != NULL && root->right != NULL) {
        struct tree* temp = findMin(root->right); // Find in-order successor
        root->data = temp->data;
        root->right = deleteTwoChildNodes(root->right); // Delete the successor
    } else {
        root->left = deleteTwoChildNodes(root->left);
        root->right = deleteTwoChildNodes(root->right);
    }
    return root;
}

// In-order traversal function
void inorder(struct tree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Driver program
int main() {
    struct tree* root = NULL;

    // Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the original tree
    printf("Original BST (in-order): ");
    inorder(root);
    printf("\n");

    // Delete leaf nodes
    root = deleteLeafNodes(root);
    printf("After deleting leaf nodes: ");
    inorder(root);
    printf("\n");

    // Delete single-child nodes
    root = deleteSingleChildNodes(root);
    printf("After deleting single-child nodes: ");
    inorder(root);
    printf("\n");

    // Delete two-child nodes
    root = deleteTwoChildNodes(root);
    printf("After deleting two-child nodes: ");
    inorder(root);
    printf("\n");

    return 0;
}
