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

// Function to insert a new node into the binary tree
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

// Function to count total nodes, nodes with a single child, and leaf nodes
void countNodes(struct tree* root, int* totalNodes, int* singleChildNodes, int* leafNodes) {
    if (root == NULL) {
        return;
    }

    // Increment total nodes
    (*totalNodes)++;

    if (root->left == NULL && root->right == NULL) {
        // Leaf node
        (*leafNodes)++;
    } else if ((root->left == NULL && root->right != NULL) || (root->right == NULL && root->left != NULL)) {
        // Node with a single child
        (*singleChildNodes)++;
    }

    // Recurse for left and right subtrees
    countNodes(root->left, totalNodes, singleChildNodes, leafNodes);
    countNodes(root->right, totalNodes, singleChildNodes, leafNodes);
}

// Inorder traversal for displaying the tree
void inorder(struct tree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct tree* root = create(100);
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 35);
    root = insert(root, 20);
    root = insert(root, 21);
    root = insert(root, 34);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 81);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    int totalNodes = 0, singleChildNodes = 0, leafNodes = 0;

    // Count all types of nodes
    countNodes(root, &totalNodes, &singleChildNodes, &leafNodes);

    printf("Total nodes in the tree: %d\n", totalNodes);
    printf("Nodes with a single child: %d\n", singleChildNodes);
    printf("Leaf nodes: %d\n", leafNodes);

    return 0;
}
