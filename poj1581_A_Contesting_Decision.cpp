#include <stdio.h>
#include <cstring>
#include <string>

int a[100] = {0}, f[100] = {0};
char b[100][30];

void solve(int i) {
    int c, d;
    for (int j = 0; j < 4; ++j) {
        scanf("%d%d", &c, &d);
        if (d) {
            a[i] += (c - 1) * 20 + d;
            f[i]++;
        }
    }
}

int main() {
    int n, mina = 100000, maxb = 0, minp = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", b[i]);
        solve(i);
        if (f[i] > maxb) {
            mina = a[i];
            maxb = f[i];
            minp = i;
        }
        if (f[i] == maxb && a[i] < mina) {
            mina = a[i];
            minp = i;
        }
    }
    printf("%s %d %d\n", b[minp], f[minp], a[minp]);
}