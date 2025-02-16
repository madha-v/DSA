// #include <stdio.h>
// #include <stdlib.h>

// // Node structure for adjacency list
// typedef struct node {
//     int v;
//     struct node* next;
// } node;

// // Function to create a new node
// node* createNode(int dest) {
//     node* newNode = (node*)malloc(sizeof(node));
//     newNode->v = dest;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to add an edge to the graph
// void add(node* adj[], int src, int dest) {
//     // Add edge src -> dest
//     node* newNode = createNode(dest);
//     newNode->next = adj[src];
//     adj[src] = newNode;

//     // Add edge dest -> src (for undirected graph)
//     newNode = createNode(src);
//     newNode->next = adj[dest];
//     adj[dest] = newNode;
// }

// // Recursive function for DFS
// void dfsRec(node* adj[], int src, int visited[]) {
//     visited[src] = 1;
//     printf("%d ", src);
//     node* temp = adj[src];
//     while (temp != NULL) {
//         if (!visited[temp->v]) {
//             dfsRec(adj, temp->v, visited);
//         }
//         temp = temp->next;
//     }
// }

// // Function to perform DFS traversal
// void dfs(node* adj[], int src, int V) {
//     int visited[V];
//     for (int i = 0; i < V; i++) {
//         visited[i] = 0; // Initialize visited array
//     }
//     printf("DFS traversal starting from vertex %d:\n", src);
//     dfsRec(adj, src, visited);
// }

// // Function to print the adjacency list of the graph
// void printGraph(node* adj[], int V) {
//     for (int i = 0; i < V; i++) {
//         printf("%d: ", i);
//         node* temp = adj[i];
//         while (temp != NULL) {
//             printf("%d -> ", temp->v);
//             temp = temp->next;
//         }
//         printf("NULL\n");
//     }
// }

// int main() {
//     int V, E;
//     printf("Enter the number of vertices and edges: ");
//     scanf("%d %d", &V, &E);

//     node* adj[V];
//     for (int i = 0; i < V; i++) {
//         adj[i] = NULL; // Initialize adjacency list
//     }

//     int src, dest;
//     for (int i = 0; i < E; i++) {
//         printf("Enter the source and destination (0 to %d): ", V - 1);
//         scanf("%d %d", &src, &dest);
//         if (src < 0 || src >= V || dest < 0 || dest >= V) {
//             printf("Invalid edge! Please enter valid vertices.\n");
//             i--; // Repeat the iteration for a valid edge
//         } else {
//             add(adj, src, dest);
//         }
//     }

//     printf("Adjacency list of the graph:\n");
//     printGraph(adj, V);

//     int start;
//     printf("Enter the starting vertex for DFS: ");
//     scanf("%d", &start);
//     if (start < 0 || start >= V) {
//         printf("Invalid starting vertex!\n");
//         return 1;
//     }

//     dfs(adj, start, V);

//     // Free allocated memory
//     for (int i = 0; i < V; i++) {
//         node* temp = adj[i];
//         while (temp != NULL) {
//             node* toFree = temp;
//             temp = temp->next;
//             free(toFree);
//         }
//     }

//     return 0;
// }
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

