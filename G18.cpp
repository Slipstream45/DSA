//BFS Toposort (Kahn's Algorithm)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfsTopo(int n, vector<int> adj[]){
    vector<int> topo;
    vector<int> indegrees(n, 0);
    //finding indegrees of all nodes
    for(int i=0;i<n;i++){
        for(int n : adj[i]){
            indegrees[n]++;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegrees[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        topo.push_back(node);
        q.pop();
        for(int n : adj[node]){
            indegrees[n]--;
            if(indegrees[n]==0){
                q.push(n);
            }
        }
    }
    return topo;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> res = bfsTopo(n, adj);
    for(auto n : res){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}