#include <stdio.h>
#include <cstring>

char f[10], d[10];

int ten(char a) {
    if (a >= '0' && a <= '9') return a - '0';
    else return 10 + a - 'A';
}

char tenrev(int a) {
    if (a >= 0 && a <= 9) return a + '0';
    return 'A' + a - 10;
}

int basetoten(int a) {
    int res = 0;
    for (int i = 0; i < strlen(f); ++i) {
        res = res * a + ten(f[i]);
    }
    return res;
}

void baserev(int res, int b) {
    int p = 0;
    while (res) {
        d[p] = tenrev(res % b);
        res /= b;
        p++;
    }
    d[p] = '\0';
}



int main() {
    int a, b;
    while (scanf("%s%d%d", f, &a, &b) != EOF) {
        baserev(basetoten(a), b);
        if (strlen(d) > 7) {
            printf("  ERROR\n");
            continue;
        }
        for (int i = 0; i + strlen(d) < 7; ++i) printf(" ");
        for (int i= strlen(d) - 1; i >= 0; --i) printf("%c", d[i]);
        printf("\n");
    }
}