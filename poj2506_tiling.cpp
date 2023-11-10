#include <stdio.h>

const int N = 101, n = 251;
int res[n][N] = {0};

void mul(int b) {
    int tmp = 0, tmpn = 0, maxn = N - 1;
    for (int i=N-1; i>=res[b-1][0]; --i) {
        res[b][i] += 2 * res[b-2][i] + res[b-1][i];
        tmp = i;
        while (res[b][tmp]>9) {
            tmpn = res[b][tmp];
            res[b][tmp] = tmpn % 10;
            res[b][tmp-1] = tmpn / 10;
            tmp--;
        }  
        if (maxn>tmp) maxn = tmp;  
    }
    while (res[b][maxn]==0) maxn++;
    res[b][0] = maxn;
}

int main() {
    int tmp = 2, a = 0;
    for (int i=0; i<3; ++i) res[i][0] = N - 1;
    res[0][N-1] = 1;
    res[1][N-1] = 1;
    res[2][N-1] = 3;
    while (scanf("%d", &a)!=EOF) {
        if (a>tmp) {
            for (int i=tmp+1; i<=a; ++i) mul(i);
            for (int i=res[a][0]; i<=N-1; ++i) printf("%d", res[a][i]);
            tmp = a;   
        }
        else for (int i=res[a][0]; i<=N-1; ++i) printf("%d", res[a][i]);
        printf("\n");
    } 
}
