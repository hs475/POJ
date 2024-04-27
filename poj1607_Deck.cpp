#include <stdio.h>
#include <cmath>
#include <iostream>

double f[100005];

void dp(int a, int b) {
    for (int i = a + 1; i <= b; ++i) {
        f[i] = f[i-1] + 0.5 / ((i - 1) * 1.0 + 1);
    }
}

int main() {
    f[1] = 0.5;
    int n, max = 1;
    printf("Cards  Overhang\n");
    while (scanf("%d", &n) != EOF) {
        if (n <= max) printf("%5d%10.3lf\n", n, f[n]);
        else {
            dp(max, n);
            max = n;
            printf("%5d%10.3lf\n", n, f[n]);
        }
    }   
}