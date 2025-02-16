#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int v;
    struct node *next;
}node;

struct node *create(int desti)
{
    struct node *newnode=(node *)malloc(sizeof(node));
    newnode->v=desti;
    newnode->next=NULL;
    return newnode;
}

void add(node *adj[], int src, int desti)
{
    struct node *newnode=create(desti);
    newnode->next=adj[src];
    adj[src]=newnode;
}

void bfs(node* adj[], int start, int vertex, int visited[]) {
   

    int queue[vertex], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal starting from vertex %d: ", start);

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        node* temp = adj[current];
        while (temp) {
            int dest = temp->v;
            if (!visited[dest]) {
                visited[dest] = 1;
                queue[rear++] = dest;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main()
{
    int v,e;
    printf("enter the number of the vertex and edges ::->");
    scanf("%d%d",&v,&e);

    node *adj[v];
    for(int i=0;i<v;i++)
    {
        adj[i]=NULL;
    }
    
    int visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
    }

   int start;
   printf("enter the straing vertex to traverse in tree using bfs ::->");
   scanf("%d",&start);
    int src, desti;
    for(int i=0;i<e;i++)
    {
        printf("enter the source and destination in the grapgh of the edges ::->");
        scanf("%d%d",&src,&desti);
        add(adj, src, desti);
    }

    printf("bfs traversal of the graph is ::_>");
    bfs(adj,start, 0, visited);
    return 0;

    

}