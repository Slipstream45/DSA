#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[]){
    vis[node] = 1;
    for(auto n : adj[node]){
        if(!vis[n]){
            dfs(n, adj, vis);
        }
    }
}

int countProvincesDFS(int n, vector<int> adj[]){
    int vis[n] = {0};
    int countDFS = 0;
    
    for(int i=0;i<n+1;i++){
        if(!vis[i]){
            dfs(i, adj, vis);
            countDFS++;
        }
    }
    return countDFS;
}
void bfs(int n, vector<int> adj[], int vis[]){
    queue<int> q;
    q.push(n);
    vis[n] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i : adj[curr]){
            if(!vis[i]){
                q.push(i);
                vis[i] = 1;
            }
        }
    }
}
int countProvincesBFS(int n, vector<int> adj[]){
    int vis[n] = {0};
    int countBFS = 0;
    for(int i=0;i<n;i++){
        bfs(i, adj, vis);
        countBFS++;
    }
    return countBFS;
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
    int countDFS = countProvincesDFS(n, adj);
    cout << "The number of provinces is: " << countDFS << "\n";
    int countBFS = countProvincesBFS(n, adj);
    cout << "The number of provinces is: " << countBFS << "\n";
    return 0;
}