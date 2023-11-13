#include <stdio.h>
#include <cstring>
#include <cmath>

int f[10];

void fuc() {
    for (int i=1; i<=8; ++i) {
        f[i] = (pow(10, i-1) + pow(10, i)) / 2;
        printf("%d", f[i]);
        printf("\n");
    }
}

int count(int a) {
    int res = 1;
    while (a) {
        a /= 10;
        res++;
    }
    return res;
}

int main() {
    fuc();
    int num;
    char in[10];
    scanf("%d", &num);
    printf("%d", count(num));
}