#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree* left, *right;
};

struct tree* create(int data)
{
    struct tree* newnode=(struct tree*)malloc(sizeof(struct tree));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;

}

struct tree*insert(struct tree* root , int key)
{
    if(root==NULL)
    {
        return create(key);
    }
    if(root->data==key)
    {
        return root ;
    }
    if(root->data<key)
    {
        root->right=insert(root->right, key);
    }
    else{
        root->left=insert(root->left, key);
    }
    return root;
}

void inorder(struct tree*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct tree*root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

void postorder(struct tree*root)
{
    if(root!=NULL)
    {
        
        inorder(root->left);
        inorder(root->right);
        printf("%d ",root->data);
    }
}

int main()
{
    struct tree* root=create(40);
    root=insert(root, 10);
     root=insert(root ,20);
    root=insert(root ,30);
    root=insert(root ,50);
     root=insert(root ,60);
       root=insert(root ,70);
        printf("inorder traversal is ::->");
        inorder(root);
        printf("\n");
       printf("preorder traversal is ::->");
       preorder(root);
        printf("\n");

        printf("postorder traversal is ::->");
        postorder(root);
        printf("\n");
        return 0;
}