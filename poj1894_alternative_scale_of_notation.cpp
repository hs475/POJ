#include <stdio.h>
#include <string.h>
#include <math.h>

const int N = 10001;
char a[N];
int in[N], rest[N], res[N], resf[N];
int len, base1, base2, remain;

void devide(int b1, int num) {
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
    if (!remain&&!(res[0]==N-1&&res[res[0]]==0)) {
        tmp = N - 1;
        while (!res[tmp]) {
            res[tmp] = b1 - 1;
            tmp--;
        }
        res[tmp]--;
        remain = num;
    }
}

void convertion() {
    int pos = N - 1, tmp;
    memcpy(rest, in, sizeof(res));
    memcpy(res, in, sizeof(res));
    while (!(res[0]==N-1&&res[res[0]]==0)) {
        memset(res, 0, sizeof(res));
        devide(base1, base2);
        resf[pos] = remain;
        memcpy(rest, res, sizeof(rest));
        pos--;
    }
    resf[0] = pos;
    while (resf[resf[0]]==0&&resf[0]<N-1) resf[0]++;
}

int main() {
    memset(resf, 0, sizeof(resf));
    scanf("%d%s", &base2, a);
    base1  = 10;
    len = strlen(a);
    for (int i=N-1; i>=N-len; --i) in[i] = a[i-N+len]  - '0';
    in[0] = N - len;
    convertion();
    if (len==1&&in[N-1]==0) printf(" ");
    else for (int i=resf[0]; i<=N-1; ++i) printf("%d", resf[i]);
}