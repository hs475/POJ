#include <stdio.h>
#include <cmath>

long long gcd(long long a, long b) {return b == 0 ? a : gcd(b, a % b);}

int main() {
    long long a, b, t, j ,p1, p2;
    while (scanf("%lld%lld", &a, &b) != EOF) {
        p1 = 600000;
        p2 = 1;
        t = gcd(a, b);
        a /= t;
        b /= t;
        long long tmp = a / b;
        for (long long i = 1; i <= b; ++i) {
            for (j = tmp * i;; ++j) {
                if ((j * b <= a * i) && ((j + 1) * b >= a * i)) break;
            } 
            if (2 * a * i >= b * (2 * j + 1) && (((j + 1) * b - a * i) * p2) < p1 * i * b) {
                printf("%lld/%lld\n", j + 1, i);
                p1 = (j + 1) * b - a * i;
                p2 = i * b;
                t = gcd(p1, p2);
                p1 /= t;
                p2 /= t;
                continue;
            }
            if (2 * a * i < b * (2 * j + 1) && (a * i - b * j) * p2 < p1 * b * i) {
                printf("%lld/%lld\n", j, i);
                p1 = a * i - b * j;
                p2 = b * i;
                t = gcd(p1, p2);
                p1 /= t;
                p2 /= t;
                continue;
            }
        }
        printf("\n");
    }
}