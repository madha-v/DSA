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
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

int count(struct tree*root) // count nodes sharing common shraing parents 
{
    if(root==NULL)
    {
       return 0;
    }
    int c=0;
    if(root->left!=NULL && root->right!=NULL)
    {
        c=1;
    }
    return c+count(root->left)+count(root->right);
}



void inorder(struct tree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
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
    root = insert(root, 80);
    root = insert(root, 81);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

  
   int res=count(root);
   printf("Total nodes hvaing common sharing parents in the tree: %d\n",res);
    

    return 0;
}
