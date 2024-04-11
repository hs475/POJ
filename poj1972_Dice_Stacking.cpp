#include <stdio.h>
#include <iostream>

int f[10005][6];

int opp(int a) {
    if (a == 0 || a == 5) return 5 - a;
    if (a == 1 || a == 3) return 4 - a;
    if (a == 2 || a == 4) return 6 - a;
    return 0;
}

int max1(int a, int b) {
    for (int i = 6; i > 0; --i) {
        if (i != a && i != b) return i;
    }
    return 0;
}

int search(int n, int k) {
    int a, b, res = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 6; ++j) {
            if (f[i][j] == k) {
                a = j;
                break;
            }
        } 
        b = opp(a);
        //printf("%d %d\n", a, b);
        int t = max1(f[i][a], f[i][b]);
        //printf("%d\n", t);
        res += t;
        k = f[i][b];
    }
    return res;
}

int main() {
    int t, n, res;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 6; ++j) scanf("%d", &f[i][j]);
        }
        for (int i = 1; i < 7; ++i) res = std::max(res, search(n, i));
        printf("%d\n", search(n, 6));
    }
}