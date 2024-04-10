#include <stdio.h>

int main() {
    int a, b, c, d, sum;
    while (1) {
        sum = 1080;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (!a && !b && !c && !d) break;
        sum += ((40 + a - b) % 40) * 9;
        sum += ((40 + c - b) % 40) * 9;
        sum += ((40 + c - d) % 40) * 9;
        printf("%d\n", sum);
    }
}