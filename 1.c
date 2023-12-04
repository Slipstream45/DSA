#include<stdio.h>
long fact(long);
long fib(long);
int print(int);

int main(){
    long n;
    int p;
    scanf("%ld", &n);
    scanf("%d", &p);
    for(int i=0;i<n;i++){
        printf("%ld ", fib(i));
    }
    printf("%ld\n", fact(n));
    printf("%ld\n", fib(n));
    //print(p);
    return 0;
}
long fact(long n){
    if(n==1 || n==0){
        return 1;
    }else{
        return n*fact(n-1);
    }
}
// int print(int p){
//     if(p==0){
//         printf("%d\n", p);
//         return 0;
//     }else{
//         printf("%d\n", p);
//         return print(p-1);
//     }
// }
long fib(long n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        return (fib(n-1) + fib(n-2));
    }
}