#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}


int isPrime(int num) {
    if (num <= 1) return 0; 
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; 
    }
    return 1;
}


TreeNode* successor(TreeNode* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root!=NULL) return NULL;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left!=NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right!=NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        } else {
            TreeNode* temp = successor(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}
TreeNode* deletePrimes(TreeNode* root) {
    if (!root) return NULL;

    root->left = deletePrimes(root->left);
    root->right = deletePrimes(root->right);

    if (isPrime(root->val)) {
        root = deleteNode(root, root->val);
    }
    return root;
}

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return createNode(val);
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}


void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}


int main() {
    TreeNode* root = NULL;

 
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 11);
    root = insert(root, 17);

    printf("Original BST (In-order): ");
    inorder(root);
    printf("\n");


    root = deletePrimes(root);

    printf("BST after deleting prime nodes (In-order): ");
    inorder(root);
    printf("\n");

    return 0;
}
