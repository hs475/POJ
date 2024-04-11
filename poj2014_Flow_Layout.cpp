#include <stdio.h>
#include <iostream>

int main() {
    int n, a, b, w, h, maxw, maxh;
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        maxw = 0;
        maxh = 0;
        w = 0;
        h = 0;
        while (scanf("%d%d", &a, &b)) {
            if (a == -1) {
                maxh += h;
                break;
            }
            if (a + w <= n) {
                maxw = std::max(maxw, a + w);
                w += a;
                h = std::max(h, b);
            }
            else {
                maxh += h;
                w = 0;
                h = 0;
                w += a;
                maxw = std::max(maxw, a);
                h = std::max(h, b);
            }
        }
        printf("%d x %d\n", maxw, maxh);
    }
}