#include <stdio.h>
#include <cstring>

const int N = 1001;
char in[N];
int rest[N], rest1[N], res[N], remain, resf[N];

void divide(int num) {
    int tmp = rest[0], tmpn;
    memset(res, 0, sizeof(res));
    while (tmp<N-1) {
        if (rest[tmp]<num) {
            rest[tmp+1] += 10 * rest[tmp];
            tmp++;
        }
        else {
            tmpn = rest[tmp];
            res[tmp] = tmpn / num;
            rest[tmp+1] += (tmpn % num) * 10;
            tmp++;
        }
    }
    while (res[res[0]]==0&&res[0]<N-1) res[0]++;
    res[tmp] = rest[tmp] / num;
    remain = rest[tmp] % num;
}

int solve() {
    int a = 1, tmp, i;
    int value[] = {9, 8, 7, 6, 5, 2};
    while (1) {
        memcpy(rest, res, sizeof(res));
        if (rest[0]==N-1) {
            resf[resf[0]] = rest[N-1];
            break;
        }
        else {
            rest1[0] = rest[0];
            memcpy(rest1+rest[0], rest+rest[0], (N-rest[0]) * sizeof(int));
            for (int j=0; j<6; ++j) {
                i = value[j];
                divide(i);
                if (!remain) {
                    tmp = i;
                    break;
                }
                if (i==2&&remain) {
                    a = 0;
                    return a;
                }
                rest[0] = rest1[0];
                memcpy(rest+rest1[0], rest1+rest1[0], (N-rest1[0]) * sizeof(int));
            }
            resf[resf[0]] = tmp;
            resf[0]--;
        }
    }
    return a = 1;
}

int main() {
    int len;
    char num[10];
    while (scanf("%s", in)) {
        if (strlen(in)==2&&in[0]=='-'&&in[1]=='1') break;
        len = strlen(in);
        for (int i=N-1; i>=N-len; --i) rest[i] = in[i-N+len] - '0';
        rest[0] = N - len;
        memcpy(res, rest, sizeof(rest));
        resf[0] = N - 1;
        if (strlen(in)==1) printf("%d%d\n", 1, in[0] - '0');
        else {
            if (solve()) {
                for (int i=resf[0]; i<N; ++i) printf("%d", resf[i]);
                printf("\n");
            }
            else printf("There is no such number.\n");
        }
    }
}
