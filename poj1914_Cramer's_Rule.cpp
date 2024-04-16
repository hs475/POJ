#include <stdio.h>

long long a[4][4], b[4];

long long det() {
    return a[1][1] * (a[2][2] * a[3][3] - a[2][3] * a[3][2])\
            - a[1][2] * (a[2][1] * a[3][3] - a[2][3] * a[3][1])\
            + a[1][3] * (a[2][1] * a[3][2] - a[2][2] * a[3][1]);
}

void swap(int i) {
    long long tmp;
    tmp = b[1];
    b[1] = a[1][i];
    a[1][i] = tmp;
    tmp = b[2];
    b[2] = a[2][i];
    a[2][i] = tmp;
    tmp = b[3];
    b[3] = a[3][i];
    a[3][i] = tmp;
}

void output(long long a, long long b) {
    double tmp = a * 1.0 / b;
    if (tmp > - 0.0005 && tmp < 0.0005) printf("0.000");
    else printf("%.3lf", tmp);
}

int main() {
    int n;
    long long c, d, e, f;
    scanf("%d", &n);
    while (n--) {
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j) scanf("%lld", &a[i][j]);
            scanf("%lld", &b[i]);
        }
        c = det();
        swap(1);
        d = det();
        swap(1);
        swap(2);
        e = det();
        swap(2);
        swap(3);
        f = det();
        printf("%lld %lld %lld %lld\n", d, e, f, c);
        if (c) {
            printf("Unique solution: ");
            output(d, c);
            printf(" ");
            output(e, c);
            printf(" ");
            output(f, c);
            printf("\n\n");
        }
        else printf("No unique solution\n\n");
    }
}
