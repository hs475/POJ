#include <stdio.h>

int res[101][51] = {0};

void mul(int b) {
    int tmp = 0, tmpn = 0, maxn = 50;
    for (int i=50; i>=res[b-1][0]-1; --i) {
        res[b][i] += 3 * res[b-1][i];
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
    for (int i=50; i>=maxn; --i) {
        if (res[b][i]>=res[b-2][i]) res[b][i] -=res[b-2][i];
        else {
            tmp = i - 1;
            while (res[b][tmp]==0) {
                res[b][tmp] = 9;
                tmp--;
            }
            res[b][tmp] -= 1;
            res[b][i] = 10 + res[b][i] - res[b-2][i];
        }
    }
    while (res[b][maxn]==0) maxn++;
    res[b][0] = maxn;
}

int main() {
    int tmp = 2, a = 0;
    res[1][50] = 1;
    res[2][50] = 3;
    res[1][0] = 50;
    res[2][0] = 50;
    while (scanf("%d", &a)!=EOF) {
        if (a>tmp) {
            for (int i=tmp+1; i<=a; ++i) mul(i);
            for (int i=res[a][0]; i<=50; ++i) printf("%d", res[a][i]);
            tmp = a;   
        }
        else for (int i=res[a][0]; i<=50; ++i) printf("%d", res[a][i]);
        printf("\n");
    } 
}