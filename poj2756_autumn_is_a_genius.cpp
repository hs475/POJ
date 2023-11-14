#include <stdio.h>
#include <cstring>


const int N = 100000;
int a[N], b[N];
char in[N];
int p1, p2, len1, len2;

void sum(int s[], int t[], int k, int g) {
    int out = g, tmp;
    for (int i=k; i>=0; --i) {
        t[g] += s[i];
        tmp = g;
        while (t[tmp]>9&&tmp>0) {
            t[tmp-1] += t[tmp] / 10;
            t[tmp] %= 10;
            tmp--;
        }
        g--;
    }
    if (t[0]>9) {
        if (!p1) printf("-");
        printf("%d", t[0]/10);
        t[0] %= 10;
        for (int i=0; i<=out; ++i) printf("%d", t[i]);
    } 
    else {
        if (!p1) printf("-");
        for (int i=0; i<=out; ++i) printf("%d", t[i]);
    }
    printf("\n");
}

int big() {
    if (len1>len2) return 0;
    if (len2>len1) return 1;
    for (int i=0; i<=len1; ++i) {
        if (a[i]>b[i]) return 0;
        if (a[i]<b[i]) return 1;
    }
    return 2;
}

void substraction(int a[], int b[], int k, int g) {
    int out = g, tmp;
    for (int i=k; i>=0; --i) {
        if (b[g]>=a[i]) b[g] -= a[i];
        else {
            tmp = g - 1;
            b[g] = 10 + b[g] - a[i];
            while (!b[tmp]) {
                b[tmp] = 9;
                tmp--;
            }
            b[tmp]--;
        }
        g--;
    }
    int start = 0;
    while (!b[start]) start++;
    for (int i=start; i<=out; ++i) printf("%d", b[i]);
    printf("\n");
}

void solve() {
    if (p1==p2) {
        if (len1>len2) sum(b, a, len2, len1);
        else sum(a, b, len1, len2);
        return;
    }
    else {
        int tmp = big();
        if (tmp==2) printf("0\n");
        if (tmp==1) {
            if (!p2) printf("-");
            substraction(a, b, len1, len2);
        }
        if (tmp==0) {
            if (!p1) printf("-");
            substraction(b, a, len2, len1); 
        }
        return;
    }
}

int main() {
    int n, tmp;
    scanf("%d", &n);
    getchar();
    for (int i=0; i<n; ++i) {
        p1 = 0;
        p2 = 0;
        tmp = 0;
        scanf("%s", in);
        len1 = strlen(in) - 1;
        if (in[0]!='-') p1 = 1;
        if (in[0]=='+'||in[0]=='-') {
            len1--;
            tmp = 1;
        }
        for (int i=tmp; i<strlen(in); ++i) {
            a[i-tmp] = in[i] - '0';
        }
        tmp = 0;
        scanf("%s", in);
        len2 = strlen(in) - 1;
        if (in[0]!='-') p2 = 1;
        if (in[0]=='+'||in[0]=='-') {
            len2--;
            tmp = 1;
        }
        for (int i=tmp; i<strlen(in); ++i) {
            b[i-tmp] = in[i] - '0';
        }
        solve();
    }
}