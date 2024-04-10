#include <stdio.h>

int f[105][105];

int main() {
    int n, sum1, sum2, l, r, flag;
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        l = -1;
        r = -1;
        flag = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &f[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            sum1 = 0;
            sum2 = 0;
            if (!flag) break;
            for (int j = 0; j < n; ++j) {
                sum1 += f[i][j];  
                sum2 += f[j][i];   
            }
            if (sum1 % 2) {
                if (l > 0) flag = 0;
                else l = i;
            }
            if (sum2 % 2) {
                if (r > 0) flag = 0;
                else r = i;
            }
        }
        if (l == -1 && r == -1) printf("OK\n");
        else {
            if (flag) printf("Change bit (%d,%d)\n", l + 1, r + 1);
            else printf("Corrupt\n");
        }
    }
}