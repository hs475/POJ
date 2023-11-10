#include <stdio.h>
#include <cstring>
#include <iostream>

const int N = 1001, n = 500;
char in1[N], in2[N];
int f[n][N], l[N], r[N], max = 2;

void plus(int a, int b) {
    int min = std::min(f[a][0], f[b][0]), tmp;
    f[b][0] = min;
    for (int i=N-1; i>=min; --i) {
        f[b][i] += f[a][i];
        tmp = i;
        while (f[b][tmp]>9) {
            f[b][tmp-1] += f[b][tmp] / 10;
            f[b][tmp] %= 10;
            tmp--;
        }
    }
    while (f[b][f[b][0]-1]) f[b][0]--;
}

int big(int a, int s[]) {
    if (f[a][0]>s[0]) return 0;
    else {
        if (f[a][0]<s[0]) return 2;
        else {
            for (int i=f[a][0]; i<N; ++i) {
                if (f[a][i]>s[i]) return 2;
                else {
                    if (f[a][i]<s[i]) return 0;
                }
            }
        }
    }
    return 1;
}
//0 小    1 等     2 大

void fib() {
    while (1) {
        if (big(max, r)!=2) {
            max++;
            plus(max-1, max);
            plus(max-2, max);
        }
        else break;
    }
}

int solve() {
    int res = 0;
    for (int i=1; i<n; ++i) {
        if ((big(i, l)>=1)&&big(i, r)<=1) res++;
        if (big(i, r)==2) break;
    }
    return res;
}

int main() {
    int len;
    f[1][N-1] = 1;
    f[2][N-1] = 2;
    for (int i=0; i<n; ++i) f[i][0] = N - 1;
    while (scanf("%s%s", in1, in2)!=EOF) {
        if ((strlen(in1)==1&&in1[0]=='0')&&(strlen(in2)==1&&in2[0]=='0')) break;
        else {
            len = strlen(in1);
            for (int i=N-1; i>=N-len; --i) l[i] = in1[i-N+len] - '0';
            l[0] = N - len;
            len = strlen(in2);
            for (int i=N-1; i>=N-len; --i) r[i] = in2[i-N+len] - '0';
            r[0] = N - len;

            fib();
            printf("%d\n", solve());            
        }
    }
}