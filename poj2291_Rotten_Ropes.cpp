#include <stdio.h>
#include <algorithm>

int f[1005];

void solve() {
    int n, t = 0, maxw = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &f[i]);
    std::sort(f, f + n);
    for (int i = n - 1; i >= 0; --i) {
        maxw = std::max(maxw, f[i] * (n - i));
    }
    printf("%d\n", maxw);
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) solve();
}