//shortest path in DAG
//need to fix
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> adj[]){
    vis[node] = 1;
    for(auto n : adj[node]){
        int v = n.first;
        int w = n.second;
        if(!vis[v]){
            dfs(v, vis, st, adj);
        }
    }
    st.push(node);
}
vector<int> compute(int n, vector<pair<int, int>> adj[]){
    stack<int> st;
    vector<int> vis(n, 0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i, vis, st, adj);
        }
    }
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();

            for(auto it : adj[node]){
                int v = it.first;
                int w = it.second;

                if(dist[node] + w < dist[v]){
                    dist[v] = dist[node]+w;
                }
            }
    }
    return dist;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<int> s_path = compute(n, adj);
    for(auto n : s_path){
        cout << n << " ";
    }
}