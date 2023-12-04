//nearest distance to 1 from every cell
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> nearestBFS(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> distance(n, vector<int>(m, 0));
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<pair<pair<int, int>, int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            } else{
                vis[i][j] = 0;
            }

        }
    }
    while(!q.empty()){
        int dist = q.front().second;
        int row = q.front().first.first;
        int col = q.front().first.second;
        distance[row][col] = dist;
        q.pop();
        for(const auto &dir : directions){
            int r = row+dir.first;
            int c = col+dir.second;
            if(r<n && r>=0 && c<m && c>=0 && !vis[r][c]){
                vis[r][c] = 1;
                q.push({{r, c}, dist+1});
            }
        }
    }
    return distance;
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
    vector<vector<int>> res = nearestBFS(grid);
    cout << "Result is: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}