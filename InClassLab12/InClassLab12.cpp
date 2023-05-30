#include <iostream>
#include <climits>

using namespace std;

#define V 6 // Number of vertices
#define INFINITY 9999

int minTime(int time[], bool visited[]) {
    int min = INFINITY;
    int min_city;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && time[v] <= min) {
            min = time[v];
            min_city = v;
        }
    }

    return min_city;
}

void dijkstra(int graph[V][V], int source) {
    int time[V]; // shortest time from source to each city is stored in this array.
    bool visited[V]; // visted cities are marked as True.

    for (int i = 0; i < V; i++) {
        time[i] = INFINITY; // all the starting times are initialized as infinity.
        visited[i] = false; // all the cities are marked as unvisited at the start.
    }
    
    time[source] = 0; // There is no time spent from source to itself.


    for (int j = 0; j < V - 1; j++) {

        int u = minTime(time, visited);

        visited[u] = true; //visited citys are marked as true.

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && time[u] != INFINITY && time[u] + graph[u][v] < time[v]) {
                time[v] = time[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest time from city "<< source << ":\n";
    for (int i = 0; i < V; i++) {
        cout  <<" to city " << i <<" is " << time[i] << "\n";
    }
}

int main() {

    int graph[V][V] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int source = 0;

    dijkstra(graph, source);

    return 0;
}