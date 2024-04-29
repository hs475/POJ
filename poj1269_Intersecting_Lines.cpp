#include <stdio.h>

int a[2], b[2], c[2];
double x, y;

void line(int x1, int y1, int x2, int y2, int t) {
    if (x1 == x2) {
        a[t] = 1;
        b[t] = 0;
        c[t] = -x1;
        return;
    }
    if (y1 == y2) {
        a[t] = 0;
        b[t] = 1;
        c[t] = -y1;
        return;
    }
    a[t] = y1 - y2;
    b[t] = x2 - x1;
    c[t] = -1 * x1 * a[t] - b[t] * y1;
    return;
}

void solve() {
    if ((a[0] * b[1] - a[1] * b[0]) == 0) {
        if ((a[0] == 0 && b[0] * c[1] - b[1] * c[0] == 0) \
        || (b[0] == 0 && a[0] * c[1] - a[1] * c[0] == 0) || \
        (a[0] != 0 && b[0] != 0 && a[0] * c[1] - a[1] * c[0] == 0)) printf("LINE\n");
        else printf("NONE\n");
    }
    else {
        x = (c[1] * 1.0 * b[0] - c[0] * b[1]) / (a[0] * b[1] - a[1] * b[0]);
        y = (a[0] * c[1] * 1.0 - a[1] * c[0]) / (a[1] * b[0] - a[0] * b[1]);
        printf("POINT %.2f %.2f\n", x, y);
    }
    return;
}

int main() {
    int n, x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d", &n);
    printf("INTERSECTING LINES OUTPUT\n");
    while (n--) {
        scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        line(x1, y1, x2, y2, 0);
        line(x3, y3, x4, y4, 1);
        solve();
    }
    printf("END OF OUTPUT");
}