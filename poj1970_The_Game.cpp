#include <stdio.h>

int f[20][20], d[3][2];

int search(int i, int j, int h, int v) {
    int res = 1, it = i, jt = j;
    while (f[i+h][j+v] == f[i][j] && (i + h) <= 19 && (i + h) >= 1 && (j + v) >= 1 && (j + v) <= 19) {
        res++;
        i += h;
        j += v;
    }
    while (f[it-h][jt-v] == f[it][jt] && (it - h) <= 19 && (it - h) >= 1 && (jt - v) >= 1 && (jt - v) <= 19) {
        res++;
        it -= h;
        jt -= v;
    }
    return res;
}

int solve(int a) {
    for (int i = 1; i <= 19; ++i) {
        for (int j = 1; j <= 19; ++j) {
            if (f[i][j] == a) {
                if (search(i, j, 0, 1) == 5 || search(i, j, 1, 0) == 5 || search(i, j, 1, 1) == 5) {
                    d[a][0] = i;
                    d[a][1] = j;
                    return 1;
                }
                if (search(i, j, -1, 1) == 5) {
                    d[a][0] = i + 4;
                    d[a][1] = j - 4;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int t, r1, r2;
    scanf("%d", &t);
    while (t--) {
        for (int i = 1; i < 20; ++i) {
            for (int j = 1; j < 20; ++j) scanf("%d", &f[i][j]);
        }
        r1 = solve(1);
        r2 = solve(2);
        if (!r1 && !r2) printf("0\n");
        else {
            if (r1) printf("1\n%d %d\n", d[1][0], d[1][1]);
            else printf("2\n%d %d\n", d[2][0], d[2][1]);
        }
    }
}