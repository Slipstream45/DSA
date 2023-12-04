//cycle detection in a graph
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool dfs(int src, int parent, vector<int> adj[], vector<int> &vis){
    vis[src] = 1;
    for(int n : adj[src]){
        if(!vis[n]){
            dfs(n, src, adj, vis);
        }else if(parent != n){
            return true;
        }
    }
    return false;

}
bool detectCycleDFS(int N, vector<int> adj[]){
    vector<int> vis = {N, 0};
    for(int i=0;i<N;i++){
        if(!vis[i]){
            if(dfs(i, -1, adj, vis)){
                return true;
            }
        }
    }
    return false;
}
bool bfs(int src, vector<int> adj[], vector<int> &vis){
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while(!q.empty()){
        int child = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto n : adj[child]){
            if(!vis[n]){
                vis[n] = 1;
                q.push({n, child});
            } else if(parent != n){
                return true;
            }
        }
    }
    return false;
}
bool detectCycleBFS(int N, vector<int> adj[]){
    vector<int> vis = {N, 0};
    for(int i=0;i<N;i++){
        if(!vis[i]){
            if(bfs(i, adj, vis)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << detectCycleBFS(n, adj) << endl;
    cout << detectCycleDFS(n, adj) << endl;
}