//Island counting problem

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
    vis[row][col] = 1;
    for(const auto &dir : directions){
        int nrow = row + dir.first;
        int ncol = col + dir.second;
        
        if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
            dfs(nrow, ncol, vis, grid);
        }
    }
}
int dfsIslands(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]=='1'){
                dfs(i, j, vis, grid);
                count ++;
            }
        }
    }
    return count;
}

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
    q.push({row, col});
    vis[row][col] = 1;

    while(!q.empty()){
        int currRow = q.front().first;
        int currCol = q.front().second;
        q.pop();
        
        for(const auto &dir : directions){
            int nrow = currRow + dir.first;
            int ncol = currCol + dir.second;

            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
}
int bfsIslands(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]=='1'){
                bfs(i, j, vis, grid);
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }

    cout << "Number of islands (BFS) " << bfsIslands(grid) << "\n";
    cout << "Number of islands (DFS) " << dfsIslands(grid) << "\n";

    return 0;
}