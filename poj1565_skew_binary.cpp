#include <stdio.h>
#include <string.h>

const int N = 2001;
int max = 2147483647;
char a[N];
int in[N], rest[N], res[N], resf[N];
int len, remain, r = 0, minus;

void devide(int b1, int num) {
    int tmp = rest[0], tmpn;
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
    int pos = N - 1, tmp, tmpn;
    minus = 0;
    memcpy(rest, in, sizeof(res));
    res[0] = in[0];
    while (!(res[0]==N-1&&res[res[0]]==0)) {
        memset(res, 0, sizeof(res));
        devide(2, 10);
        resf[pos] = remain;
        memcpy(rest, res, sizeof(rest));
        pos--;
    }
    resf[0] = pos;
    while (resf[resf[0]]==0&&resf[0]<N-1) resf[0]++;
    tmp = 1;
    for (int i=N-1; i>=resf[0]; --i) {
        r += tmp * resf[i];
        tmp *= 10;
    }
    for (int i=in[0]; i<N; ++i) minus += in[i];
    r  = r - minus + r;
}

int main() {
    while (scanf("%s", a)!=EOF) {
        r = 0;
        if (strlen(a)==1&&a[0]=='0') break;
        if (strlen(a)==1) {
            r = a[0] - '0';
            printf("%d\n", r);
            continue;
        }
        memset(resf, 0, sizeof(resf));
        len = strlen(a);
        for (int i=N-1; i>=N-len; --i) in[i] = a[i-N+len] - '0';
        in[0] = N - len;
        convertion();
        printf("%d\n", r);
    }
}