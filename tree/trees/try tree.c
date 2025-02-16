#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left , *right;

};
struct node *create(int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
struct node *insert(struct node *root , int key)
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
        root->right=insert(root->right, key);
    }
    else{
        root->left=insert(root->left, key);
    }
    return root;
}

// struct node *insertbetween(struct node *parent, struct node *child ,int data , int pos)
// {
//     if(parent==NULL || child==NULL || pos<=0)
//     {
//         printf("invalid choice made by the user");
//     }
//     struct node *newnode=create(data);

//     if(pos=='L' || pos=='l')
//     {
//         parent->left=newnode;
//         newnode->left=child;
      
//     }
//     else if(pos=='R' || pos=='r')
//     {
//         parent->right=newnode;
//         newnode->right=child;

//     }
//     else{
//         printf("invalid choice");
//     }

// }
// void  findmax(struct node *root)
// {
//     if(root==NULL || root->left==NULL)
//     {
//         printf("invalid choice made by the user");
//     }
//     struct node *temp=root->left;
//     while(temp->right!=NULL)
//     {
//         temp=temp->right;
//     }
//     printf("%d ", temp->data);
// }

// void  findmax2(struct node *root)
// {
//     if(root==NULL || root->left==NULL)
//     {
//         printf("invalid choice made by the user");
//     }
//     struct node *temp=root->right;
//     while(temp->right!=NULL)
//     {
//         temp=temp->right;
//     }
//     printf("%d ", temp->data);
// }


// void  findmini(struct node *root)
// {
//     if(root==NULL || root->left==NULL)
//     {
//         printf("invalid choice made by the user");
//     }
//     struct node *temp=root->right;
//     while(temp->left!=NULL)
//     {
//         temp=temp->left;
//     }
//     printf("%d ", temp->data);
// }
inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int sum(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
     return root->data+sum(root->left)+sum(root->right);
   

}

int main()
{
    struct node *root=create(50);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,55);
    root=insert(root,60);
    printf("inorder traversal of the tree  root is ::->");
    inorder(root);
    printf("\n");
    // printf("inorder traversal of the left subtree  root is ::->");
    // inorder(root->left);
    // printf("\n");

    //  printf("inorder traversal of the right subtree  root is ::->");
    // inorder(root->right);
    // printf("\n");

    //  printf("inorder traversal of the tree  root is ::->");
    // inorder(root);
    // printf("\n");
//    printf("maximum element in the left subtree is::_>");
//     findmax(root);

//     printf("\n");
//     printf("maximum element in the right subtree is::_>");
//     findmax2(root);

//     printf("\n");
//     printf("minimum element in the right subtree is::_>");
//     findmini(root);
    // int data;
    // char pos;
    // printf("enter the data of the newnode to be inserted ::->");
    // scanf("%d", &data);
    // getchar();
    // printf("enter the position of the newnode to be inserted ::_>");
    // scanf("%c",&pos);

    // struct node *parent=root->left;
    // struct node *child=root->left->left;

    // insertbetween(parent, child, data,pos);

    
    // inorder(root);

    printf("sum of the all elements in the tree ::_>");
    int res=sum(root->left);
    printf("%d", res);


    return 0;

}