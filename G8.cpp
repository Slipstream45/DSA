//rotten oranges
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int rotten(int n, int m, vector<vector<int>> bag){
    queue<pair<int, int>> q;
    int time=0;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int fresh = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(bag[i][j]==2){
                q.push({i,j});
            }else if(bag[i][j]==1){
                fresh++;
            }
        }
    }

    while(!q.empty() && fresh > 0){
        int size = q.size();
        for(int i=0;i<size;i++){
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();

            for(const auto &dir : directions){
                int nr = cr+dir.first;
                int nc = cc+dir.second;

                if(nr>=0 && nr<n && nc>=0 && nc<m && bag[nr][nc]==1){
                    q.push({nr, nc});
                    bag[nr][nc]=2;
                    fresh--;
                }
            }
        }
        if(!q.empty()){
            time++;
        }
    }
    return time;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> bag(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> bag[i][j];
        }
    }

    rotten(n, m, bag);
    cout << "Infection in " << rotten(n, m, bag) <<" units of time.\n";
    return 0;
}