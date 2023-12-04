//1,2,3,4 -> 4,3,2,1
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
void revR(int A[], int n, int l, int r);
void revR2(int A[], int n, int l);
void swap(int *a, int *b);
bool pal(char S[]);
bool check(char S[], int s, int e);

int main(){
    int A[] = {1,2,3,4,5};
    int n = sizeof(A)/sizeof(A[0]);
    revR(A, n, 0, n-1);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    revR2(A, n, 0);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    char S[10] = "racecar";
    if(pal(S)){
        printf("\nPalindrome\n");
    }else{
        printf("\nNot a palindrome\n");
    }
    return 0;

}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void revR(int A[], int n, int l, int r){
    if(l>=r){
        return;
    }
    swap(&A[l], &A[r]);
    revR(A, n, l+1, r-1);
}
void revR2(int A[], int n, int l){
    if(l>=n-l-1){
        return;
    }
    swap(&A[l], &A[n-l-1]);
    revR2(A, n, l+1);
}
bool pal(char S[]) {
    int n = strlen(S);
    if (n == 0) {
        return true;
    }
    return check(S, 0, n - 1);
}

bool check(char S[], int s, int e) {
    if (s == e) {
        return true;
    }
    if (S[s] != S[e]) {
        return false;
    }
    if (s < e + 1) {
        return check(S, s + 1, e - 1);
    }
    return true;
}