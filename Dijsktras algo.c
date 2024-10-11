#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Function to implement Dijkstra's single source shortest path algorithm
void dijkstra(const vector<vector<int>>& graph, int src) {
    int V = graph.size();
    vector<int> dist(V, numeric_limits<int>::max()); // Initialize distances to all vertices as infinite
    vector<bool> sptSet(V, false); // Track vertices included in the shortest path tree

    dist[src] = 0; // Distance from source to itself is 0

    // Min-heap priority queue to select the vertex with the minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); // Push the source vertex

    while (!pq.empty()) {
        int u = pq.top().second; // Get the vertex with the smallest distance
        pq.pop();
        sptSet[u] = true; // Mark it as processed

        // Traverse through all adjacent vertices of u
        for (int v = 0; v < V; ++v) {
            // Check for an edge and if the vertex is not yet included in the shortest path tree
            if (graph[u][v] && !sptSet[v] && dist[u] != numeric_limits<int>::max()) {
                // If the distance to v can be shortened
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v]; // Update distance
                    pq.push({dist[v], v}); // Push updated distance to priority queue
                }
            }
        }
    }

    // Print the constructed distance array
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << dist[i] << "\n";
    }
}

// Driver program to test the function
int main() {
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0); // Starting from vertex 0

    return 0;
}
