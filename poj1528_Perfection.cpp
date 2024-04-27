#include <stdio.h>
#include <cstring>

int f[60005];

int factor(int n) {
    int res = 0;
    memset(f, 0, sizeof(f));
    for (int i = 2; i < n; ++i) {
        if (f[i]) continue;
        if (n % i != 0) {
            for (int j = i; j < n; j += i) f[j] = 1;
        } 
    }
    for (int i = 1; i < n; ++i) if (!f[i]) res += i;
    return res;
}

int main() {
    int n, tmp;
    printf("PERFECTION OUTPUT\n");
    while (scanf("%d", &n)) {
        if (!n) {
            printf("END OF OUTPUT");
            break;
        }
        printf("%5d  ", n);
        tmp = factor(n);
        if (tmp == n) printf("PERFECT\n");
        if (tmp < n) printf("DEFICIENT\n");
        if (tmp > n) printf("ABUNDANT\n"); 
    }
}