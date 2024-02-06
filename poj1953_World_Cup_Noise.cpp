#include <stdio.h>

int f[2][45];

void dp(int a, int n) {
    for (int i=a+1; i<=n; ++i) {
        f[1][i] = f[0][i-1];
        f[0][i] = f[0][i-1] + f[1][i-1];
    }
}

int main() {
    int a, n, num;
    scanf("%d", &num);
    a = 1;
    f[0][a] = 1;
    f[1][a] = 1;
    for (int i=1; i<=num; ++i) {
        scanf("%d", &n);
        printf("Scenario #%d:\n", i);
        if (n>a) {
            dp(a, n);
            a = n;
        }
        printf("%d\n\n", f[0][n] + f[1][n]);
    }
}