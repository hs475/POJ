#include <stdio.h>

void calC(int N, int M) {
    long long res = 1;
    int b = (N - M) > M ? (N - M) : M;
    int a = 1;
    for (int i=b+1; i<=N; ++i) {
        res *= i;
        res /= a;
        a++;
    }
    printf("%d things taken %d at a time is ", N, M);
    printf("%lld exactly.\n", res);
}


int main() {
    int N, M;
    while (scanf("%d%d", &N, &M)!=EOF) {
        if (N==0&&M==0) break;
        else calC(N, M);
    }
}