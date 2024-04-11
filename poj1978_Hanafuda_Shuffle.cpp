#include <stdio.h>
#include <iostream>

int f[2][55], flag;

void shuffle(int n, int p, int c) {
    for (int i = p; i < p + c; ++i) f[1][i - p + 1] = f[0][i];
    for (int i = 1; i < p; ++i) f[1][c + i] = f[0][i];
    memcpy(f[1], f[0], sizeof(f[1]));
}

int main() {
    int n, step, p, c;
    while (scanf("%d%d", &n, &step)) {
        if (!n) break;
        flag = 1;
        for (int i = 1; i <= n; ++i) f[0][i] = n - i + 1;
        for (int i = 1; i <= n; ++i) f[1][i] = n - i + 1;
        for (int i = 0; i < step; ++i) {
            scanf("%d%d", &p, &c);
            shuffle(n, p, c);
        }
        printf("%d\n", f[0][1]);
    }
}