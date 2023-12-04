//print any one subsequence
#include<iostream>
#include<vector>
using namespace std;

bool printS(int ind, vector <int> &ds, int arr[], int sum, int target, int n){
    if(ind == n){
        if(sum == target){
            for(auto i : ds){
                cout << i << " ";
            }
            cout << endl;
            return true;
        } else {
            return false;
        }
    }
    //take
    ds.push_back(arr[ind]);
    sum += arr[ind];
    
    if(printS(ind+1, ds, arr, sum, target, n) == true){
        return true;
    }

    sum -= arr[ind];
    ds.pop_back();

    //don't take
    if(printS(ind+1, ds, arr, sum, target, n) ==  true){
        return true;
    }

    return false;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int target = 5, n = 5;
    vector <int> ds;
    printS(0, ds, arr, 0, target, n);
}