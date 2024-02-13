#include <stdio.h>
#include <iostream>
using namespace std;

int f[5900], res = 1;

void solve() {
    int a = 1, b = 1, c = 1, d = 1;
    f[1] = 1;
    while (res<5900) {
        f[res+1] = min(min(f[a]*2, f[b]*3), min(f[c]*5, f[d]*7));
        res++;
        if (f[res]==f[a]*2) a++;
        if (f[res]==f[b]*3) b++;
        if (f[res]==f[c]*5) c++;
        if (f[res]==f[d]*7) d++;
    }
}

int main() {
    int n;
    solve();
    while (scanf("%d", &n)) {
        if (!n) break;
        printf("The %d", n);
        if (n%10==1&&n%100!=11) printf("st humble number is %d.\n", f[n]);
        else {
            if (n%10==2&&n%100!=12) printf("nd humble number is %d.\n", f[n]);
            else {
                if (n%10==3&&n%100!=13) printf("rd humble number is %d.\n", f[n]);
                else printf("th humble number is %d.\n", f[n]);
            }
        }
    }
}