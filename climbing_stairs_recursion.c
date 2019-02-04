#include <stdio.h>

int climbStairs(int n);

int main(){
    printf("an: %d", climbStairs(45));
    return 0;
}

int climbStairs(int n) {
    if(n == 1 || n==0) return 1;
    return climbStairs(n-1) + climbStairs(n-2);
}