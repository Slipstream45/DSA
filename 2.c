//Tower of Hanoi
#include<stdio.h>
void toh(int, char, char, char);

int main(){
    int n = 3;
    char src='S', dst='D', aux='A';
    toh(n, src, dst, aux);
    return 0;
}
void toh(int n, char src, char dst, char aux){
    if(n==1){
        printf("Move disk 1 from %c to %c\n", src, dst);
        return;
    }
    toh(n-1, src, aux, dst);
    printf("Move disk %d from %c to %c\n",n, src, dst);
    toh(n-1, aux, dst, src);
}