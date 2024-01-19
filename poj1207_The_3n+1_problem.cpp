#include <stdio.h>
#include <iostream>

int cylce_length(int n) {
    int res = 1;
    while (n!=1) {
        if (n%2) n  = 3 * n + 1;
        else n /= 2;
        res++;
    }
    return res;
}

int maxlength(int a, int b) {
    int res = 0;
    int i = std::min(a, b), j = std::max(a, b);
    for (int k=i+1; k<j; ++k) res = std::max(res, cylce_length(k));
    return res;
}

int main() {
    int i, j;
    while (scanf("%d%d", &i, &j)!=EOF) {
        printf("%d %d %d\n", i, j, maxlength(i, j));
    }
}