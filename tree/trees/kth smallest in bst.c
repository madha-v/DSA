#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree* left, * right;
};

// Function to create a new node
struct tree* create(int data) {
    struct tree* newnode = (struct tree*)malloc(sizeof(struct tree));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Function to insert a node in the binary search tree
struct tree* insert(struct tree* root, int key) {
    if (root == NULL) {
        return create(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

void oddeven(struct tree *root, struct tree **evenroot, struct tree **oddroot)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->data%2==0)
    {
        *evenroot=insert(*evenroot ,root->data);
    }
   else
    {
    *oddroot=insert(*oddroot,root->data);
    }
   oddeven(root->left,evenroot,oddroot);
   oddeven(root->right,evenroot,oddroot);
}  

// Inorder traversal of the tree
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

    printf("Inorder Traversal of Original Tree: ");
    inorder(root);
    printf("\n");

    // Initialize evenroot and oddroot
    struct tree* evenroot = NULL;
    struct tree* oddroot = NULL;

    // Split the tree into even and odd
    oddeven(root, &evenroot, &oddroot);

    // Print the even tree
    printf("Inorder Traversal of Even Tree: ");
    inorder(evenroot);
    printf("\n");

    // Print the odd tree
    printf("Inorder Traversal of Odd Tree: ");
    inorder(oddroot);
    printf("\n");

    return 0;
}
