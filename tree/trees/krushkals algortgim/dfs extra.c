#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the adjacency list
typedef struct node {
    int vertex;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(Node* adjList[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // Uncomment the following lines for an undirected graph
    // newNode = createNode(src);
    // newNode->next = adjList[dest];
    // adjList[dest] = newNode;
}

// Recursive function for DFS
void dfs(Node* adjList[], int visited[], int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = adjList[vertex];
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) {
            dfs(adjList, visited, connectedVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Create an array of adjacency lists
    Node* adjList[vertices];
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
    }

    // Input edges
    int src, dest;
    for (int i = 0; i < edges; i++) {
        printf("Enter source and destination: ");
        scanf("%d %d", &src, &dest);
        addEdge(adjList, src, dest);
    }

    // Initialize visited array
    int visited[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    // Perform DFS from vertex 0 (or any starting vertex)
    printf("DFS Traversal starting from vertex 0:\n");
    dfs(adjList, visited, 0);

    // Free allocated memory
    for (int i = 0; i < vertices; i++) {
        Node* temp = adjList[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }

    return 0;
}
