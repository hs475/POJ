#include <stdio.h>
#include <cstring>

const int N = 2001;
int f[N], g[N], h[N], res[2*N];
int f1, g1, h1, res1;

void multi() {
    res1 = f1 + g1;
    for (int i=0; i<=f1; ++i) {
        for (int j=0; j<=g1; ++j) {
            res[i+j] += f[i] * g[j];
        }
    }
    for (int i=0; i<=res1; ++i) res[i] %= 2;
        
}

void mod() {
    for (int i=res1-h1; i>=0; --i) {
        if (!res[i+h1]) continue;
        for (int j=h1; j>=0; --j) {
            res[i+j] = (res[i+j] - h[j] + 2) % 2;
        }
    }
    while (!res[res1]) res1--;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", &f1);
        for (int j=f1-1; j>=0; --j) scanf("%d", &f[j]);
        f1--;
        scanf("%d", &g1);
        for (int j=g1-1; j>=0; --j) scanf("%d", &g[j]);
        g1--;
        scanf("%d", &h1);
        for (int j=h1-1; j>=0; --j) scanf("%d", &h[j]);
        h1--;
        multi();
        mod();
        printf("%d ", res1+1);
        for (int i=res1; i>=0; --i) printf("%d ", res[i]);
        printf("\n");
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        memset(h, 0, sizeof(h));
        memset(res, 0, sizeof(res));
    }
}