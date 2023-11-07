//notice the number can contain more than 500 digits

#include <stdio.h>
#include <cstring>

const int N = 1005;
char in[N];
int a[N];

int main() {
    int len, tmp, res, tmpn;
    while (scanf("%s", in)!=EOF) {
        res = 10;
        if (strlen(in)==1&&in[0]=='0') break;
        len = strlen(in);
        tmp = 0;
        for (int i=N-1; i>=N-len; --i) a[i] = int(in[tmp++] - '0');
        a[0] = N - len;
        while (res>9) {
            res = 0;
            for (int i=a[0]; i<N; ++i) res += a[i];
            tmp = N - 1;
            a[0] = N-1;
            a[tmp] = res;
            while (a[tmp]>9) {
                a[0]--;
                tmpn = a[tmp];
                a[tmp] = tmpn % 10;
                a[tmp-1] = tmpn / 10;
                tmp--;
            }
        }
        memset(a, 0, sizeof(a));
        memset(in, '0', sizeof(in));
        printf("%d\n", res);
    }
}
