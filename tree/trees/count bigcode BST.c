#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree*left , *right;
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

int count(struct tree*root) // to count total nodes
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+count(root->left)+count(root->right);
}

int count1(struct tree*root) // nodes having single child 
{
    if(root==NULL)
    {
        return 0;
    }
    int left=count1(root->left);
     int right=count1(root->right);
    if((root->left==NULL && root->right!=NULL)|| (root->right==NULL &&root->left!=NULL))
    {
         return 1+count1(root->left)+count1(root->right);

    }
    return left+right;

}

int count2(struct tree*root) // leaf nodes
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    return count2(root->left)+count2(root->right);
}


void inorder(struct tree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
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

    int res=count(root);
    printf("number of total nodes in the tree is %d ",res);
    printf("\n");

    int res1=count1(root);
    printf("number of total nodes having single children in the tree is %d ",res1);


    printf("\n");
      int res2=count2(root);
    printf("number of leaf nodesin the tree is %d ",res2);


}