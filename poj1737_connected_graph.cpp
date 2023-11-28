#include <stdio.h>
#include <iostream>
#include <cstring>

const int N = 401;
int tmp[N], f[51][N], two[N], res[N], rest[N];

void multi(int a, int tmp[]) {
    tmp[0] -= 3;
    for (int i=N-1; i>=tmp[0]; --i) tmp[i] *= a;
    for (int i=N-1; i>=tmp[0]-1; --i) {
        if (tmp[i]>9) {
            tmp[i-1] += tmp[i] / 10;
            tmp[i] %= 10;
        }
    }
    if (tmp[tmp[0]+1]) tmp[0]++;
}

void devide(int num) {
    memset(res, 0, sizeof(res));
    res[0] = tmp[0];
    int t = tmp[0], tn;
    while (t<N-1) {
        if (tmp[t]<num) {
            tmp[t+1] += 10 * tmp[t];
        }
        else {
            tn = tmp[t];
            res[t] = tn / num;
            tmp[t+1] += (tn % num) * 10;
        }
        t++;
    }
    while (!res[res[0]]&&res[0]<N-1) res[0]++;
    res[t] = tmp[t] / num;
    memcpy(tmp, res, sizeof(tmp));
}

void powt(int a) {
    for (int i=0; i<a; ++i) multi(2, two);
    two[N-1]--;
}

void C(int a, int b) {
    for (int i=b; i>b-a; --i) multi(i, tmp);
    for (int i=2; i<=a; ++i) devide(i);
}

void plus(int a, int b[]) {
    int t = std::min(f[a][0], b[0]);
    f[a][0] = t;
    for (int i=N-1; i>=t; --i) {
        f[a][i] += b[i];
        if (f[a][i]>9) {
            f[a][i-1] += f[a][i] / 10;
            f[a][i] %= 10; 
        }
    }
    if (f[a][f[a][0]-1]) f[a][0]--;
}

void mul(int a[], int b[]) {
    memset(res, 0, sizeof(res));
    res[0] = a[0] + b[0] - N;
	for (int j=N-1; j>=a[0]; j--) {
		for (int i=N-1; i>=b[0]; i--) {
			res[i-N+1+j] += b[i] * a[j];
		}
	}
	for (int i=N-1; i>=res[0]; --i) {
		if (res[i]>9) {
			res[i-1] += res[i] / 10;
			res[i] %= 10;
		}
	}
	while (!res[res[0]]) res[0]++;
    memcpy(rest, res, sizeof(rest));
}

void solve(int n) {
    for (int i=n-1; i>0; --i) {
        memset(two, 0, sizeof(two));
        memset(tmp, 0, sizeof(tmp));
        memset(res, 0, sizeof(res));
        memset(rest, 0, sizeof(rest));
        tmp[0] = N - 1;
        tmp[N-1] = 1;
        two[0] = N - 1;
        two[N-1] = 1;
        powt(i);
        C(i-1, n-2);
        mul(tmp, two);
        mul(f[n-i], rest);
        mul(f[i], rest);
        plus(n, rest);
    }
}

int main() {
    int max = 3, n;
    f[1][N-1] = 1;
    f[2][N-1] = 1;
    f[3][N-1] = 4;
    for (int i=1; i<=50; ++i) f[i][0] = N - 1;
    while (scanf("%d", &n)) {
        if (!n) break;
        if (n>max) for (int i=max+1; i<=n; ++i) {
            solve(i);
            max = n;
        }
        for (int i=f[n][0]; i<N; ++i) printf("%d", f[n][i]);
        printf("\n");
    }
}