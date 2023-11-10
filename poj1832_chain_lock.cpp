//Gray code
//The first step is to change the rightmost bit value;
//The second step is to change the bit to the left of the 
//first bit from the right that is 1.

//change gray code to binary, and calculate the difference.

//由二进制数转换为格雷码：从右到左检查，如果某一数字左边是0，
//该数字不变；如果是1，该数字改变

//由格雷码表示变为二进制数：从右到左检查，如果某一数字的左边
//数字和是偶数，该数字不变；如果是奇数，该数字改变。

#include <stdio.h>
#include <cstring>
#include <math.h>

const int N = 130;
int g1[N], g2[N], tmpl[N], res[N], rest[N], resf[N], remain;

void togray(int a[], int num) { 
    int sum = 0;
    for (int i=N-num; i<N-1; ++i) sum += a[i];
    for (int i=N-1; i>N-num; --i) {
        if (sum%2) a[i] = (a[i] + 1) % 2;
        sum -= a[i-1];
    }
}

void minus() {
    int a = 0, tmp, tmpn;
    for (int i=g1[0]; i<N; ++i) {
        if(g1[i]>g2[i]) {
            a = 1;
            break;
        }
        else {
            if (g1[i]<g2[i]) {
                a = 0;
                break;
            }
            else continue;
        }
    }
    if (!a) {
        memcpy(tmpl, g1, sizeof(g1));
        memcpy(g1, g2, sizeof(g1));
        memcpy(g2, tmpl, sizeof(g2));
    }
    for (int i=N-1; i>=g1[0]; --i) {
        if (g1[i]>=g2[i]) g1[i] -= g2[i];
        else {
            tmp = i;
            while (!g1[tmp]) {
                g1[tmp] = 1;
                tmp--;
            }
            g1[tmp] = 0;
        }              
    }
    while (!g1[g1[0]]) g1[0]++;
}

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
    int pos = N - 1;
    memcpy(rest, g1, sizeof(res));
    memcpy(res, g1, sizeof(res));
    while (!(res[0]==N-1&&res[res[0]]==0)) {
        memset(res, 0, sizeof(res));
        devide(2, 10);
        resf[pos] = remain;
        memcpy(rest, res, sizeof(rest));
        pos--;
    }
    resf[0] = pos;
    while (resf[resf[0]]==0&&resf[0]<N-1) resf[0]++;
}

int main() {
    int num, n;
    scanf("%d", &n);
    for (int j=0; j<n; ++j) {
        scanf("%d", &num);
        for (int i=N-num; i<N; ++i) scanf("%d", &g1[i]);
        g1[0] = N - num;
        togray(g1, num);
        for (int i=N-num; i<N; ++i) scanf("%d", &g2[i]);
        g2[0] = N - num;
        togray(g2, num);
        minus();
        convertion();
        for (int i=resf[0]; i<N; ++i) printf("%d", resf[i]);
        printf("\n");
        memset(g1, 0, sizeof(g1));
        memset(g2, 0, sizeof(g2));
        memset(resf, 0, sizeof(resf));
    }
}