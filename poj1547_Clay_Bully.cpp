#include <stdio.h>
#include <cstring>

int f[20];
char name[20][10];

int main() {
    int n, sum, a, b, c, p1, p2;
    while (scanf("%d", &n)) {
        if (n == -1) break;
        sum = 0;
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%s", &a, &b, &c, name[i]);
            f[i] = a * b * c;
            sum += f[i];
        }
        sum /= n;
        for (int i = 0; i < n; ++i) {
            if (f[i] < sum) p2 = i;
            if (f[i] > sum) p1 = i;
        }
        printf("%s took clay from %s\n", name[p1], name[p2]);
    }
}