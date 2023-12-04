//Cycle detection in Directed graph
#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node, vector<int> vis, vector<int> pathVis, vector<int> adj[]){
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto n : adj[node]){
        if(!vis[n]){
            if(dfs(n, vis, pathVis, adj)){
                return true;
            }
        }else if(pathVis[n]){
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}
bool isCyclic(int n, vector<int> adj[]){
    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);

    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(n, vis, pathVis, adj)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    if(isCyclic(n+1, adj)){
        cout << "Given directed graph is cyclic.\n";
    }else{
        cout << "Not cyclic.\n";
    }
    return 0;
}