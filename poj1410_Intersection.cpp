#include <stdio.h>
#include <iostream>

int a[2], b[2], c[2];
int x1, y11, x2, y2, lx, ly, rx, ry, tmp;
double x, y;

void line(int x1, int y11, int x2, int y2, int t) {
    if (x1 == x2) {
        a[t] = 1;
        b[t] = 0;
        c[t] = -1 * x1;
        return;
    }
    if (y11 == y2) {
        a[t] = 0;
        b[t] = 1;
        c[t] = -1 * y11;
        return;
    }
    a[t] = y11 - y2;
    b[t] = x2 - x1;
    c[t] = -1 * x1 * a[t] - b[t] * y11;
    return;  
}

void solve(int lx, int ly, int rx, int ry) {
    if ((a[0] * b[1] - a[1] * b[0]) == 0) {
        if (b[0] == 0) {
            if (c[0] * a[1] == c[1] * a[0]) {
                if (std::min(y11, y2) > std::max(ly, ry) || std::max(y11, y2) < std::min(ly, ry)) {
                    x = 10000000;
                    y = 10000000;
                    return;
                }
                else {
                    x = rx;
                    y = ry;
                    return;
                }
            }
            else {
                x = 1000000;
                y = 1000000;
                return;
            }
        }
        if (a[0] == 0) {
            if (c[0] * b[1] == c[1] * b[0]) {
                if (std::min(x1, x2) > std::max(lx, rx) || std::max(x1, x2) < std::min(lx, rx)) {
                    x = 10000000;
                    y = 10000000;
                    return;
                }
                else {
                    x = rx;
                    y = ry;
                    return;
                }
            }
            else {
                x = 1000000;
                y = 1000000;
                return;
            }
        }
    }
    x = (c[1] * 1.0 * b[0] - c[0] * b[1]) / (a[0] * b[1] - a[1] * b[0]);
    y = (a[0] * c[1] * 1.0 - a[1] * c[0]) / (a[1] * b[0] - a[0] * b[1]);
    return;
}

int inl(int x1, int y1, int x2, int y2, double a, double b) {
    if (std::min(x1, x2) <= a && a <= std::max(x1, x2) && std::min(y1, y2) <= b && b <=std::max(y1, y2)) return 1;
    return 0;
}

int main() {
    int n, e, f, d, g;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d%d", &x1, &y11, &x2, &y2);
        scanf("%d%d%d%d", &e, &f, &d, &g);
        lx = std::min(e, d);
        rx = std::max(e, d);
        ly = std::max(f, g);
        ry = std::min(f, g);
        line(x1, y11, x2, y2, 0);
        line(lx, ly, rx, ly, 1);
        solve(lx, ly, rx, ry);
        if (inl(x1, y11, x2, y2, x, y) && inl(lx, ly, rx, ly, x, y)) {
            printf("T\n");
            continue;
        }

        line(rx, ry, rx, ly, 1);
        solve(lx, ly, rx, ry);
        if (inl(x1, y11, x2, y2, x, y) && inl(rx, ry, rx, ly, x, y)) {
            printf("T\n");
            continue;
        }
        line(lx, ry, rx, ry, 1);
        solve(lx, ly, rx, ry);
        if (inl(x1, y11, x2, y2, x, y) && inl(lx, ry, rx, ry, x, y)) {
            printf("T\n");
            continue;
        }
        line(lx, ry, lx, ly, 1);
        solve(lx, ly, rx, ry);
        if (inl(x1, y11, x2, y2, x, y) && inl(lx, ry, lx, ly, x, y)) {
            printf("T\n");
            continue;
        }
        if (std::min(x1, x2) >= lx && std::max(y11, y2) <= ly && std::max(x1, x2) <= rx && std::min(y11, y2) >= ry) {
            printf("T\n");
            continue;
        }
        printf("F\n");
    }
}