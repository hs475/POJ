#include <stdio.h>
#include <cstring>

int f[105];

void solve(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            f[j] = (f[j] + 1) % 2;
        }
    }
    for (int i = 1; i <= n; ++i) if (f[i] == 0) sum++;
    printf("%d\n", sum);
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) f[i] = 1;
        solve(n);
    }

}