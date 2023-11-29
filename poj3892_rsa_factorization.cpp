#include <stdio.h>
#include <cstring>
#include <iostream>

const int N = 121, base = 100;
char in2[N];
int tmp[N];
int rest[N], res[N], rest1[N], a[N], b[N], remain[N], at[N], vt[N], ten[N], rr, kk[N];

void plus(int a[], int b) {
    a[N-1] += b;
    int tmp = N - 1;
    while (a[tmp]>base-1) {
        a[tmp-1] += a[tmp] / base;
        a[tmp] %= base;
        tmp--;
    }
    while (a[a[0]-1]) a[0]--;
}

void plus1(int a[], int b[]) {
    if (a[0]>b[0]) a[0] = b[0];
    a[0]--;
    for (int i=a[0]; i<N; ++i) a[i] += b[i];
    for (int i=N-1; i>=a[0]; --i) {
        if (a[i]>base-1) {
            a[i-1] += a[i] / base;
            a[i] %= base;
        }
    }
    while (!a[a[0]]) a[0]++;
}

void minus(int g1[], int g2[]) {
    int tmp;
    for (int i=N-1; i>=g1[0]; --i) {
        if (g1[i]>=g2[i]) g1[i] -= g2[i];
        else {
            g1[i] = g1[i] + base - g2[i];
            tmp = i - 1;
            while (!g1[tmp]) {
                g1[tmp] = base - 1;
                tmp--;
            }
            g1[tmp]--;
        }              
    }
    while (!g1[g1[0]]&&g1[0]<N-1) g1[0]++;
}

void mul1(int a[], int b) {
    memset(res, 0, sizeof(res));
    res[0] = a[0] - 5;
	for (int j=N-1; j>=res[0]; j--) res[j] = a[j] * b;
	for (int i=N-1; i>=res[0]; --i) {
		if (res[i]>base-1) {
			res[i-1] += res[i] / base;
			res[i] %= base;
		}
	}
	while (!res[res[0]]&&res[0]<N-1) res[0]++;
}

void mul(int a[], int b) {
    a[0] = a[0] - 5;
	for (int j=N-1; j>=a[0]; j--) a[j] *= b;
	for (int i=N-1; i>=a[0]; --i) {
		if (a[i]>base-1) {
			a[i-1] += a[i] / base;
			a[i] %= base;
		}
	}
	while (!a[a[0]]&&a[0]<N-1) a[0]++;
}

void multi(int a[], int b[]) {
    memset(res, 0, sizeof(res));
    res[0] = a[0] + b[0] - N;
	for (int j=N-1; j>=a[0]; j--) {
		for (int i=N-1; i>=b[0]; i--) {
			res[i-N+1+j] += b[i] * a[j];
		}
	}
	for (int i=N-1; i>=res[0]; --i) {
		if (res[i]>base-1) {
			res[i-1] += res[i] / base;
			res[i] %= base;
		}
	}
	while (!res[res[0]]) res[0]++;
}

void devide(int num, int tmp[]) {
    memset(res, 0, sizeof(res));
    res[0] = tmp[0];
    int t = tmp[0], tn;
    while (t<N-1) {
        if (tmp[t]<num) {
            tmp[t+1] += base * tmp[t];
        }
        else {
            res[t] = tmp[t] / num;
            tmp[t+1] += (tmp[t] % num) * base;
        }
        t++;
    }
    while (!res[res[0]]&&res[0]<N-1) res[0]++;
    res[t] = tmp[t] / num;
    rr = tmp[t] % num;
}


int big(int a[], int s[]) {
    if (a[0]>s[0]) return 0;
    else {
        if (a[0]<s[0]) return 2;
        else {
            for (int i=a[0]; i<N; ++i) {
                if (a[i]>s[i]) return 2;
                else {
                    if (a[i]<s[i]) return 0;
                }
            }
        }
    }
    return 1;
}

