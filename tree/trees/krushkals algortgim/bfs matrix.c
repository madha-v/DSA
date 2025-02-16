#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void bfs(int graph[MAX][MAX], int start, int vertex) {
    int queue[MAX];
    int front = 0, rear = 0;
    bool visited[MAX] = {false};

    visited[start] = true;
    queue[rear++] = start;

    printf("BFS Traversal starting from vertex %d: ", start);
    while (front < rear) {
        int current = queue[front++];
        printf("%d -> ", current);

        for (int i = 0; i < vertex; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("END\n");
}

int main() {
    int v, e, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    int graph[MAX][MAX] = {0};

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < e; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);

        if (src >= v || dest >= v || src < 0 || dest < 0) {
            printf("Invalid edge! Try again.\n");
            i--; // Reattempt edge input
        } else {
            graph[src][dest] = 1; // For directed graph
            graph[dest][src] = 1; // Uncomment for undirected graph
        }
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);

    if (start < 0 || start >= v) {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    bfs(graph, start, v);

    return 0;
}
