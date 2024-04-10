#include <stdio.h>
#include <cmath>

int main() {
    double a, b, c, d, e, f, a1, a2, a3, S, r, C;
    while (scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f) != EOF) {
        a1 = std::sqrt((a - c) * (a - c) + (b - d) * (b - d));
        a2 = std::sqrt((c - e) * (c - e) + (d - f) * (d - f));
        a3 = std::sqrt((a - e) * (a - e) + (b - f) * (b - f));
        double p = (a1 + a2 + a3) / 2;
        S = std::sqrt(p * (p - a1) * (p - a2) * (p - a3));
        r = a1 * a2 * a3 / 2 / S;
        C = 3.141592653589793 * r;
        printf("%.2lf\n", C);
    } 
}