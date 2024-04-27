#include <stdio.h>
#include <cmath>

int main() {
    int n, m;
    scanf("%d", &n);
    double pi = 3.141592653589793238463, e = 2.7182818284590452354;
    while (n--) {
        scanf("%d", &m);
        if (m == 1) {
            printf("1\n");
            continue;
        }
        printf("%d\n", int(log10(sqrt(2 * pi * m)) + m * log10(m / e) + 1));
    }
}
