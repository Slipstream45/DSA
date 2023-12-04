//flood-fill
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(int c, vector<vector<int>> &grid, vector<vector<int>> &vis, int sr, int sc, int target_colour){
    int n = grid.size(), m = grid[0].size();
    vis[sr][sc]=1;
    grid[sr][sc]=c;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    for(const auto &dir : directions){
        int n_row = sr + dir.first;
        int n_col = sc + dir.second;
        if(n_row>=0 && n_row<n && n_col>=0 && n_col<m && !vis[n_row][n_col] && grid[n_row][n_col]!=c && grid[n_row][n_col]==target_colour){
            dfs(c, grid, vis, n_row, n_col, target_colour);
        }
    }
}
void dfsFill(int c, vector<vector<int>> &grid, int sr, int sc, int target_colour){
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    if(!vis[sr][sc] && grid[sr][sc]!= c && grid[sr][sc]==target_colour){
        dfs(c, grid, vis, sr, sc, target_colour);
    }
}

void bfs(int row, int col, int c, vector<vector<int>> &vis, vector<vector<int>> &grid, int target_colour){
    int n = grid.size(), m = grid[0].size();
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = 1;
    grid[row][col] = c;

    while(!q.empty()){
        int c_row = q.front().first;
        int c_col = q.front().second;
        q.pop();
        for(const auto &dir : directions){
            int n_row = c_row + dir.first;
            int n_col = c_col + dir.second;
            if(n_row>=0 && n_row<n && n_col>=0 && n_col<m && !vis[n_row][n_col] && grid[n_row][n_col]!=c && grid[n_row][n_col]==target_colour){
                q.push({n_row, n_col});
                vis[n_row][n_col] = 1;
                grid[n_row][n_col] = c;
            }
        }
    }
}
void bfsFill(int c, vector<vector<int>> &grid, int sr, int sc, int target_colour){
    int n=grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    if(!vis[sr][sc] && grid[sr][sc]!=c && grid[sr][sc]==target_colour){
        bfs(sr, sc, c, vis, grid, target_colour);
    }
    
}
int main(){
    int n, m, c, sr, sc;
    cin >> n >> m >> sr >> sc >> c;
    vector<vector<int>> grid(n, vector<int>(m, -1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    int target_colour = grid[sr][sc];
    
    bfsFill(c, grid, sr, sc, target_colour);
    cout << "New grid is : \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Enter new starting co-ordinates and a colour: \n";
    int nr, nc, c2;
    cin >> nr >> nc >> c2;
    int tc2 = grid[nr][nc];
    dfsFill(c2, grid, nr, nc, tc2);
    cout << "New grid is : \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;

}