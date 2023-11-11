//同余定理
//1234%m=(1*1000+2*100+3*10+4)%m=(((1*10+2)%m*10+3%m)*10+4)%m
//create the list of prime

#include <stdio.h>
#include <cstring>

const int N = 250, n = 1000001, base = 1000;
char in[1001];
int rest[N], res[N], resf[N], remain;
int b[n] = {0}, p = 2, prime[100000];

void primel(int c) { 
    int tmp = prime[p];
    while (prime[p]<=c) {
        if (!b[tmp]) {
            prime[p+1] = tmp;
            for (int i=tmp; i<n; i+=tmp) b[i] = 1;
            p++;
        }
        tmp += 2;
    }
}

void divide(int b1, int num) {
    int tmp = rest[0], tmpn;
    res[0] = rest[0];
    while (tmp<N-1) {
        if (rest[tmp]<num) {
            rest[tmp+1] += b1 * rest[tmp];
            tmp++;
        }
        else {
            tmpn = rest[tmp];
            res[tmp] = tmpn / num;
            rest[tmp+1] += (tmpn % num) * b1;
            tmp++;
        }
    }
    while (res[res[0]]==0&&res[0]<N-1) res[0]++;
    res[tmp] = rest[tmp] / num;
    remain = rest[tmp] % num;
}

void convertion() {
    int pos = N - 1;
    while (!(res[0]==N-1&&res[res[0]]==0)) {
        memset(res, 0, sizeof(res));
        divide(10, base);
        resf[pos] = remain;
        memcpy(rest, res, sizeof(rest));
        pos--;
    }
    resf[0] = pos;
    while (resf[resf[0]]==0&&resf[0]<N-1) resf[0]++;
}

int cremain(int i) {
    if (rest[0]==N-1) return rest[N-1] % i;
    int res1 = rest[rest[0]], tmp = rest[0];
    while(tmp<N-1) {
        res1 = (res1 * base+ rest[tmp+1]) % i;
        tmp++;
    }
    return res1;
}

void solve(int a) {
    for (int i=1; i<=p; ++i) {
        if (prime[i]>=a) break;
        if (!cremain(prime[i])) {
            printf("BAD %d\n", prime[i]);
            return;
        }
    }
    printf("GOOD\n");
}

int main() {
    int num, len;
    prime[1] = 2;
    prime[2] = 3;
    for (int i=2; i<n; i+=2) b[i] = 1;
    for (int i=3; i<n; i+=3) b[i] = 1;
    while (scanf("%s%d", in, &num)!=EOF) {
        primel(num);
        memset(b, 0, num*sizeof(int));
        memset(res, 0, sizeof(res));
        if (strlen(in)==1&&in[0]=='0'&&num==0) break;
        len = strlen(in);
        for (int i=N-1; i>=N-len; --i) rest[i] = in[i-N+len]  - '0';
        rest[0] = N - len;
        convertion();
        memcpy(rest, resf, sizeof(rest));
        solve(num);
    }
}
