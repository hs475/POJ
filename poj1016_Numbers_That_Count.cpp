#include <stdio.h>
#include <cstring>

const int N = 90;
int num[15][N], f[10];
char in[N];

void dis(int i) {
    for (int j=num[i][0]; j<N; ++j) printf("%d", num[i][j]);
    printf("\n");
}

int equal(int a, int b) {
    if (num[a][0]!=num[b][0]) return 0;
    for (int i=num[a][0]; i<N; ++i) if (num[a][i]!=num[b][i]) return 0;
    return 1;
}

void count(int a) {
    int t;
    memset(f, 0, sizeof(f));
    t = N - 1;
    for (int i=num[a][0]; i<N; ++i) f[num[a][i]]++;
    for (int i=9; i>=0; --i) {
        if (f[i]) {
            num[a+1][t] = i;
            t--;
        }
        else continue;
        while (f[i]) {
            num[a+1][t] = f[i] % 10;
            f[i] /= 10;
            t--;
        }
    } 
    num[a+1][0] = t + 1;
}

void solve() {
    for (int i=0; i<15; ++i) {
        count(i);
        for (int j=0; j<=i; ++j) {
            if (equal(i+1, j)) {
                if (j==i) {
                    if (i==0) {
                        for (int k=num[0][0]; k<N; ++k) printf("%d", num[0][k]);
                        printf(" is self-inventorying\n");
                        return;
                    }
                    else {
                        for (int k=num[0][0]; k<N; ++k) printf("%d", num[0][k]);
                        printf(" is self-inventorying after %d steps\n", i);
                        return;
                    }
                }
                else {
                    for (int k=num[0][0]; k<N; ++k) printf("%d", num[0][k]);
                    printf(" enters an inventory loop of length %d\n", i-j+1);
                    return;
                }
            }
        }
    }
    for (int k=num[0][0]; k<N; ++k) printf("%d", num[0][k]);
    printf(" can not be classified after 15 iterations\n");
    return;
}


int main() {
    int len;
    while (scanf("%s", in)) {
        if (in[0]=='-') break;
        len = strlen(in);
        num[0][0] = N - len;
        for (int i=0; i<len; ++i) num[0][i+num[0][0]] = in[i] - '0';
        solve();  
    }
}