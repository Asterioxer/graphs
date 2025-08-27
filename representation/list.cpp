#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // Initialize an adjacency list for the graph with O(n) space, efficient for sparse graphs
    vector<int> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); //at u, v is a neighbor so store it
        adj[v].push_back(u); //at v, u is a neighbor so store it

        //for undirected graph, we add both directions
        //for directed graph, we would only add one direction
        // u ---> v
        // adj[u].push_back(v); only this if the graph is directed
        // v ---> u
        // adj[v].push_back(u); only this if the graph is directed
    }
    return 0;
}