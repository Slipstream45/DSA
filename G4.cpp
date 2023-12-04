#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> bfsTravel(int n, vector<int> adj[]){
    int vis[n+1] = {0};
    vis[1] = 1;

    queue<int> q;
    q.push(1);
    vector<int> nodes;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        nodes.push_back(node);

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return nodes;
}

void dfs(int node, vector<int> adj[], int vis[], vector<int> &nodes){
    vis[node] = 1;
    nodes.push_back(node);

    for(auto n : adj[node]){
        if(!vis[n]){
            dfs(n, adj, vis, nodes);
        }
    }
}

vector<int> dfsTravel(int n, vector<int> adj[]){
    int vis[n+1] = {0};
    vector<int> nodes;
    int start = 1;
    dfs(start, adj, vis, nodes);
    return nodes;
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

    vector<int> bfs = bfsTravel(n, adj);
    cout << "BFS\n";
    for(int nodes : bfs){
        cout << nodes << " ";
    }

    vector<int> dfs = dfsTravel(n, adj);
    cout << "\nDFS\n";
    for(int nodes : dfs){
        cout << nodes << " ";
    }

    return 0;
}

//Sample input:
// 9 9
// 1 2
// 1 6
// 2 3
// 2 4
// 4 5
// 5 8
// 7 8
// 7 9
// 7 6
//uncomment copy then comment again