#include <stdio.h>
#include <cmath>

#define pi acos(-1)

int main() {
    int t, n;
    double R;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        scanf("%lf%d", &R, &n);
        printf("Scenario #%d:\n", i);
        printf("%.3lf\n\n", R * sin(pi / n) / (1 + sin(pi / n)));
    }
}