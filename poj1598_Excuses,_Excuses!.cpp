#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <iostream>

char f[200][200], g[200][200], a[200][200];
int ans[200];

int match(int p, int k)
{
    int l, r, num = 0, flag;
    for (int i = 0; i + strlen(f[k]) < strlen(a[p]) + 1; ++i) {
        l = i;
        r = 0;
        flag = 0;
        if (l > 0 && (a[p][l - 1] >= 'a' && a[p][l - 1] <= 'z')) continue;
        while (r < strlen(f[k])) {
            if (a[p][l] != f[k][r]) break;
            if (a[p][l] == f[k][r] && r == strlen(f[k]) - 1\
             &&(l == strlen(a[p]) - 1 || (a[p][l + 1] > 'z' || a[p][l + 1] < 'a')))\
            flag = 1;
            l++;
            r++;
        }
        if (flag) {
            num++;
            i = l - 1;
        }
    }
    return num;
}

void solve(int n1, int n2) {
    int maxv = 0;
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n2; ++i) {
        for (int j = 0; j < n1; ++j) {
            ans[i] += match(i, j);
            maxv = std::max(maxv, ans[i]);
        }
    }
    for (int i = 0; i < n2; ++i) if (ans[i] == maxv) printf("%s\n", g[i]);
}

int main()
{
    int n1, n2, n = 1;
    while (scanf("%d%d", &n1, &n2) != EOF) {
        for (int i = 0; i < n1; ++i) scanf("%s", f[i]);
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < strlen(f[i]); ++j) {
                if (f[i][j] >= 'A' && f[i][j] <= 'Z')f[i][j] += 32;
            }
        }
        getchar();
        for (int i = 0; i < n2; ++i) {
            gets(a[i]);
            for (int j = 0; j < strlen(a[i]); ++j) {
                g[i][j] = a[i][j];
                if (a[i][j] >= 'A' && a[i][j] <= 'Z') a[i][j] += 32;
            }
            g[i][strlen(a[i])] = '\0';
        }
        printf("Excuse Set #%d\n", n);
        n++;
        solve(n1, n2);
        printf("\n");
    }
}