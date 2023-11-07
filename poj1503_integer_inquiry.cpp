#include <stdio.h>
#include <cstring>
#include <iostream>

const int N = 105;
char in[N];
int res[N], rest[N];

void plus() {
    int tmp, tmpn;
    int min = std::min(res[0], rest[0]);
    for (int i=N-1; i>=min; --i) {
        res[i] += rest[i];
        tmp = i;
        while (res[tmp]>9) {
            tmpn = res[tmp];
            res[tmp] = tmpn % 10;
            res[tmp-1] += tmpn / 10;
            tmp--;
        }
    }
    res[0] = min - 1;
    while (!res[res[0]]) res[0]++;
}

int main() {
    int len, tmp = 0;
    memset(res, 0, sizeof(res));
    res[0] = N - 1;
    while (scanf("%s", in)!=EOF) {
        if (strlen(in)==1&&in[0]=='0') break;
        len = strlen(in);
        tmp = len - 1;
        for (int i=N-1; i>=N-len; --i) rest[i] = int(in[tmp--] - '0');
        rest[0] = N - len;
        plus();
        memset(rest, 0, sizeof(rest));
    }
    for (int i=res[0]; i<N; ++i) printf("%d", res[i]);
}