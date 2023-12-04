//count subsequences with sum k
#include<bits/stdc++.h>
using namespace std;
void printS(int ind, int arr[], vector <int> &ds, int n, int sum, int target, int &k){
    if(ind == n){
        if(sum == target){
            k++;
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

    printS(ind+1, arr, ds, n, sum, target, k);

    sum -= arr[ind];
    ds.pop_back();

    //don't pick
    printS(ind+1, arr, ds, n, sum, target, k);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5, target = 5;
    int k = 0;
    vector <int> ds;
    printS(0, arr, ds, n, 0, target, k);
    cout << "Total subsequences with sum " << target << ": " << k << endl;
    return 0;
}