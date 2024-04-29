#include <stdio.h>
#include <cmath>

int main() {
    long long a, b, t, m, n;
    scanf("%lld", &a);
    for (long long i = a; i >= 1; --i) {
        if ((a * a + 1) % i == 0) {
            m = i;
            break;
        }
    }
    n = (a * a + 1) / m;
    printf("%d", 2 * a + m + n);
}