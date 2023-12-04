//simple path finding
#include<bits/stdc++.h>
using namespace std;

void findPath(int x, int y, int n, int m, vector<vector<int>> &grid, vector<int> &path, vector<vector<int>> &allPaths){
    if(x == n-1 && y == m-1){
        path.push_back(grid[x][y]);
        allPaths.push_back(path);
        path.pop_back();
        return;
    }
    if(x+1 < n){
        path.push_back(grid[x][y]);
        findPath(x+1, y, n, m, grid, path, allPaths);
        path.pop_back();
    }
    if(y+1 < m){
        path.push_back(grid[x][y]);
        findPath(x, y+1, n, m, grid, path, allPaths);
        path.pop_back();
    }
}
vector<vector<int>> genPaths(int n, int m, vector<vector<int>> &grid){
    vector<vector<int>> allPaths;
    vector<int> path;
    findPath(0, 0, n, m, grid, path, allPaths);
    return allPaths;
}
int main(){
    int n = 7, m = 10;
    vector<vector<int>> grid = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
        {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
        {61, 62, 63, 64, 65, 66, 67, 68, 69, 70}
    };
    vector<vector<int>> allPaths = genPaths(n, m, grid);

    for(const auto &p : allPaths){
        for(int cells : p){
            cout << cells << " ";
        }
        cout << endl;
    }
    return 0;
}