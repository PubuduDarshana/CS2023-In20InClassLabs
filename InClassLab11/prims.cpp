#include <iostream>
#include <climits>

using namespace std;

#define V 6 // Number of vertices

int findMinKey(int key[], bool mstSet[]) {
    int minimumKey = INT_MAX;
    int minIdx;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < minimumKey) {
            minimumKey = key[v];
            minIdx = v;
        }
    }
    return minIdx;
}

void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    for (int v = 1; v < V; v++)
        cout << parent[v] << "-" << v << "\t" << graph[v][parent[v]] << "\n";
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    // Initializing all keys as infinite and mstSet as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1; // Start node has no parent

    for (int count = 0; count < V - 1; count++) {
        int u = findMinKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0 },
        {0, 2, 0, 3, 0, 5 },
        {0, 1, 3, 0, 5, 0 },
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0 }
    };

    primMST(graph);

    return 0;
}
