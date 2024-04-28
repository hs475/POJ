#include <stdio.h>
#include <cmath>

int main() {
    int n, t, res;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        res = 0;
        while (t >= 5) {
            res += t / 5;
            t /= 5;
        }
        printf("%d\n", res);
    }
}