// #include<iostream>
// #include<vector>
// using namespace std;

// int main(){
//     int n, m;
//     cin >> n >> m;
//     vector<pair<int, int>> adj[n+1];

//     for(int i=0;i<n+1;i++){
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//     }

//     for(int u=0;u<n+1;u++){
//         cout << "Node " << u << " hs edges: \n";
//         for(auto edge : adj[u]){
//             int v = edge.first;
//             int w = edge.second;
//             cout << " -> " << v << " (Weight: " << w << ")\n";
//         }
//     }
//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n+1];

    for(int i=0;i<n+1;i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for(int u=1;u<n+1;u++){
        cout << "Node " << u << " has edges: \n";
        for(auto edge : adj[u]){
            int v = edge.first;
            int w = edge.second;
            cout << " -> " << v << " (Weight: " << w << ")\n";
        }
    }
    return 0;
}