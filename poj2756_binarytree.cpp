#include <stdio.h>

int solve(int a, int b) {
    while (!(a==1||b==1)) {
        if (a==b) return a;
        if (a>b) a /= 2;
        else b /= 2;
    }
    return 1;
}

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b)) {
        printf("%d\n", solve(a, b));
    }
    
}