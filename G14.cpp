//Number of distinct islands
#include<iostream>
#include<vector>
#include<set>
using namespace std;

void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int row0, int col0){
    int n = grid.size(), m = grid[0].size();
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vis[row][col] = 1;
    vec.push_back({row-row0, col-col0});


    for(const auto &dir : directions){
        int r = row+dir.first;
        int c = col+dir.second;
        if(r<n && r>=0 && c<m && c>=0 && grid[r][c]==1 && !vis[r][c]){
            dfs(r, c, vis, grid, vec, row0, col0);
        }
    }

}
int countDFS(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]==1){
                vector<pair<int, int>> vec;
                dfs(i, j, vis, grid, vec, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
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
    cout << "Number of distinct islands: " << countDFS(grid) << endl;
    return 0;
}