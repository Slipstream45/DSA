//Distance of nearest cell having 1
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

void bfs(int sr, int sc, vector<vector<int>> grid, vector<vector<int>> &res, vector<vector<int>> &vis){
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    q.push({sr, sc});
    vis[sr][sc] = 1;

    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for(const auto &dir : directions){
            int nr = cr+dir.first;
            int nc = cr+dir.second;
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                vis[nr][nc]=1;
                res[nr][nc] = res[cr][cc] + 1;
                q.push({nr, nc});
            }
        }
    }
}

vector<vector<int>> distanceBFS(int n, int m, vector<vector<int>> &grid){
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> res(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]==0){
                bfs(i, j, grid, res, vis);
            }
        }
    }
    return res;

}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> result = distanceBFS(n, m, grid);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}