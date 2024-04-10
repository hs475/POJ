#include <stdio.h>
#include <math.h>
#include <iostream>

int main() {
    int n;
    double r, a1, b1, a2, b2, res = 0;
    scanf("%d%lf%lf%lf", &n, &r, &a1, &b1);
    double a = a1, b = b1;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%lf%lf", &a2, &b2);
        res += sqrt((a2 - a1) * (a2 - a1) + (b2 - b1) * (b2 - b1));
        a1 = a2;
        b1 = b2;
    }
    res += sqrt((a - a1) * (a - a1) + (b - b1) * (b - b1));
    res += 2 * 3.141 * r;
    printf("%.2lf", res);
}