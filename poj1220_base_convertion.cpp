#include <stdio.h>
#include <string.h>
#include <math.h>

char a[1001];
int in[1001], rest[1001], res[1001], resf[1001];
int len, base1, base2, remain;

int num(char a) {
    if (a>=65&&a<=90) return int(a-'A'+10);
    else {
        if (a>=97&&a<=122) return int(a-'a'+36);
        else return int(a-'0');
    } 
    return 0;
}

char letter(int a) {
    if (a>=0&&a<=9) return char(a+'0');
    else {
        if (a>=10&&a<=35) return char('A'+a-10);
        else return char('a'+a-36);
    }
}

void devide(int b1, int num) {
    int tmp = rest[0], tmpn;
    while (tmp<1000) {
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
    while (res[res[0]]==0&&res[0]<1000) res[0]++;
    res[tmp] = rest[tmp] / num;
    remain = rest[tmp] % num;
}

void convertion() {
    int pos = 1000;
    memcpy(rest, in, sizeof(res));
    memcpy(res, in, sizeof(res));
    while (!(res[0]==1000&&res[res[0]]==0)) {
        memset(res, 0, sizeof(res));
        devide(base1, base2);
        resf[pos] = remain;
        memcpy(rest, res, sizeof(rest));
        pos--;
    }
    resf[0] = pos;
    while (resf[resf[0]]==0&&resf[0]<1000) resf[0]++;
}

int main() {
    int outnum = 0;
    scanf("%d", &outnum);
    for (int i=0; i<outnum; ++i) {
        memset(resf, 0, sizeof(resf));
        scanf("%d%d%s", &base1, &base2, a);
        len = strlen(a);
        for (int i=1000; i>=1001-len; --i) in[i] = num(a[i-1001+len]);
        in[0] = 1001 - len;
        convertion();
        printf("%d ", base1);
        for (int i=0; i<len; ++i) printf("%c", a[i]);
        printf("\n%d ", base2);
        for (int i=resf[0]; i<=1000; ++i) printf("%c", letter(resf[i]));
        printf("\n\n");
    }
}
