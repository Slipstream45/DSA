#include<bits/stdc++.h>
using namespace std;

void pathFunction(int x, int y, int n, int m, vector<vector<int>> &grid, vector<int> &path, vector<vector<int>> &allPaths){
    //Base condition is when we reached destination
    if((x == n - 1) && (y == m - 1)){
        path.push_back(grid[x][y]);
        allPaths.push_back(path);
        path.pop_back();
        return;
    }
    //Explore down and right
    path.push_back(grid[x][y]);

    //check for boundary or 0
    //move right
    if(x + 1 < n && grid[x+1][y] !=0){ 
        pathFunction(x + 1, y, n, m, grid, path, allPaths);
    }
    //move down
    if(y + 1 < m && grid[x][y+1] != 0){
        pathFunction(x, y + 1, n, m, grid, path, allPaths);
    }
    //backtrack
    path.pop_back();
}

vector<vector<int>> findPaths(int n, int m, vector<vector<int>> &grid){
    vector<vector<int>> allPaths;
    vector<int> path;
    pathFunction(0, 0, n, m, grid, path, allPaths);
    return allPaths;
}

int main(){
    int n = 2, m = 3;
    vector< vector<int> > grid = {
        {1, 2, 0},
        {0, 5, 6}
    };

    vector< vector<int> > paths = findPaths(n, m, grid);

    for(const auto &path : paths){
        for(int cell : path){
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}