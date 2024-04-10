#include <stdio.h>

const int N = 1000000;
int f[N];

int main() {
    int a;
    scanf("%d", &a);
    for (int i = 1; ; ++i) {
        a = a / 10 % 10000;
        a *= a;
        a %= N;
        if (f[a]) {
            printf("%d %d %d\n", a, i - f[a], i);
            break;
        }
        f[a] = i;
    }
}