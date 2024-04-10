#include <stdio.h>

int flag;
char f[2][105][105];

void solve(int &flag, int r, int c) {
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (f[1 - flag][i][j] == 'R') {
                if (f[1 - flag][i - 1][j] == 'P' || f[1 - flag][i + 1][j] == 'P' || \
                    f[1 - flag][i][j + 1] == 'P' || f[1 - flag][i][j - 1] == 'P') \
                    f[flag][i][j] = 'P'; 
                else f[flag][i][j] = f[1 - flag][i][j];
            }
            if (f[1 - flag][i][j] == 'S') {
                if (f[1 - flag][i - 1][j] == 'R' || f[1 - flag][i + 1][j] == 'R' || \
                    f[1 - flag][i][j + 1] == 'R' || f[1 - flag][i][j - 1] == 'R') \
                    f[flag][i][j] = 'R'; 
                else f[flag][i][j] = f[1 - flag][i][j];
            } 
            if (f[1 - flag][i][j] == 'P') {
                if (f[1 - flag][i - 1][j] == 'S' || f[1 - flag][i + 1][j] == 'S' || \
                    f[1 - flag][i][j + 1] == 'S' || f[1 - flag][i][j - 1] == 'S') \
                    f[flag][i][j] = 'S'; 
                else f[flag][i][j] = f[1 - flag][i][j];
            }
        }
    }
    flag = 1 - flag;
}

int main() {
    int r, c, n, day;
    scanf("%d", &n);
    for (int k = 0; k < n; ++k) {
        flag = 1;
        scanf("%d%d%d", &r, &c, &day);
        getchar();
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) scanf("%c", &f[0][i][j]);
            getchar();
        }
        for (int i = 0; i < day; ++i) solve(flag, r, c);
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) printf("%c", f[1 - flag][i][j]);
            printf("\n");
        }
        if (k != n - 1) printf("\n");
    }
}