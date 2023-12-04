//Printing subsequences whose sum is K
#include<iostream>
#include<vector>
using namespace std;
void printS(int ind, vector <int> &ds, int sum, int target, int arr[], int n){
    if(ind == n){
        if(sum == target){
            for(auto i : ds){
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }
    //pick
    ds.push_back(arr[ind]);
    sum += arr[ind];
    
    printS(ind+1, ds, sum, target, arr, n);
    
    sum -= arr[ind];
    ds.pop_back();

    //not pick
    printS(ind+1, ds, sum, target, arr, n);
    
}
int main(){
    int arr[] = {1,2,3,4};
    int n = 4;
    int target = 5;
    vector <int> ds;
    printS(0, ds, 0, target, arr, n);
    return 0;
}