#include<bits/stdc++.h>
using namespace std;

void findPaths(int x, int y, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<string> ans, string moves){
    if(x == n-1 && y == n-1){
        ans.push_back(moves);
        return;
    }
    //right
    if(x+1 < n && grid[x+1][y]==1 && visited[x+1][y]==0){
        visited[x][y] = 1;
        findPaths(x+1, y, n, m, grid, visited, ans, moves+'R');
        visited[x][y] = 0;
    }
    //left
    if(x-1 < n && grid[x-1][y]==1 && visited[x-1][y]==0){
        visited[x][y] = 1;
        findPaths(x-1, y, n, m, grid, visited, ans, moves+'L');
        visited[x][y] = 0;
    }
    //up
    if(y-1 < m && grid[x][y-1]==1 && visited[x][y-1]==0){
        visited[x][y] = 1;
        findPaths(x, y-1, n, m, grid, visited, ans, moves+'U');
        visited[x][y] = 0;
    }
    //down
    if(y+1 < m && grid[x][y+1]==1 && visited[x][y+1]==0){
        visited[x][y] = 1;
        findPaths(x, y+1, n, m, grid, visited, ans, moves+'L');
        visited[x][y] = 0;
    }
}

vector<string> moveFun(int n, int m, vector<vector<int>> &grid){
    vector<string> ans;
    vector<vector<int>> visited;
    if(grid[0][0]==0){
        return ans;
    }
    findPaths(0, 0, n, m, grid, visited, ans, "");
    return ans;
}
int main(){
    int n = 4, m = 4;
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string> moves = moveFun(n, m, grid);
    for(auto &p : moves){
        cout << p << " ";
    }
    return 0;
}