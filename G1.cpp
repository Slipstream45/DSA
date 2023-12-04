#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int adj[n+1][m+1];

    for(int i=0;i<m+1;i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(adj[i][j]==1){
                cout << i << "--" << j << "\n";
            }
        }
    }
    return 0;
}