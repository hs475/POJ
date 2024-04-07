#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <iostream>

int t = 0;
char f[20], a[20];

void solve() {
    int flag = t;
    int b = std::min(strlen(a), strlen(f));
    for (int i = 0; i <= t; ++i) {
        if (f[i] != a[i]) {
            flag = i - 1;
            break;
        }
    }
    if (flag == t) t++;
    else if (flag <= t - 1) t = flag + 1; 
    t = std::min(t, b);
    for (int i = 0; i < t; ++i) printf(" ");
    printf("%s\n", f);
    memcpy(a, f, sizeof(a));
}

int main() {
    scanf("%s", a);
    printf("%s\n", a);
    while (scanf("%s", f) != EOF) {
        solve();
    }
}
