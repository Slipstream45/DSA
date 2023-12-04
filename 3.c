//Check if array is sorted with recursion
#include<stdio.h>
#include<stdbool.h>
bool checkArray(int A[], int n);

int main(){
    int A[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(A)/sizeof(A[0]);

    if(checkArray(A, n)){
        printf("Sorted!\n");
    }else{
        printf("Unsorted!\n");
    }
    return 0;
}

bool checkArray(int A[], int n){
    if(n<=1){
        return true;
    }if(A[n-1]<A[n-2]){
        return false;
    }
    checkArray(A, n-1);
}