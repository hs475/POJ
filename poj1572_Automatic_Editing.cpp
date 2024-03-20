#include <stdio.h>
#include <cstring>

char f[50][500], a[500], b[500];

int match(int k) {
    int l, r, flag = 0;
    for (int i = 0; i < strlen(a) - strlen(f[2 * k]) + 1; ++i) {
        l = i;
        r = 0;
        while (r < strlen(f[2 * k])) {
            if (a[l] != f[2 * k][r]) break;
            if (a[l] == f[2 * k][r] && r == strlen(f[2 * k]) - 1) flag = 1;
            l++;
            r++;
        }
        if (flag) return i;
    }
    return -1;
}

void solve(int n) {                                                                                                                    
    int tmp, r;
    for (int i = 0; i < n; ++i) {
        while (1) {
            tmp = match(i);
            if (tmp < 0) break;
            for (int j = 0; j < tmp; ++j) b[j] = a[j];
            r = tmp;
            for (int j = 0; j < strlen(f[2 * i + 1]); ++j) {
                b[r] = f[2 * i + 1][j];
                r++;
            }
            for (int j = tmp + strlen(f[2 * i]); j < strlen(a); ++j) {
                b[r] = a[j];
                r++;
            }
            for (int j = 0; j < r; ++j) a[j] = b[j];
            a[r] = '\0';
        }
    }
    printf("%s\n", a);
}

int main() {
    int n;
    while (scanf("%d", &n)) {
        if (!n) break;
        getchar();
        for (int i = 0; i < n; ++i) {
            gets(f[2 * i]);
            gets(f[2 * i + 1]);
        }
        gets(a);
        solve(n);
    } 
}