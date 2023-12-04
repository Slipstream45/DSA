#include<stdio.h>
int sumR(int n);
int factR(int n);

int main(){
    int n=5;
    printf("%d\n", sumR(n));
    printf("%d\n", factR(n));
    return 0;
}
int sumR(int n){
    if(n<0){
        return 0;
    }else{
        n += sumR(n-1);
    }
    return n;
}
int factR(int n){
    if(n==0 || n==1){
        return 1;
    }else{
        n *= factR(n-1);
    }
    return n;
}