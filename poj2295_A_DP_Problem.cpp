#include <stdio.h>
#include <cstring>
#include <cmath>

int x[2], a[2];
char f[300];

int match(int k, int i) {
    int c, flag = 1;
    while (f[k] != '=' && k < strlen(f)) {
        c = 0;
        while (f[k] >= '0' && f[k] <= '9') {
            c = c * 10 + f[k] - '0';
            k++;
        }
        if (f[k] == 'x') {
            if (c == 0 && (f[k - 1] < '0' || f[k - 1] > '9')) c = 1;
            x[i] += c * flag;
            k++;
        }
        else a[i] += c * flag;
        if (f[k] == '+' || f[k] == '-') {
            if (f[k] == '+') flag = 1;
            else flag = -1;
            k++;
        }
    }
    return k;
}

void solve() {
    memset(x, 0, sizeof(x));
    memset(a, 0, sizeof(a));
    int k = 0;
    scanf("%s", f);
    k = match(k, 0);
    k++;
    match(k, 1);
    if (x[0] == x[1]) {
        if (a[0] == a[1]) printf("IDENTITY\n");
        else printf("IMPOSSIBLE\n");
    }
    else printf("%d\n", int(floor((double(a[1]) - a[0]) / (x[0] - x[1]))));
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) solve();
}