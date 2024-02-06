#include <cmath>
#include <stdio.h>

void solve(int n) {
    int k = (int(pow(n * 8 + 1, 0.5)) - 1) / 2;
    printf("%d\n", k);
    int tmp = n - ((k + 1) * k / 2);
    printf("%d\n", tmp);
    if (tmp!=0) {
        if (k%2) printf("TERM %d IS %d/%d\n", n, tmp, k + 2 - tmp);
        else printf("TERM %d IS %d/%d\n", n, k + 2 - tmp, tmp);
    }
    else {
        if (k%2) printf("TERM %d IS %d/%d\n", n, 1, k);
        else printf("TERM %d IS %d/%d\n", n, k, 1);
    }
}

int main() {
    int n;
    while (scanf("%d", &n)!=EOF) {
        solve(n);
    }
}