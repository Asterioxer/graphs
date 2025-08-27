#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;

int query(int start, vector<int>& locations) {
    cout << "? " << start;
    for (int loc : locations) {
        cout << " " << loc;
    }
    cout << endl;
    cout.flush();
    
    int result;
    cin >> result;
    return result;
}

void output_path(vector<int>& path) {
    cout << "!";
    for (int node : path) {
        cout << " " << node;
    }
    cout << endl;
    cout.flush();
}

vector<int> find_longest_path() {
    vector<int> best_path;
    int max_length = 0;
        for (int start = 1; start <= n; start++) {
        vector<int> all_except_start;
        for (int i = 1; i <= n; i++) {
            if (i != start) {
                all_except_start.push_back(i);
            }
        }
        
        if (!all_except_start.empty()) {
            int path_length = query(start, all_except_start);
            if (path_length > max_length) {
                max_length = path_length;
            }
        }
    }
    vector<int> current_best;
        for (int start = 1; start <= n; start++) {
        for (int next = 1; next <= n; next++) {
            if (next == start) continue;
            
            vector<int> locations = {next};
            int len = query(start, locations);
            
            if (len >= 2) {
                vector<int> path = {start, next};
                
                for (int third = 1; third <= n; third++) {
                    if (third == start || third == next) continue;
                    
                    vector<int> test_locations = {next, third};
                    int test_len = query(start, test_locations);
                    
                    if (test_len > len) {
                        path.push_back(third);
                        len = test_len;
                        break;
                    }
                }
                
                if (len > current_best.size()) {
                    current_best = path;
                }
            }
        }
    }
    
    return current_best;
}

void solve() {
    cin >> n;
    
    if (n == 1) {
        vector<int> path = {1};
        output_path(path);
        return;
    }
    vector<int> longest_path;
    int queries_used = 0;
    int max_queries = 2 * n;
    
    int best_length = 0;
    int best_start = 1;
    
    for (int start = 1; start <= n && queries_used < max_queries - 1; start++) {
        vector<int> all_others;
        for (int i = 1; i <= n; i++) {
            if (i != start) {
                all_others.push_back(i);
            }
        }
        
        int length = query(start, all_others);
        queries_used++;
        
        if (length > best_length) {
            best_length = length;
            best_start = start;
        }
    }
    longest_path.push_back(best_start);
    
    set<int> remaining;
    for (int i = 1; i <= n; i++) {
        if (i != best_start) {
            remaining.insert(i);
        }
    }
    while (!remaining.empty() && queries_used < max_queries) {
        int best_next = -1;
        int best_next_length = 0;
        
        for (int candidate : remaining) {
            if (queries_used >= max_queries) break;
            
            vector<int> test_path(remaining.begin(), remaining.end());
            test_path.erase(find(test_path.begin(), test_path.end(), candidate));
            
            if (!test_path.empty()) {
                int length_without = query(best_start, test_path);
                queries_used++;
                
                if (best_length - length_without > best_next_length) {
                    best_next_length = best_length - length_without;
                    best_next = candidate;
                }
            }
        }
        
        if (best_next != -1) {
            longest_path.push_back(best_next);
            remaining.erase(best_next);
        } else {
            break;
        }
    }
    if (longest_path.size() < best_length) {
        longest_path.clear();
        longest_path.push_back(best_start);
        for (int i = 1; i <= n && longest_path.size() < best_length; i++) {
            if (i != best_start) {
                longest_path.push_back(i);
            }
        }
    }
    
    output_path(longest_path);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}