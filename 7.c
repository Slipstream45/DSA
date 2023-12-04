//Subsequence
#include<iostream>
#include<vector>
using namespace std;
void print(int ind, vector<int> &ds, int arr[], int n){
    if(ind == n){
        for(auto it : ds){
            cout << it << " ";
        } if(ds.size()==0){
            cout << "{}" << endl;
        }
        cout << endl;
        return;
    }
    //take or pick the particular index into subsequence
    ds.push_back(arr[ind]);
    print(ind+1, ds, arr, n);
    ds.pop_back();

    //do not pick the particular index into subsequence
    print(ind+1, ds, arr, n);

}
int main(){
    int arr[] = {3,1,2};
    int n = 3;
    vector <int> ds;
    print(0, ds, arr, n);
}