//Cycle detection in directed graph using Kahn's Algorithm
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isCyclic(int n, vector<int> adj[]){
    //vector<int> topo;
    int count = 0;
    vector<int> indegrees(n, 0);
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
        //topo.push_back(node);
        count++;
        q.pop();
        for(int n : adj[node]){
            indegrees[n]--;
            if(indegrees[n]==0){
                q.push(n);
            }
        }
    }
    return count != n;
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
    if(isCyclic(n, adj)){
        cout << "Graph is cyclic! \n";
    }else{
        cout << "Graph is DAG!\n";
    }
    return 0;
}