#include <stdio.h>

int main() {
    int a, b, c, tmp;
    for (int i = 2992; i < 10000; ++i) {
        tmp = i;
        a = 0;
        b = 0;
        c = 0;
        while (tmp) {
            a += tmp % 10;
            tmp /= 10;
        }
        tmp = i;
        while (tmp) {
            b += tmp % 12;
            tmp /= 12;
        }
        tmp = i;
        while (tmp) {
            c += tmp % 16;
            tmp /= 16;
        }
        if (a == b && a == c) printf("%d\n", i);
    }
}