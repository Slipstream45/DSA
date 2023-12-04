#include<stdio.h>
void name(char *p, int times);
void linearAsc(int start, int end);
void linearDsc(int start, int end);
void diffAsc(int s, int e);
void diffDsc(int n);

int main(){
    char n[10] = "Anirban";
    name(n, 0);
    int n1 = 10;
    linearAsc(1, n1);
    printf("====");
    linearDsc(n1, 1);
    printf("====");
    diffAsc(n1, n1);
    printf("====");
    diffDsc(n1);
    printf("====");
}
void name(char *p, int times){
    if(times==5){
        return;
    }else{
        printf("%s\n", p);
    }
    name(p, times+1);
}
void linearAsc(int start, int end){
    if(start>end){
        return;
    }else{
        printf("%d\n", start);
    }
    linearAsc(start+1, end);
}
void linearDsc(int start, int end){
    if(start<end){
        return;
    }else{
        printf("%d\n", start);
    }
    linearDsc(start-1, end);
}
void diffAsc(int i, int n){
    if(i<1){
        return;
    }
    diffAsc(i-1, n);
    printf("%d\n", i);
}
void diffDsc(int n){
    if (n == 0) {
        return;
    } else {
        printf("%d\n", n);
        diffDsc(n - 1);
    }
}
