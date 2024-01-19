#include <stdio.h>
#include <cmath>

const int n = 20050;
int b[n] = {0}, p = 2, prime[1300];

void primelist(int num) {
    int tmp = 3;
    prime[1] = 2;
    prime[2] = 3;
    for (int i=2; i<num; i+=2) b[i] = 1;
    for (int i=3; i<num; i+=3) b[i] = 1;
    while (tmp<num) {
        if (!b[tmp]) {
            p++;
            prime[p] = tmp; 
            for (int i=tmp; i<num; i+=tmp) b[i] = 1;           
        }
        tmp++;
    }
}

int isPrime(int t) {
    int num = int(pow(t, 0.5));
    for (int i=1; prime[i]<=num; ++i) {
        if (t%prime[i]==0) return 0;
    }
    return 1;
}

int sum(int t) {
    int res = 0;
    while (t) {
        res += t % 10;
        t /= 10;
    }
    return res;
}

int smith_number(int t) {
    int res = 0, flag = 0, number = sum(t);
    int num = int(pow(t, 0.5));
    //printf("%d\n\n", num);
    while (1) {
        for (int i=1; i<=p; ++i) {
            if (t%prime[i]==0) {
                t /= prime[i];
                res += sum(prime[i]);
                if (t==1) return (res==number);
                //printf("%d\n", prime[i]);
                break;
            }
            if (i==p&&t%prime[i]!=0) {
                res += sum(t);
                //printf("%d\n", t);
                flag = 1;
            }
        }
        if (flag) break;
    }
    return res == number;
}

int main() {
    int innum;
    primelist(10000);
    while (scanf("%d", &innum)!=EOF) {
        if (!innum) break;
        else {
            while (1) {
                innum++;
                if (isPrime(innum)) continue;
                if (smith_number(innum)) {
                    printf("%d\n", innum);
                    break;
                }
            }
        }
    }  
}