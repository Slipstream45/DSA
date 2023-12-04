#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); //comment this out if this is a directed graph.
    }

    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (u < v) {
                cout << u << " -- " << v << "\n";
            }
        }
    }
    return 0;
}