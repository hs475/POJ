#include <stdio.h>
#include <iostream>
#include <cmath>

int main() {
    int n;
    double v, t, res, tmp;
    while (scanf("%d", &n)) {
        if (!n) break;
        res = 1000000;
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &v, &t);
            if (t >= 0) {
                tmp = ceil((4.5 / v) * 3600 + t);
                res = std::min(tmp, res);
            }
        }
        printf("%d\n", int(res));
    }
}