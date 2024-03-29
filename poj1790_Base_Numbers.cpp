#include <stdio.h>
#include <cstring>

const int N = 50;
int f[N];
long long sum = 0, dp[N][N] = {0};
char a[N];

int compare(int a, int b, int c) {
    if (b - a > N - c - 1) return 1;
    if (b - a < N - c - 1) return -1;
    for (int i = a; i <= b; ++i) {
        if (f[i] > f[c - a + i]) return 1;
        if (f[i] < f[c - a + i]) return -1;
    }
    return 0;
}

long long count(int i, int c) {
    if (i == f[0] - 1) sum++;
    for (int j = i; j >= f[0]; --j) {
        if (j != i && f[j] == 0) continue;
        if (compare(j, i, c) == -1) {
            if (dp[j - 1][c]) sum += dp[j - 1][c];
            else dp[j - 1][c] = count(j - 1, c);
        }
        else break;
    }
    return sum;
}

long long solve() {
    long long res = 0;
    for (int j = N - 1; j > f[0]; --j) {
        sum = 0;
        if (j - 1 > f[0] && f[f[0]] == 0) continue;
        if (f[j]) res += count(j - 1, j);
    }
    return res;
}


int main() {
    while (scanf("%s", a)) {
        long long res;
        memset(dp, 0, sizeof(dp));
        if (a[0] == '#') break;
        f[0] = N - strlen(a);
        for (int i = f[0]; i < N; ++i) f[i] = a[i - f[0]] - '0';
        res = solve();
        if (res > 0) printf("The code %s can represent %lld numbers.\n", a, res);
        else printf("The code %s is invalid.\n", a);
    }  
}