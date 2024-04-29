#include <stdio.h>
#include <cmath>

int main() {
    int a, b, N, k, l, r, mid;
    double eps = 1e-10;
    while (scanf("%d%d", &a, &b)) {
        if (!a) break;
        N = 2;
        l = 0, r = 100000;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (abs(pow(mid + 1, log10(b * 1.0) / log10(mid * 1.0)) - a) < eps) break;
            else if (pow(mid + 1, log10(b * 1.0) / log10(mid * 1.0)) > a) l = mid + 1;
            else r = mid - 1;
        }
        N = mid;
        k = int(0.5 + (log10(b * 1.0) / log10(N * 1.0)));
        printf("%d %d\n", int(0.5 + (1 - pow(N * 1.0, k)) / (1 - N)), int(0.5 + (1 - pow(N * 1.0 / (N + 1), k + 1)) * ((N + 1) * a)));
    }
}