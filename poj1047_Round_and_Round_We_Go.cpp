#include <stdio.h>
#include <cstring>

char in[200];
const int N = 100;
int num[N], res[N];

void multi(int n) {
    int tmp;
    memset(res, 0, sizeof(res));
    res[0] = num[0];
    for (int i=N-1; i>=num[0]; --i) {
        res[i] += num[i] * n;
        tmp = i;
        while (res[tmp]>9) {
            res[tmp-1] += res[tmp] / 10;
            res[tmp] %= 10;
            tmp--;
        }
    }  
    while(res[res[0]-1]) res[0]--;  
}

int cycle(int len) {
    int a, b;
    //printf("%d\n", res[0]);
    for (int i=2; i<=len; ++i) {
        multi(i);
        //printf("%d\n", res[0]);
        if (num[0]!=res[0]) return 0;
        //printf("multi%d\n", i);
        //for (int b=res[0]; b<=N-1; ++b) printf("%d", res[b]);
        //printf("\n");
        int flag = 0;
        for (int k=N-1; k>=num[0]; --k) {
            a = N - 1;
            b = k;
            //printf("k---%d\n", k);
            for (int j=0; j<len; ++j) {
                if (num[a]!=res[b]) {
                    //printf("%d %d\n", a, b);
                    break;
                }
                if (j==len-1&&num[a]==res[b]) flag = 1;
                a--;
                b--;
                if (a<res[0]) {
                    //printf("%d %d\n", a, res[0]);
                    a += len;
                }
                if (b<res[0]) b += len;
            } 
            //printf("%d", 333);
            if (flag) break;          
        }
        if (!flag) return 0;
    }
    return 1;
}

int main() {
    int len;
    while (scanf("%s", in)!=EOF) {
        memset(num, 0, sizeof(num));
        len = strlen(in);
        //printf("%d\n", len);
        num[0] = N - len;
        for (int i=num[0]; i<=N-1; ++i) num[i] = in[i-num[0]] - '0';
        for (int i=num[0]; i<=N-1; ++i) printf("%d", num[i]);
        if (cycle(len)) printf(" is cyclic\n");
        else printf(" is not cyclic\n");
    }
}