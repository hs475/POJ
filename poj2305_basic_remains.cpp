#include <stdio.h>
#include <cstring>
#include <cmath>

const int N = 1001;
char in[N];
int rest[N], res[N], remain, resf[50];

void divide(int b1, int num) {
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
    tmp = 49;
    memset(resf, 0, sizeof(resf));
    resf[0] = 49;
    while (remain) {
        resf[tmp] = remain % b1;
        remain /= b1;
        resf[0] = tmp;
        tmp--;
    }
}

int main() {
    int base, len, n;
    char num[10];
    while (scanf("%d", &base)) {
        if (!base) break;
        scanf("%s%s", in, num);
        n = 0;
        len = strlen(in);
        memset(res, 0, sizeof(res));
        memset(rest, 0, sizeof(rest));
        for (int i=1000; i>=1001-len; --i) rest[i] = in[i-1001+len] - '0';
        rest[0] = 1001 - len;
        len = strlen(num);
        for (int i=len-1; i>=0; --i) n += pow(base, len - i - 1) * (num[i] - '0');
        divide(base, n);
        for (int i=resf[0]; i<50; ++i) printf("%d", resf[i]);
        memset(num, '0', sizeof(num));
        printf("\n");
    }
}
