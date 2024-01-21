#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>

const int N = 65536;
int phi[N];

//void primelist(int n) {
//    int tmp = 4;
//    while (tmp<N) {
//        if (!b[tmp]) {
//            p++;
//            prime[p] = tmp;
//            for (int i=tmp; i<N; i+=tmp ) b[i] = 1;
//        }
//        tmp++;
//    }    
//}

void root(int p) {
    for (int i=0; i<N; ++i) phi[i] = i;
    for (int i=2; i<N; ++i) {
        if (phi[i]==i) {
            for (int j=i; j<N; j+=i) phi[j] = phi[j] / i * (i - 1);
        }
    }

}

int main() {
    int n;
    root(N);
    while (scanf("%d", &n)!=EOF) {
        printf("%d\n", phi[n-1]);
    }
}
