#include <stdio.h>
#include <cmath>
#include <cstring>

int p[6000], b[45000], t = 2;

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

void prime() {
    p[1] = 2;
    for (int i = 2; i <= 45000; i += 2) b[i] = 1;
    for (int i = 3; i <= 45000; ++i) {
        if (!b[i]) {
            p[t] = i;
            t++;
            for (int j = i; j <= 45000; j += i) b[j] = 1;
        }
    }
}

int factorization(long long n) {
    int res = 0, flag = 0, ans;
    if (n < 0) {
        n *= -1;
        flag = 1;
    }
    printf("%lld\n", n);
    for (int i = 1; i < t; ++i) {
        ans = 0;
        if (n == 1) break;
        while (n % p[i] == 0) {
            n /= p[i];
            ans++;
        }
        if (!ans) continue;
        if (flag) while (ans % 2 == 0) ans /= 2;
        res = gcd(res, ans);
    }
    if (n != 1) return 1;
    else return res;
}

int main() {
    long long n;
    prime();
    while (1) {
        scanf("%lld", &n);
        if (n == 0) break;
        printf("%d\n", factorization(n));
    }
}