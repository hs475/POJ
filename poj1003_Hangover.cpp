#include <stdio.h>

int main() {
    double res, n;
    int t;
    while (scanf("%lf", &n)!=EOF) {
        if (n==0) break;
        t = 2;
        res = 0;
        while (res<n) {
            res += double(1) / t;
            t++;
        }
        printf("%d card(s)\n", t-2);
    }
}