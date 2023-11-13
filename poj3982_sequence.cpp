#include <stdio.h>
#include <cstring>
#include <iostream>

const int N = 1001;
int f[100][N];
char in[3][N];

void plus(int a, int b) {
    int c, tmp = std::min(f[a][0], f[b][0]);
    f[b][0] = tmp;
    for (int i=N-1; i>=tmp; --i) {
        f[b][i] += f[a][i];
        c = i;
        while (f[b][c]>9) {
            f[b][c-1] += f[b][c] / 10;
            f[b][c] %= 10;
        }
    }
    if (f[b][f[b][0]-1]) f[b][0]--;
}

void solve() {
    for (int i=3; i<100; ++i) {
        plus(i-3, i);
        plus(i-2, i);
        plus(i-1, i);
    }
    for (int i=f[99][0]; i<N; ++i) printf("%d", f[99][i]);
    printf("\n");
}

int main() {
    int len, tmp;
    while (scanf("%s%s%s", in[0], in[1], in[2])!=EOF) {
        for (int i=0; i<100; ++i) f[i][0] = N - 1;
        for (int i=0; i<3; ++i) {
            len = strlen(in[i]);
            tmp = 0;
            for (int j=N-len; j<N; ++j) f[i][j] = int(in[i][tmp++] - '0');
            f[i][0] = N - len;
        }
        solve();
        memset(f, 0, sizeof(f));
    }  
}
