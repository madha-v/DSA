#include <stdio.h>
#include <stdbool.h>

#define max 100

// BFS Function
void bfs(int graph[max][max], int V, int start) {
    int queue[max]; // Array to hold the queue elements
    int front = 0, rear = 0;
    bool visited[max] = {false};  // Initialize visited array to false (not visited)
    visited[start] = true;        // Mark the start vertex as visited
    queue[rear++] = start;        // Add the starting vertex to the queue
    
    printf("BREADTH FIRST SEARCH starting from vertex %d:\n", start);
    
    // Process the queue
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);  // Print the current vertex
        
        // Visit all the unvisited neighbors of the current vertex
        for (int i = 0; i < V; i++) {
            if (graph[curr][i] == 1 && !visited[i]) {  // Check for unvisited neighbor
                visited[i] = true;  // Mark the neighbor as visited
                queue[rear++] = i;  // Add it to the queue
            }
        }
    }
    printf("\n");
}

// Main function with menu-driven options
int main() {
    int V = 0, choice, start;
    int graph[max][max];  // Declare adjacency matrix
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enter the adjacency matrix\n");
        printf("2. Perform BFS\n");
        printf("3. Exit\n");
        
        // Read user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Enter adjacency matrix
                printf("Enter number of vertices: ");
                scanf("%d", &V);
                
                if (V <= 0 || V > max) {
                    printf("Error: Number of vertices should be between 1 and %d.\n", max);
                    V = 0; // Reset V to indicate invalid input
                    break;
                }
                
                printf("Enter the adjacency matrix (0 or 1 for each pair of vertices):\n");
                // Read the adjacency matrix from the user
                for (int i = 0; i < V; i++) {
                    for (int j = 0; j < V; j++) {
                        scanf("%d", &graph[i][j]);
                        if (graph[i][j] != 0 && graph[i][j] != 1) {
                            printf("Error: Invalid input. Please enter 0 or 1 only.\n");
                            i = j = V; // Exit the loops
                        }
                    }
                }
                break;
                
            case 2:
                // Perform BFS
                if (V > 0) {  // Check if the adjacency matrix has been entered
                    printf("Enter the starting vertex for BFS: ");
                    scanf("%d", &start);
                    
                    if (start < 0 || start >= V) {
                        printf("Error: Starting vertex should be between 0 and %d.\n", V - 1);
                    } else {
                        bfs(graph, V, start);
                    }
                } else {
                    printf("Error: Please enter the adjacency matrix first!\n");
                }
                break;
                
            case 3:
                // Exit the program
                printf("Exiting the program.\n");
                return 0;
                
            default:
                // Invalid choice
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
