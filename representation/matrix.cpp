#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // Initialize an adjacency matrix for the graph with O(n) space
    int adj[n+1][m+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;

        //for weighted graph, we can store the weight instead of 1
        //adj[u][v] = weight;
        //adj[v][u] = weight; //for undirected graph
        //for directed graph, we would only add one direction
        // u ---> v
        // adj[u][v] = weight; only this if the graph is directed
        // v ---> u
        // adj[v][u] = weight; only this if the graph is directed
    }
    return 0;
}