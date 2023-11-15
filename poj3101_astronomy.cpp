#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cmath>

const int N1 = 10001, base = 10000, N = 100001;
int prime[2][N1] = {0}, res[N], gcd;
int p[1229], tmpp = 1228, b[10100], pt = 0;

int Gcd(int a, int b) {
    int res = std::min(a, b);
    while (a%b!=0) {
        res = a % b;
        a = b;
        b = res;
    }
    return res;
}

void multi(int a) {
    for (int i=N-1; i>=res[0]; --i) res[i] *= a;
    for (int i=N-1; i>=res[0]; --i) {
        if (res[i]>base-1) {
            res[i-1] += res[i] / base;
            res[i] %= base;
        }
    }
    while (res[res[0]-1]) res[0]--;
}

void primel(int c) { 
    int tmp = 3;
    prime[0][0] = 2;
    for (int i=2; i<=10000; i+=2) b[i] = 1;
    while (prime[0][pt]<=9967) {
        if (!b[tmp]) {
            prime[0][pt+1] = tmp;
            for (int i=tmp; i<10010; i+=tmp) b[i] = 1;
            pt++;
        }
        tmp += 2;
    }
    tmpp = pt;
}

void primefacL(int n) {
    int tmp = 0, t = 1;
    while (t) {
        t = 0;
        for (int i=tmp; i<1229; ++i) {
            if (!(n%prime[0][i])) {
                n /= prime[0][i];
                p[i]++;
                tmp = i;
                t = 1;
                break;
            }
        }
    } 
    for (int i=0; i<1229; ++i) if (p[i]>prime[1][i]) prime[1][i] = p[i];
    for (int i=1228; i<=tmpp; ++i) {
        if (prime[0][i]==n) break;
        if (i==tmpp&n!=1) {
            tmpp++;
            prime[0][tmpp] = n;
            prime[1][tmpp] = 1;
        }
    }
}

void primefacG(int n) {
    int tmp = 0, t = 1;
    while (t) {
        t = 0;
        for (int i=tmp; i<1229; ++i) {
            if (!(n%prime[0][i])) {
                n /= prime[0][i];
                p[i]++;
                tmp = i;
                t = 1;
                break;
            }
        }
    } 

    for (int i=0; i<1229; ++i) {
        if (p[i]&&prime[1][i]) {
            tmp = std::min(p[i], prime[1][i]);
            prime[1][i] -= tmp;
            for (int j=0; j<tmp; ++j) gcd /= prime[0][i];
        }
        
    }
    for (int i=1228; i<=tmpp; ++i) {
        if (prime[0][i]==n) {
            prime[1][i]--;
            gcd /= n;
        }
    }
}

int main() {
    int n, t0, t, GCD, b0 = 0;
    primel(10008);
    scanf("%d%d", &n, &t0);
    n--;
    while (scanf("%d", &t)) {
        if (t==t0) {
            n--;
            if (n==0) break;
            continue;
        }
        else {
            n--;
            b0 = 1;
            GCD = Gcd(t * t0, 2 * abs(t - t0));
            primefacL(t*t0 / GCD);
            gcd = abs(2 * (t0 - t)) / GCD;
            break;
        }
    }
    if (!b0) {
        printf("%d %d", 0, 0);
        return 0;
    } 
    memset(p, 0, sizeof(p));
    while (n--) {
        scanf("%d", &t);
        if (t==t0) continue;
        GCD = Gcd(t * t0, 2 * abs(t - t0));
        primefacL(t * t0 / GCD);
        gcd = Gcd(gcd, abs(2 * (t - t0)) / GCD);
        memset(p, 0, sizeof(p));
    }
    res[N-1] = 1;
    res[0] = N - 1;
    int ttt = gcd;
    primefacG(ttt);
    for (int i=0; i<=tmpp; ++i) {
        if (prime[1][i]) {
            while (prime[1][i]) {
                prime[1][i]--;
                multi(prime[0][i]);
            }
        }
    }
    printf("%d", res[res[0]]);
    for (int i=res[0]+1; i<N; ++i) printf("%04d", res[i]);
    printf(" %d\n", gcd);
}