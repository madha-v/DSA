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

struct tree *successor(struct tree*root)
{
    while(root->left!=NULL)
    root=root->left;

    return root;
}

struct tree* delete (struct tree *root, int key)
{
    if(root==NULL)
    {
        return root;
    }

    if(key<root->data)
    {
        root->left=delete(root->left ,key);
    }
      else if(key>root->data)
    {
        root->right=delete(root->right ,key);
    }

    else{
        if(root->left==NULL)
        {
            struct tree* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct tree*temp=root->left;
            free(root);
            return temp;
        }
        struct tree* temp=successor(root->right);
        root->data=temp->data;
        root->right=delete(root->right , temp->data);

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


int main() {
    struct tree* root = NULL;


    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);


    printf("Original BST (in-order): ");
    inorder(root);
    printf("\n");

    int key;
    printf("enter the key to delete the data::-");
    scanf("%d", &key);

    
    delete(root, key);
    printf("After deleting  nodes: ");
    inorder(root);
    printf("\n");



 

    return 0;
}
