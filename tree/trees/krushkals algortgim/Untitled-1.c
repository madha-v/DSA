#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}


void addEdge(Node* graph[MAX], int src, int dest) {
   
    Node* newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;

  
}

void bfs(Node* graph[MAX], int V, int start) {
    int queue[MAX];
    int front = 0, rear = 0;
    bool visited[MAX] = {false};

    visited[start] = true;
    queue[rear++] = start;

    printf("BFS Traversal starting from vertex %d:\n", start);

    while (front < rear) {
        int j = queue[front++];
        printf("%d ", j);

        Node* temp = graph[j];
        while (temp) {
            int i = temp->vertex;
            if (!visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void printGraph(Node* graph[MAX], int V) {
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: ", i);
        Node* temp = graph[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int V, E, choice, start;
    Node* graph[MAX] = {NULL};

    do {
        printf("\nMenu:\n");
        printf("1. Add edges to the graph\n");
        printf("2. Perform BFS\n");
        printf("3. Print adjacency list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               
                printf("Enter number of vertices: ");
                scanf("%d", &V);
                printf("Enter number of edges: ");
                scanf("%d", &E);

                printf("Enter edges (source destination):\n");
                for (int i = 0; i < E; i++) {
                    int src, dest;
                    scanf("%d %d", &src, &dest);
                    addEdge(graph, src, dest);
                 }
                break;

            case 2:
               
            printf("Enter the starting vertex for BFS: ");
            scanf("%d", &start);
            bfs(graph, V, start);
               
                break;

            case 3:
                
            printGraph(graph, V);
             ;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice made by the user");
                break;
        }
    } while (choice != 4);

    return 0;
}

