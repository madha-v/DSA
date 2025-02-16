#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree* left,*right;
};

struct tree*create(int data)
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
        return root;
    }
    if(root->data<key)
    {
        root->right=insert(root->right,key);

    }
    else{
        root->left=insert(root->left ,key);
    }
    return root;
}
struct tree*search(struct tree*root ,int key2)
{
    if(root==NULL || root->data==key2)
    {
        return root;
    }
    if(root->data<key2)
    {
        root->right=search(root->right , key2);
    }
    else{
        root->left=search(root->left ,key2);

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
int main()
{
    struct tree* root=create(10);
    root=insert(root ,1);
    root=insert(root ,2);
    root=insert(root ,3);
    root=insert(root ,4);
    root=insert(root ,5);
    printf(" inorder traversal is ::->");
    inorder(root);
    printf("\n");

    struct tree* res=search(root ,5);
    if(res!=NULL)
    {
        printf("key %d if found in the bst " , root->data);
    }
    else{
        printf("key is not found in the data");
    }
    return 0;
}