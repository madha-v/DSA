#include <iostream>
#include <vector>
#include <algorithm> // For sorting
using namespace std;

// Function to initialize the disjoint set
void makeset(vector<int>& parent, vector<int>& rank, int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

// Function to find the parent of a node (with path compression)
int findparent(vector<int>& parent, int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findparent(parent, parent[node]);
}

// Function to unite two sets
void unionset(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findparent(parent, u);
    v = findparent(parent, v);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[v] < rank[u]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

// Function to calculate the minimal spanning tree using Kruskal's algorithm
int minimalspantree(vector<vector<int>>& edges, int n) {
    vector<int> parent, rank;
    makeset(parent, rank, n);

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    });

    int minweight = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        if (findparent(parent, u) != findparent(parent, v)) {
            minweight += wt;
            unionset(u, v, parent, rank);
        }
    }
    return minweight;
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> edges = {
        {0, 1, 10}, // {node1, node2, weight}
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    cout << "Minimal Spanning Tree weight: " << minimalspantree(edges, n) << endl;

    return 0;
}
