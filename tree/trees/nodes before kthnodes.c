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
void knodes(struct tree*root , int key , int*count)
{
    if(root==NULL ||*count>key)
    {
        return ;
    }
    knodes(root->left, key , count);
  

    if(*count<key)
    {
        printf("%d " ,root->data);
          (*count)++;

    }
    knodes(root->right, key , count);
}


int main() {
    struct tree* root = NULL;

    
    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 60);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    int k;
    printf("enter the value of the k ::->");
    scanf("%d",&k);
    int count=0;
    printf("Nodes before the %dth node: ", k);

    knodes(root, k, &count);
   




    return 0;
}
