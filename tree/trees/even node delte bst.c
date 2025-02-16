#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct node *insert(struct node *root ,int key)
{
    if(root==NULL)
    {
        return create(key);
    }
    if(key<root->data)
    {
        root->left=insert(root->left, key);
    }
    else
    {
        root->right=insert(root->right, key);
    }
    return root;
}

struct node * successor(struct node *root)
{
    if(root!=NULL &&root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

struct node *oddnodedelete(struct node *root)
{

    if(root==NULL)
    {
        return NULL;
    }
    root->left=oddnodedelete(root->left);
    root->right=oddnodedelete(root->right);
    if(root->data%2==0)
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
           else if(root->right==NULL && root->left!=NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp=successor(root->right);
            root->data=temp->data;
            root->right=oddnodedelete(root->right);
        }
     
    }
    return root;
}





void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);
    }
}
int main()
{
    struct node *root=NULL;
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
    root=insert(root, 100);
    
    inorder(root);
    printf("\n");

   root=oddnodedelete(root);
       printf("\n");
      inorder(root);

   


    
}