#include <stdio.h>
#include <math.h>

void solve(int n) {
    int k = (-1 + int(pow(1 + 8 * n, 0.5))) / 2;
    int res = k * (k + 1) * (2 * k + 1) / 6;
    res += (n - (k * (k + 1) / 2)) * (k + 1);
    printf("%d %d\n", n, res);
} 

int main() {
    int n;
    while (scanf("%d", &n)) {
        if (!n) break;
        solve(n);
    }
}