int calr(int a[], int b[]) {
    int tmp = 0, l = 0, r = 101, mid, result;
    while (l<=r) {
        mid = l + (r - l) / 2;
        memcpy(at, a, sizeof(at));
        plus(at, mid);
        mul1(at, mid);
        tmp = big(res, b);
        if (tmp==0||tmp==1) {
            result = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return result;
}

void square(int rest[]) {
	int tmp;
    memset(res, 0, sizeof(res));
    res[0] = 2 * rest[0] - N;
	for (int j=N-1; j>=rest[0]; j--) {
		for (int i=N-1; i>=rest[0]; i--) {
			res[i-N+1+j] += rest[i] * rest[j];
		}
	}
	tmp = N - 1;
	for (int tmp=N-1; tmp>=res[0]; --tmp) {
		if (res[tmp]>base-1) {
			res[tmp-1] += res[tmp] / base;
			res[tmp] %= base;
		}
	}
	while (!res[res[0]]) res[0]++;
}

void display(int a[]) {
    printf("%d", a[a[0]]);
    for (int i=a[0]+1; i<N;++i) printf("%02d", a[i]);
    printf("\n");
}

void calroot(int f[]) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(remain, 0, sizeof(remain));
    int t = N - 1, re = 0;
    if ((N-f[0])%2) f[0]--;
    a[0] = N - 1;
    b[0] = N - 2;
    b[N-2] = f[f[0]];
    b[N-1] = f[f[0]+1];
    if (!b[b[0]]) b[0]++;
    remain[0] = N - 1;
    for (int i=f[0]; i<N; i+=2) {
        re = calr(a, b);
        mul(remain, base);
        plus(remain, re); 
        plus(a, re);
        mul(a, re);
        minus(b, a);
        if (i<N-3) {
            mul(b, 10000);
            b[N-1] = f[i+3];
            b[N-2] = f[i+2];
        }
        if (b[0]>=N-2) b[0] = N - 2;
        mul1(remain, 200);
        memcpy(a, res, sizeof(a));  
    }
    while (!b[b[0]]&&b[0]<N-1) b[0]++;
    if (!f[f[0]]) f[0]++;
}

void out(int V, int k, int t) {
    printf("%d", res[res[0]]);
    for (int i=res[0]+1; i<N; ++i) printf("%02d", res[i]);
    printf(" * ");
    mul(res, k);
    if (t==1) plus1(res, remain);
    else minus(res, remain);
    printf("%d", res[res[0]]);
    for (int i=res[0]+1; i<N; ++i) printf("%02d", res[i]);   
    printf("\n");
}

void solve(int k) {
    int V = 0, t, tmpt = 0;
    memset(vt, 0, sizeof(vt));
    memset(kk, 0, sizeof(kk));
    multi(rest1, rest);
    memcpy(rest1, res, sizeof(rest));
    mul(rest1, 4);
    calroot(rest1);
    memcpy(tmp, remain, sizeof(tmp));
    square(tmp);
    memcpy(kk, rest1, sizeof(kk));
    minus(kk, res);
    calroot(kk);
    if (!(kk[0]==N-1&&kk[N-1]==0)) {
        plus(tmp, 1);
        square(tmp);
        minus(res, rest1);
        memcpy(kk, res, sizeof(kk));
        calroot(kk);
        
    }
    while (1) {
        if (b[0]==N-1&&b[N-1]==0) {
            memcpy(ten, tmp, sizeof(ten));
            minus(ten, remain);
            devide(2*k, ten);
            if (rr==0&&!(res[0]==N-1&&res[N-1]==1)) {
                out(V, k, 1);
                return;
            }
            memcpy(ten, tmp, sizeof(ten));
            plus1(ten, remain);
            devide(2*k, ten);
            if (rr==0&&!(res[0]==N-1&&res[N-1]==1)) {
                out(V, k, -1);
                return;
            }
        }
        plus(tmp, 1);
        square(tmp);
        minus(res, rest1);
        memcpy(kk, res, sizeof(kk));
        calroot(kk);
    } 
}

int main() {
    char in1[8];
    int k, len, tmp = N - 1;
    while (scanf("%s%s", in2, in1)!=EOF) {
        k = 0;
        tmp = N - 1;
        memset(rest, 0, sizeof(rest));
        memset(rest1, 0, sizeof(rest));
        memset(res, 0, sizeof(res));
        memset(remain, 0, sizeof(remain));
        len = strlen(in2);
        kk[0] = N - len;
        for (int i=N-1; i>=N-len; --i) kk[i] = in2[i-N+len]  - '0';
        for (int i=N-1; i>=kk[0]; i-=2) rest[tmp--] += kk[i] + kk[i-1] * 10;
        rest[0] = tmp + 1;
        memset(kk, 0, sizeof(kk));
        len = strlen(in1);
        for (int i=N-len; i<N; ++i) {
            kk[i] = in1[i-N+len]  - '0';
            k = k * 10 + kk[i]; 
        }
        tmp = N - 1;
        for (int i=N-1; i>=N-len; i-=2) rest1[tmp--] += kk[i] + kk[i-1] * 10;
        rest1[0] = tmp + 1; 
        solve(k);
        memset(kk, 0, sizeof(kk));
    }
}