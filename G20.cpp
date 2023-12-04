//course scheduling prequisite problem
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool isPossible(int n, vector<pair<int, int>> &schedule){
    vector<int> adj[n];
    vector<int> indegrees(n, 0);
    queue<int> q;
    vector<int> topoSort;

    for(auto it : schedule){
        adj[it.first].push_back(it.second);
    }
    //check for indegrees
    for(int i=0;i<n;i++){
        for(auto n : adj[i]){
            indegrees[n]++;
        }
    }
    for(int i=0;i<n;i++){
        if(indegrees[i]==0){
            q.push(indegrees[i]);
        }
    }
    while(!q.empty()){
        int node = q.front();
        topoSort.push_back(node);
        q.pop();
        for(auto n : adj[node]){
            indegrees[n]--;
            if(indegrees[n]==0){
                q.push(n);
            }
        }
    }
    cout << "test!\n";
    if(topoSort.size()==n){
        return true;
    }
    return false;
    
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> schedule;
    for(int i =0;i<n;i++){
        int u, v;
        cin >> u >> v;
        schedule.push_back({u, v});
    }
    if(isPossible(n, schedule)){
        cout << "Not possible.\n";
    } else {
        cout << "Your phone linging!\n";
    }
    return 0;
}