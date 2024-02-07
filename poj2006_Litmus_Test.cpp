#include <stdio.h>
#include <math.h>

int main() {
    double ka, c, m, n, x;
    while (scanf("%lf%lf%lf%lf", &ka, &c, &m, &n)!=EOF) {
        if (ka==0) break;
        x = (-ka + sqrt(ka * ka + 4 * m * n * ka * c)) / (2 * n);
        printf("%.3f\n", -log10(x));
    }
}
