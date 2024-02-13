#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int isPrime(int n) {
    for (int i=2; i<=sqrt(n); ++i) if (n%i==0) return 0;
    return 1;
}

void solve(int n) {
    for (int i=3; i<=n/2; i+=2) {
        if (isPrime(i)&&isPrime(n-i)) {
            printf("%d = %d + %d\n", n, i, n - i);
            return;
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n)!=EOF) {
        solve(n);
    }
}