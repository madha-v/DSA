#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree* createNode(int data) {
    struct tree* newnode = (struct tree*)malloc(sizeof(struct tree));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct tree* insertNode(struct tree* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void insertBetween(struct tree* parent, struct tree* child, int data, char pos) {
    if (parent == NULL) {
        printf("Invalid parent node.\n");
        return;
    }

    struct tree* newnode = createNode(data);

    if ((pos == 'L' || pos == 'l') && child == parent->left) {
        parent->left = newnode;
        newnode->left = child;
    } else if ((pos == 'R' || pos == 'r') && child == parent->right) {
        parent->right = newnode;
        newnode->right = child;
    } else {
        printf("Invalid child position for the selected parent.\n");
    }
}

void inorderTraversal(struct tree* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void freeTree(struct tree* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct tree* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 55);
    root = insertNode(root, 60);

    printf("Tree before insertion:\n");
    inorderTraversal(root);
    printf("\n");

    int data;
    char pos;
    printf("Enter the data to insert into the tree: ");
    scanf("%d", &data);
    getchar(); // Consume newline left in the buffer
    printf("Enter the position (L for left, R for right): ");
    scanf("%c", &pos);

    struct tree* parent = root->left;
    struct tree* child = parent ? parent->left : NULL;

    insertBetween(parent, child, data, pos);

    printf("Tree after insertion:\n");
    inorderTraversal(root);
    printf("\n");

    // Free the allocated memory
    freeTree(root);

    return 0;
}
