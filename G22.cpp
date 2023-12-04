//Alien dictionary
#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n, vector<int> adj[]){
    vector<int> indegrees(n, 0);
    queue<int> q;
    vector<int> topo;
    for(int i=0;i<n;i++){
        for(auto n : adj[i]){
            indegrees[n]++;
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
        for(auto n : adj[node]){
            indegrees[n]--;
            if(indegrees[n]==0){
                q.push(n);
            }
        }
    }
    return topo;
}
string findOrder(string dict[], int n, int k){
    vector<int> adj[k];
    for(int i=0;i<n-1;i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.size(), s2.size());    //whichever length is shorter
        for(int ptr=0;ptr<len;ptr++){
            if(s1[ptr]!=s2[ptr]){
                adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');    //make graph
                break;
            }
        }
    }
    vector<int> topo = topoSort(k, adj);
    string ans = "";
    for(auto it : topo){
        ans += char(it + 'a');
    }
    return ans;
}
int main(){
    int n, k;
    cin >> n >> k;
    string dict[n];
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        dict[i] = s;
    }
    string res = findOrder(dict, n, k);
    cout << res << "\n";
    return 0;

}