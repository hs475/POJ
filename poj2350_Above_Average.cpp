#include <stdio.h>

double f[1005];

int main() {
    int n, t;
    double res, num;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        num = 0;
        res = 0;
        scanf("%d", &t);
        for (int j = 0; j < t; ++j) {
            scanf("%lf", &f[j]);
            res += f[j];
        }
        res /= t;
        for (int j = 0; j < t; ++j) if (f[j] > res) num++;
        printf("%.3lf%%\n", 100 * num / t);
    }
}