//Bipartite graph
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool dfs(int node, int c, vector<int> adj[], vector<int> c_array){
    c_array[node] = c;
    for(int n : adj[node]){
        if(c_array[n]==-1){
            if(!dfs(n, 1-c, adj, c_array)){
                return false;
            }
        } else if(c_array[n]==c){
            return false;
        }
    }
    return true;
}
bool bipartiteDFS(int n, vector<int> adj[]){
    vector<int> c_array(n, -1);
    for(int i=0;i<n;i++){
        if(c_array[i]==-1 && !dfs(i, 0, adj, c_array)){
            return false;
        }
    }
    return true;
}
bool bipartiteBFS(int n, vector<int> adj[]){
    vector<int> c_array(n, -1);
    queue<int> q;
    q.push(1);
    c_array.push_back(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int n : adj[node]){
            if(c_array[n]==-1){
                q.push(n);
                c_array[n] = 1 - c_array[node];
            }else if(c_array[n] == c_array[node]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(bipartiteBFS(n+1, adj) && bipartiteDFS(n+1, adj)){
        cout << "Graph is bipartite.\n";
    }else{
        cout << "Graph is not bipartite.\n";
    }
    return 0;
}