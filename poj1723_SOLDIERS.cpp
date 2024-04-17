#include <stdio.h>
#include <cmath>
#include <algorithm>

int x[10005], y[10005];

int main() {
    int n, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
    }
    std::sort(x, x + n); 
    for (int i = 0; i < n; ++i) x[i] -= i;
    std::sort(y, y + n);
    for (int i = 0; i < n; ++i) res += abs(y[i] - y[n/2]) + abs(x[i] - x[n/2]);
    printf("%d\n", res);
}