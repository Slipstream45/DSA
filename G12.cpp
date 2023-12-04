//Replace O's with X on a grid
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis){
    vis[row][col] = 1;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for(const auto &dir : directions){
        int nr = row+dir.first;
        int nc = col+dir.second;

        if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !vis[nr][nc] && grid[nr][nc] == 'O'){
            dfs(nr,nc, grid, vis);
        }
    }
}
vector<vector<char>> replaceDFS(vector<vector<char>> &grid){
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        if(grid[i][0]=='O' && !vis[i][0]){  //left-most col
            dfs(i, 0, grid, vis);
        }
        if(grid[i][m-1]=='O' && !vis[i][m-1]){  //right-most col
            dfs(i, m-1, grid, vis);
        }
    }
    for(int j=0;j<m;j++){
        if(grid[0][j]=='O' && !vis[0][j]){  //upper-most row
            dfs(0, j, grid, vis);
        }
        if(grid[n-1][j]=='O' && !vis[n-1][j]){  //bottom-most row
            dfs(n-1, j, grid, vis);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]=='O'){
                grid[i][j]='X';
            }
        }
    }
    return grid;
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
    cout << "++++++++++++++\n";
    vector<vector<char>> res = replaceDFS(grid);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
