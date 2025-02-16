#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
# define max 100
struct node{
    int vertex;
    struct node *next;
};
struct node *create(int vertex)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->vertex=vertex;
    newnode->next=NULL;
    return newnode;
}
void dfs(struct node *graph[max], int vertex , bool visited[max])
{

    visited[vertex]=true;
    printf("%d->",vertex);
    struct node *temp=graph[vertex];
    while(temp)
    {
        int desti=temp->vertex;
        if(!visited[desti])
        {
            dfs(graph,desti,visited);
        }
        temp=temp->next;
    }
    


    
}
int main()
{
    int v, e, start;
    printf("enter the vertex and edges  of the graph ::-> ");
    scanf("%d%d",&v,&e);
    struct node *graph[max]={NULL};
    for(int i=0;i<e;i++)
    {
        int src, desti;
        printf("Enter the source and destination of the graph ::->");
        scanf("%d%d",&src,&desti);
        if(src>=v|| desti>=v|| src<0 || desti<0)
        {
            printf("invalid choice made by the user");
            i--;
        }
        else
        {
            struct node *newnode=create(desti);
            newnode->next=graph[src];
            graph[src]=newnode;
            
        }
    }
  printf("enter the starting element of the graph::->");
  scanf("%d",&start);
  bool visited[max]={false};
  dfs(graph,start,visited);
  return 0;
}