#include <stdio.h>
#include <cmath>
#include <cstring>

const int N = 10;
char in[N];
int res[N];

void solve() {
    if (res[0]==N-1) {
        printf("%d\n", res[N-1]);
        return;
    }
    else {
        for (int i=N-1; i>res[0]; --i) {
            if (res[i]>=5) res[i-1]++;
            res[i] = 0;
        }
    }
    for (int i=res[0]; i<N; ++i) printf("%d", res[i]);
    printf("\n");
}

int main() {
    int num, n, len;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%s", in);
        len = strlen(in);
        for (int i=N-1; i>=N-len; --i) res[i] = in[i-N+len]  - '0';
        res[0] = N - len;
        //for (int i=res[0]; i<N; ++i) printf("%d", res[i]);
        solve();
    }
}