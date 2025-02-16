// #include <stdio.h>
// #include <stdlib.h>

// struct tree {
//     int data;
//     struct tree* left;
//     struct tree* right;
// };


// struct tree* create(int data) {
//     struct tree* newnode = (struct tree*)malloc(sizeof(struct tree));
//     newnode->data = data;
//     newnode->left = newnode->right = NULL;
//     return newnode;
// }


// struct tree* insert(struct tree* root, int key) {
//     if (root == NULL) {
//         return create(key);
//     }
//     if (root->data == key) {
//         return root; 
//     }
//     if (key < root->data) {
//         root->left = insert(root->left, key);
//     } else {
//         root->right = insert(root->right, key);
//     }
//     return root;
// }


// void inorder(struct tree* root) {
//     if (root != NULL) {
//         inorder(root->left);
//         printf("%d ", root->data);
//         inorder(root->right);
//     }
// }

// int count(struct tree*root) // count leaf nodes
// {
//     int c;
//     if(root==NULL)
//     {
//         return 0;
//     }
//     int left=count(root->left);
//     int right=count(root->right);

//     if(root->left==NULL && root->right==NULL)
//     {
  
//       return 1;
//     }
//     int total=left+right;
//     return 1+total;
   
// }

// int main() {
//     struct tree* root = create(100);
//     root = insert(root, 40);
//     root = insert(root, 30);
//     root = insert(root, 50);
//     root = insert(root, 25);
//     root = insert(root, 20);
//     root = insert(root, 21);
//     root = insert(root, 24); 
//     root = insert(root, 60);
//     root = insert(root, 80);
//     root = insert(root, 81);
//     printf("Inorder Traversal: ");
//     inorder(root);
//     printf("\n");

//     int Count=count(root);
//     printf("number of leaf nodes in the tree is %d", Count);

//     return 0;
// }
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
    if (root->left == NULL && root->right == NULL) {
        return 1; 
    }
    
    int left=count(root->left);
     int right=count(root->right);
     int total=left+right;
     return total;
}

int main() {
    struct tree* root = create(100);
    root = insert(root, 50);
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

    int Count = count(root);
    printf("Number of leaf nodes in the tree is: %d\n", Count);

    return 0;
}
