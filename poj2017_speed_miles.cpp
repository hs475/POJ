#include <stdio.h>

int main() {
    int n, tmp, a, b, res;
    while (scanf("%d", &n)) {
        tmp = 0;
        res = 0;
        if (n==-1) break;
        for (int i=0; i<n; ++i) {
            scanf("%d%d", &a, &b);
            res += (b - tmp) * a;
            tmp = b;         
        }
        printf("%d miles\n", res);
    }
}