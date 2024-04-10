#include <stdio.h>

int f[25];

int main() {
    int n, t = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) scanf("%d", &f[i]);
    for (int i = 0; i <= n; ++i) printf("%d ", f[i]);
    while (!f[t]) t++;
    printf("%d\n", t);
    if (t >= n - 1) printf("YES\n");
    else {
        if (t == n - 2) {
            if (f[n - 1] * f[n - 1] - 4 * f[n - 2] * f[n] >= 0) printf("NO\n");
            else printf("YES\n");
        }
        else printf("NO\n");
    }
}