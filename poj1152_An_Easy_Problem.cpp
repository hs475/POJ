#include <stdio.h>
#include <cstring>

char f[100000];

int tranc(char a) {
    if (a >= '0' && a <= '9') return a - '0';
    if (a >= 'A' && a <= 'Z') return 10 + a - 'A';
    if (a >= 'a' && a <= 'z') return 36 + a - 'a';
    return -1;
}

int remainder(int base, int div) {
    int res = 0;
    for (int i = 0; i < strlen(f); ++i) {
        res = (res * base + tranc(f[i])) % div;
    }
    return res;
} 

void solve(int max) {
    for (int i = max + 1; i <= 62; ++i) {
        if (remainder(i, i - 1) == 0) {
            printf("%d\n", i);
            return;
        }
    }
    printf("such number is impossible!\n");
    return;
}

int main() {
    int n, max;
    char t;
    while (scanf("%s", f) != EOF) {
        max = 0;
        for (int i = 0; i < strlen(f); ++i) if (tranc(f[i]) > max) max = tranc(f[i]);
        solve(max);
    }
}