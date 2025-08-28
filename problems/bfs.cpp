#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public: // Make bfsofGraph public
    vector<int> bfsofGraph(int V, vector<vector<int> >& adj) {
        vector<int> vis(V, 0); // Change to std::vector
        vis[0] = 1;
        queue<int> q;
        q.push(0);

        vector<int> bfs;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
      return bfs;
    }
};

int main() {
    int V = 5;
    vector<vector<int> > adj(V);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);
    Solution sol; // Create an instance of Solution
    vector<int> ans = sol.bfsofGraph(V, adj);
    for (auto it : ans) {
        cout << it << " ";
    }
    return 0;
}