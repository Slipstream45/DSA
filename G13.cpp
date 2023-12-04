//Number of enclaves
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int enclaveBFS(vector<vector<int>> &grid){
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0 || i==n-1 || j==m-1){
                if(!vis[i][j] && grid[i][j]==1){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    }
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(const auto &dir : directions){
            int nr = row+dir.first;
            int nc = col+dir.second;
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                vis[nr][nc]=1;
                q.push({nr, nc});
            }
        }
    }
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]==1){
                count++;
            }
        }
    }
    return count;

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
    cout << "Number of enclaves: " << enclaveBFS(grid);
    return 0;
}