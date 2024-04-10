#include <stdio.h>
#include <cmath>
#include <iostream>
#include <algorithm>

void solve(int a) {
    int q, res = 10000;
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; i * j <= a; ++j) {
            if (a % (i * j) == 0) {
                q = a / (i * j);
                res = std::min(res, i * j + j * q + q * i);
            }
        }
    }
    printf("%d\n", 2 * res);
}

int main() {
    int n, t;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        solve(t);
    }
}