#include <stdio.h>
#include <cstring>

char a[20005], b[20005];
int out[2];

int baseto10(char k) {
    if (k >= '0' && k <= '9') return k - '0';
    else return 10 + k - 'A';
}

int baseto16(int k) {
    out[1] = k % 16;
    k /= 16;
    out[0] = k;
    for (int i = 0; i < 2; ++i) {
        if (out[i] >= 0 && out[i] <= 9) printf("%d", out[i]);
        else printf("%c", out[i] - 10 + 'A');
    }
    return out[0] * 16 + out[1];
}

int main() {
    scanf("%s%s", a, b);
    int x = 32, l = 0, bc, k;
    bc = baseto10(b[0]) * 16 + baseto10(b[1]);
    k = baseto16(bc ^ x);
    while (l < strlen(a)) {
        bc = baseto10(a[l]) * 16 + baseto10(a[l + 1]);
        bc ^= k;
        x = baseto10(b[l + 2]) * 16 + baseto10(b[l + 3]);
        k = baseto16(bc ^ x);
        l += 2;
        
    }
}