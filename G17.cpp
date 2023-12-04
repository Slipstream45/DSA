//topo sort DFS
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
    vis[node] = 1;
    for(int n : adj[node]){
        if(!vis[n]){
            dfs(n, vis, adj, st);
        }
    }
    st.push(node);
}
void dfsTopo(int n, vector<int> adj[]){
    stack<int> st;
    vector<int> vis(n, 0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i, vis, adj, st);
        }
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
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
    dfsTopo(n, adj);
}