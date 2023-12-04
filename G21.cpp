//eventual safe states - Kahn's algorithm
#include<bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(int n, vector<int> adj[]){
    vector<int> rev[n];
    vector<int> topo;
    vector<int> indegrees(n, 0);
    queue<int> q;

    for(int i=0;i<n;i++){
        for(auto it : adj[i]){
            rev[it].push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        for(auto it : rev[i]){
            indegrees[it]++;
        }
    }
    for(int i=0;i<n;i++){
        if(indegrees[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto n : rev[node]){
            indegrees[n]--;
            if(indegrees[n]==0){
                q.push(n);
            }
        }
    }
    sort(topo.begin(), topo.end());
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
    vector<int> safe_states = eventualSafeNodes(n, adj);
    for(auto n : safe_states){
        cout << n << " ";
    }
    return 0;
}